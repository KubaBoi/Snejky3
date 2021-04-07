#include "Renderer.h"

using namespace std;

Renderer::Renderer(HWND *win) {
	window = win;

	render_state = new Render_State();

	render_state->width = 0;
	render_state->height = 0;

	int buffer_size = render_state->width * render_state->height * sizeof(unsigned int);

	if (render_state->memory) VirtualFree(render_state->memory, 0, MEM_RELEASE);
	render_state->memory = VirtualAlloc(0, buffer_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	render_state->bitmapinfo.bmiHeader.biSize = sizeof(render_state->bitmapinfo.bmiHeader);
	render_state->bitmapinfo.bmiHeader.biWidth = render_state->width;
	render_state->bitmapinfo.bmiHeader.biHeight = render_state->height;
	render_state->bitmapinfo.bmiHeader.biPlanes = 1;
	render_state->bitmapinfo.bmiHeader.biBitCount = 32;
	render_state->bitmapinfo.bmiHeader.biCompression = BI_RGB;

	hdc = GetDC(*win);
}

void Renderer::clearScreen(u32 color) {
	u32* pixel = (u32*)render_state->memory;
	for (int y = 0; y < render_state->height; y++) {
		for (int x = 0; x < render_state->width; x++) {
			*pixel++ = color;
		}
	}
}

void Renderer::drawRectInPixels(int x0, int y0, int x1, int y1, u32 color) {

	x0 = clamp(0, x0, render_state->width);
	y0 = clamp(0, y0, render_state->height);
	x1 = clamp(0, x1, render_state->width);
	y1 = clamp(0, y1, render_state->height);

	for (int y = y0; y < y1; y++) {
		u32* pixel = (u32*)render_state->memory + x0 + y*render_state->width;
		for (int x = x0; x < x1; x++) {
			*pixel++ = color;
		}
	}
}

void Renderer::drawRect(float x, float y, float half_size_x, float half_size_y, u32 color) {
	x *= render_state->height;
	half_size_x *= render_state->height;
	y *= render_state->height;
	half_size_y *= render_state->height;

	x += render_state->width / 2.f;
	y += render_state->height / 2.f;
	
	//change to pixels
	int x0 = x - half_size_x;
	int x1 = x + half_size_x;
	int y0 = y - half_size_y;
	int y1 = y + half_size_y;

	drawRectInPixels(x0, y0, x1, y1, color);
}

void Renderer::drawTriangle(Vector2* vec1, Vector2* vec2, Vector2* vec3, Color* color) {
	int x0 = int(vec1->x); //nejmensi x
	int y0 = int(vec1->y); //nejmensi y
	int x1 = int(vec1->x); //nejvetsi x
	int y1 = int(vec1->y); //nejvetsi y

	if (vec2->x < x0) x0 = int(vec2->x);
	if (vec2->x > x1) x1 = int(vec2->x);

	if (vec2->y < y0) y0 = int(vec2->y);
	if (vec2->y > y1) y1 = int(vec2->y);

	if (vec3->x < x0) x0 = int(vec3->x);
	if (vec3->x > x1) x1 = int(vec3->x);

	if (vec3->y < y0) y0 = int(vec3->y);
	if (vec3->y > y1) y1 = int(vec3->y);

	x0 = clamp(0, x0, render_state->width);
	y0 = clamp(0, y0, render_state->height);
	x1 = clamp(0, x1, render_state->width);
	y1 = clamp(0, y1, render_state->height);

	Vector2* a = vec1->newVector(vec2);
	Vector2* b = vec2->newVector(vec3);
	Vector2* c = vec3->newVector(vec1);

	double alpha1 = a->angle(c->reverseVector());
	double alpha2 = b->angle(a->reverseVector());
	double alpha3 = c->angle(b->reverseVector());

	for (int y = y0; y < y1; y++) {
		u32* pixel = (u32*)render_state->memory + x0 + y * render_state->width;
		for (int x = x0; x < x1; x++) {
			Vector2* point = new Vector2(x, y);

			Vector2* v1 = vec1->newVector(point);
			Vector2* v2 = vec2->newVector(point);
			Vector2* v3 = vec2->newVector(point);

			if (v1->angle(a) <= alpha1 &&
				v2->angle(b) <= alpha2 &&
				v3->angle(c) <= alpha3) {
				*pixel = convertColor(color);
			}

			pixel++;
		}
	}
}

int Renderer::clamp(int min, int val, int max) {
	if (val < min) return min;
	if (val > max) return max;
	return val;
}

u32 Renderer::convertColor(Color* color) {
	//0xff0000
	return ((color->r & 0xff) << 16) + ((color->g & 0xff) << 8) + (color->b & 0xff);
}

void Renderer::render() {
	StretchDIBits(hdc, 0, 0,
		render_state->width,
		render_state->height,
		0, 0,
		render_state->width,
		render_state->height,
		render_state->memory,
		&render_state->bitmapinfo, DIB_RGB_COLORS, SRCCOPY);
}
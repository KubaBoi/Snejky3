#include "Engine.h"

using namespace std;

Engine::Engine(HWND* win) {
	renderer = new Renderer(win);
	gameScreen = new GameScreen();

	running = true;
}

LRESULT Engine::input(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	LRESULT result = 0;

	gameScreen->input(&uMsg);

	switch (uMsg) {
	case WM_CLOSE:
	case WM_DESTROY: {
		running = false;
	} break;

	case WM_SIZE: {
		RECT rect;
		GetClientRect(hwnd, &rect);
		renderer->render_state->width = rect.right - rect.left;
		renderer->render_state->height = rect.bottom - rect.top;

		int buffer_size = renderer->render_state->width * renderer->render_state->height * sizeof(unsigned int);

		if (renderer->render_state->memory) VirtualFree(renderer->render_state->memory, 0, MEM_RELEASE);
		renderer->render_state->memory = VirtualAlloc(0, buffer_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

		renderer->render_state->bitmapinfo.bmiHeader.biSize = sizeof(renderer->render_state->bitmapinfo.bmiHeader);
		renderer->render_state->bitmapinfo.bmiHeader.biWidth = renderer->render_state->width;
		renderer->render_state->bitmapinfo.bmiHeader.biHeight = renderer->render_state->height;
		renderer->render_state->bitmapinfo.bmiHeader.biPlanes = 1;
		renderer->render_state->bitmapinfo.bmiHeader.biBitCount = 32;
		renderer->render_state->bitmapinfo.bmiHeader.biCompression = BI_RGB;

	} break;

	default: {
		result = DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	}

	return result;
}

void Engine::update() {
	gameScreen->update();
}

Color* r = new Color(0,0,0);
bool more = true;
void Engine::draw() {
	//renderer->clearScreen(0xff5500);
	renderer->clearScreen(renderer->convertColor(r));
	//renderer->drawRect(0, 0, 0.2, 0.2, 0xff0000);
	gameScreen->draw(renderer);

	if (r->r >= 255) more = false;
	if (r->r <= 0) more = true;

	if (more) {
		r->r++;
		r->g++;
		r->b++;
	}
	else {
		r->r--;
		r->g--;
		r->b--;
	}

	/*renderer->drawTriangle(new Vector2(0, 0),
		new Vector2(500, 200),
		new Vector2(500, 100),
		r);*/

	renderer->render();
}

void Engine::addGameObject(Object* object) {
	gameScreen->addGameObject(object);
}

void Engine::removeGameObject(Object* object) {
	gameScreen->removeGameObject(object);
}


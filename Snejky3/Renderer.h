#pragma once

#include <windows.h>
#include "utils.cpp"
#include "Vector2.h"
#include "Color.h"

#include <iostream>
#include <sstream>

struct Render_State {
	int height, width;
	void* memory;

	BITMAPINFO bitmapinfo;
};

#ifndef RENDERER_H
#define RENDERER_H

class Renderer
{
private:
	HWND *window;
	HDC hdc;

public:
	Render_State *render_state;

	Renderer(HWND *win);

	void clearScreen(u32 color);
	void drawRectInPixels(int x0, int y0, int x1, int y1, u32 color);
	void drawRect(float x, float y, float half_size_x, float half_size_y, u32 color);

	void drawTriangle(Vector2* vec1, Vector2* vec2, Vector2* vec3, Color* color);

	int clamp(int min, int val, int max);
	u32 convertColor(Color* color);

	void render();
};

#endif



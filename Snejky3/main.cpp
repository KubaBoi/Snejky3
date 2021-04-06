#include <windows.h>
#include "utils.cpp"

#include "Engine.h"

Engine* engine;

LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (engine == nullptr) {
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return engine->input(hwnd, uMsg, wParam, lParam);
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	//vytvori window class
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = L"Sample Window Class";
	window_class.lpfnWndProc = window_callback;

	//registruje class
	RegisterClass(&window_class);

	//vytvori window
	HWND window = CreateWindow(window_class.lpszClassName,
		L"My First Game",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		1280, 720,
		0, 0,
		hInstance,
		0);

	engine = new Engine(&window);

	while (engine->running) {
		// INPUT
		MSG message;
		while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		// SIMULATE
		engine->update();
		//clear_screen(0xff5500);
		//draw_rect(0, 0, 0.2, 0.2, 0xff0000);


		// RENDER
		engine->draw();
	}

	return 0;
}
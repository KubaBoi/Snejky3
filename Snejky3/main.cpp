#include <windows.h>
#include "utils.cpp"

#include "Engine.h"

#include "GameObject.h"

Engine* engine;

GameObject* gmObj;
void init() {
	gmObj = new GameObject(NULL);
	engine->addGameObject(gmObj);
}

void update() {
}

LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (wParam == 119) {
		engine->removeGameObject(gmObj);
	}
	
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

	init();

	while (engine->running) {
		// INPUT
		MSG message;
		while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		// SIMULATE
		update();
		engine->update();


		// RENDER
		engine->draw();
	}

	return 0;
}
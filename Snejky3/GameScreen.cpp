#include "GameScreen.h"

GameScreen::GameScreen() {}

void GameScreen::update() {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->update();
	}
}

void GameScreen::input(UINT* uMsg) {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->input(uMsg);
	}
}

void GameScreen::draw(Renderer* renderer) {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->draw(renderer);
	}
}

void GameScreen::addGameObject(Object* object) {
	objects.push_back(object);
}

void GameScreen::removeGameObject(Object* object) {
	objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
}
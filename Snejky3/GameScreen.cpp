#include "GameScreen.h"

GameScreen::GameScreen() {}

void GameScreen::update() {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->update();
	}
}

void GameScreen::draw(Renderer* renderer) {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->draw(renderer);
	}
}

void GameScreen::addGameObject(GameObject* object) {
	objects.push_back(object);
}

void GameScreen::removeGameObject(GameObject* object) {
	objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
}
#include "GameObject.h"

GameObject::GameObject(Vector3* pPosition) {
	position = pPosition;
}

void GameObject::update() {

}

void GameObject::draw(Renderer* renderer) {
	//renderer->drawRect(0, 0, 0.2, 0.2, 0xff0000);
}

void GameObject::input(UINT* uMsg) {

}
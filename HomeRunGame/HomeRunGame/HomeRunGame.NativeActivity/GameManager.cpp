#include "GameManager.hpp"

class Power;

GameManager::GameManager(Scene *scene) :
	Game(scene),
	mScene(makeScene<Power>()) {

}

GameManager::~GameManager() {
	if (mScene != nullptr) delete mScene;
}

Scene *GameManager::Update() {
	auto p = mScene->Update();
	if (p != mScene) {
		delete mScene;
		auto p2 = dynamic_cast<Game*>(p);
		if (p2 != nullptr) {
			mScene = p2;
			return this;
		}
		else {
			mScene = nullptr;
			return p;
		}
	}
	return this;
}

void GameManager::Draw() const {
	mScene->Draw();
}

template<>
Scene *Scene::makeScene<GameManager>() {
	return new GameManager(this);
}
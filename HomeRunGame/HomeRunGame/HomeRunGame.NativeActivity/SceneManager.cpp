#include "SceneManager.hpp"
#include "CommonData.hpp"

class Title;

SceneManager::SceneManager() :
	Scene(new CommonData()),
	mScene(makeScene<Title>()) {
	
}

SceneManager::~SceneManager() {
	if(mScene != nullptr) delete mScene;
	delete commonData;
}

Scene *SceneManager::Update() {
	commonData->TouchUpdate();
	Scene *p = mScene->Update();
	if (p != mScene) {
		delete mScene;
		mScene = p;
	}
	return this;
}

void SceneManager::Draw() const {
	mScene->Draw();
}
#include "Title.hpp"
#include "CommonData.hpp"

class GameManager;
class Ranking;

Title::Title(CommonData *const commonData) :
	Scene(commonData) 
{
	
}

Title::~Title() {

}

Scene *Title::Update() {
	if (commonData->touch->isTouch()) {
		commonData->nextSound->Play();
		if (InRankButtonRange()) {
			return makeScene<Ranking>();
		}
		else {
			return makeScene<GameManager>();
		}
	}
	return this;
}

void Title::Draw() const {
	DrawBackGround();
	DrawRankButton();
}

bool Title::InRankButtonRange() const {
	Vec2i touchPos = commonData->touch->GetPos();
	Vec2i butPos   = commonData->rankButton->GetPos();
	Vec2i butSize  = commonData->rankButton->GetSize();

	if (butPos.x <= touchPos.x && touchPos.x <= butPos.x + butSize.x) {
		if (butPos.y <= touchPos.y && touchPos.y <= butPos.y + butSize.y) {
			return true;
		}
	}
	
	return false;
}

void Title::DrawBackGround() const {
	commonData->titleBack->Draw();
}

void Title::DrawRankButton() const {
	commonData->rankButton->SetPos(Vec2i(450, 1150));
	commonData->rankButton->Draw();
}

template<>
Scene *Scene::makeScene<Title>() {
	return new Title(commonData);
}
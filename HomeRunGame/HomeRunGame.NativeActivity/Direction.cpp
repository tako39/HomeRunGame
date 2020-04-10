#include "Direction.hpp"
#include "Gauge.hpp"
#include "CommonData.hpp"

class Result;

Direction::Direction(Game* game) :
	Game(*game),
	gauge(new Gauge(Gauge::Param(0.f, 0.f, 90.f, 4.6f))),
	touchCount(0) 
{
	
}

Direction::~Direction() {
	delete gauge;
}

Scene *Direction::Update() {
	if (TouchCount()) {
		if (touchCount == 1) {
			commonData->decideSound->Play();
			gauge->Stop();
			SaveValue();
		}
		else if (touchCount == 2) {
			commonData->nextSound->Play();
			return Scene::makeScene<Result>();
		}
	}
	gauge->Update();
	return this;
}

void Direction::Draw() const {
	DrawBackGround();
	DrawBatting();
	DrawGauge();
}

bool Direction::TouchCount() {
	if (commonData->touch->isTouch()) {
		touchCount++;
		return true;
	}
	return false;
}

void Direction::DrawBackGround() const {
	commonData->backGround->Draw();
}

void Direction::DrawGauge() const {
	commonData->direct_Arrow->SetPos(Vec2i(310, 715));
	commonData->direct_Arrow->DrawRotate(Vec2i(0, 25), CommonData::PI / 180.0f * -gauge->GetValue(), true);
}

void Direction::DrawBatting() const {
	commonData->batting1->SetPos(Vec2i(0, 590));
	commonData->batting1->Draw();
}

void Direction::SaveValue() const {
	commonData->directValue = gauge->GetValue();
}

template<>
Scene *Game::makeScene<Direction>() {
	return new Direction(this);
}
#include "Power.hpp"
#include "Gauge.hpp"
#include "CommonData.hpp"

class Direction;

Power::Power(Game *game) :
	Game(*game),
	gauge(new Gauge(Gauge::Param(0.f, 0.f, 100.f, 5.6f))),
	touchCount(0) 
{
	
}

Power::~Power() {
	delete gauge;
}

Scene *Power::Update() {
	if (TouchCount()) {
		if (touchCount == 1) {
			commonData->decideSound->Play();
			gauge->Stop();
			SaveValue();
		}
		else if (touchCount == 2) {
			commonData->nextSound->Play();
			return makeScene<Direction>();
		}
	}
	gauge->Update();
	return this;
}

void Power::Draw() const {
	DrawBackGround();
	DrawGauge();
	DrawBatting();
}

bool Power::TouchCount() {
	if (commonData->touch->isTouch()) {
		touchCount++;
		return true;
	}
	return false;
}

void Power::DrawBackGround() const {
	commonData->backGround->Draw();
}

void Power::DrawGauge() const {
	commonData->power_Back->SetPos(Vec2i(260, 450));
	commonData->power_Back->Draw();

	commonData->power_Bar->SetPos(Vec2i(260, 450));
	commonData->power_Bar->DrawExtend(Vec2f(gauge->GetRatio(), 1.0f));

	commonData->power_Frame->SetPos(Vec2i(260, 450));	
	commonData->power_Frame->Draw(true);
}

void Power::DrawBatting() const {
	commonData->batting0->SetPos(Vec2i(0, 590));
	commonData->batting0->Draw();
}

void Power::SaveValue() const {
	commonData->powerValue = gauge->GetValue();
}

template<>
Scene *Game::makeScene<Power>() {
	return new Power(this);
}
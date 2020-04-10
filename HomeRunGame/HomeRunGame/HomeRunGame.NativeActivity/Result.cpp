#include "Result.hpp"
#include "CommonData.hpp"
#include "HttpRequest.hpp"
#include "DxLib.h"
#include <math.h>

class Title;

Result::Result(Scene *scene) :
	Scene(*scene),
	isConnect(false),
	scoreStr(""),
	rankStr("")
{
	Calculate();
	StringSave();
}

Result::~Result() {
	
}

Scene *Result::Update() {
	if (commonData->touch->isTouch()) {
		commonData->nextSound->Play();
		return makeScene<Title>();
	}

	return this;
}

void Result::Draw() const {
	DrawBackGround();
	DrawResult();
}

void Result::DrawBackGround() const {
	commonData->resultBack->Draw();
}

void Result::DrawResult() const {
	commonData->nikoFont->DrawCenter(Vec2i(360, 540), GetColor(0, 0, 0), scoreStr.c_str());

	if(isConnect){
		commonData->nikoFont->DrawCenter(Vec2i(360, 640), GetColor(0, 0, 0), rankStr.c_str());
	}
	else {
		commonData->networkError->SetPos(Vec2i(160, 700));
		commonData->networkError->Draw(true);
	}
}

void Result::Calculate() {
	float velocity = commonData->powerValue * CommonData::COEFFICIENT;
	float shita = CommonData::PI / 180.0f * commonData->directValue;
	float score = pow(velocity, 2.0) * 2.0 * sin(shita) * cos(shita) / CommonData::GRAVITY;

	commonData->score = (int)floor(score * 1000.f);
}

void Result::StringSave() {
	char cScore[10];
	float fScore = commonData->score / 1000.f;
	snprintf(cScore, sizeof(cScore), "%3.3f", fScore);
	scoreStr = "スコア：  " + (std::string)cScore + "  ｍ";

	HttpRequest *httpRequest 
		= new HttpRequest(HttpRequest::Type::Result, commonData->score);
	if (httpRequest->IsConnect()) {
		isConnect = true;
		std::string total = httpRequest->GetNo(0);
		std::string rank  = httpRequest->GetRank(0);
		rankStr = "順位：  " + rank + "  /  " + total + "  位";
	}
	delete httpRequest;
}

template<>
Scene *Scene::makeScene<Result>() {
	return new Result(this);
}
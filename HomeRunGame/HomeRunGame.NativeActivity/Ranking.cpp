#include "Ranking.h"
#include "CommonData.hpp"
#include "HttpRequest.hpp"
#include "DxLib.h"

class Title;

Ranking::Ranking(Scene* scene) :
	Scene(*scene),
	isConnect(false),
	interval(80),
	rankNum(0)
{
	GetRanking();
}

Ranking::~Ranking() {

}

Scene *Ranking::Update() {
	if (commonData->touch->isTouch()) {
		commonData->nextSound->Play();
		return makeScene<Title>();
	}

	return this;
}

void Ranking::Draw() const {
	DrawBackGround();
	DrawRanking();
}

void Ranking::GetRanking() {
	HttpRequest *httpRequest
		= new HttpRequest(HttpRequest::Type::Ranking);
	if (httpRequest->IsConnect()) {
		isConnect = true;

		rankNum = httpRequest->GetNum();
		rankingStr = new std::string[rankNum]();
		
		for (int i = 0; i < rankNum; i++) {
			std::string rank  = httpRequest->GetRank(i);
			std::string score = httpRequest->GetScore(i);
			score = score.substr(0, 3) + "." + score.substr(3, 3);
			
			rankingStr[i] = (rank + " 位 : " + score + " ｍ");
		}
	}
	delete httpRequest;
}

void Ranking::DrawBackGround() const {
	commonData->rankingBack->Draw();
}

void Ranking::DrawRanking() const {
	if (isConnect) {
		for (int i = 0; i < rankNum; i++) {
			commonData->nikoFont->DrawCenter(Vec2i(360, 380 + interval * i), GetColor(0, 0, 0), rankingStr[i].c_str());
		}
	}
	else {
		commonData->networkError->SetPos(Vec2i(160, 590));
		commonData->networkError->Draw(true);
	}
}

template<>
Scene *Scene::makeScene<Ranking>() {
	return new Ranking(this);
}
#include "Fps.hpp"
#include "DxLib.h"

Fps::Fps() :
	mStartTime(0),
	mCount(0),
	mFps(0),
	N(60),
	FPS(60) {

}

Fps::~Fps() {

}

bool Fps::Update() {
	if (mCount == 0) {
		mStartTime = GetNowCount();
	}
	if (mCount == N) {
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;
	}
	mCount++;
	return true;
}

void Fps::Wait() {
	int tookTime = GetNowCount() - mStartTime;		//かかった時間
	int waitTime = mCount * 1000 / FPS - tookTime;	//待つべき時間
	if (waitTime > 0) {
		WaitTimer(waitTime);	//待機
	}
}
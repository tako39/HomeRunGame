#include "Timer.hpp"
#include "DxLib.h"

Timer::Timer(int timeLimit_) :
	timeLimit(timeLimit_) {
	startTime = GetNowCount();
}

Timer::~Timer() {

}

bool Timer::IsTimeUp() {
	if (GetNowCount() - startTime > timeLimit) {
		return true;
	}
	return false;
}
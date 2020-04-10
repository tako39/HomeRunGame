#include "Touch.h"
#include "DxLib.h"

Touch::Touch() :
	state(State::UP),
	touchNum(0),
	touchX(0),
	touchY(0) {
	
}

Touch::~Touch() {

}

void Touch::Update() {
	touchNum = GetTouchInputNum();
	if (touchNum > 0) {
		GetTouchInput(0, &touchX, &touchY);
		if (state == State::UP) {
			state = State::DOWN;
		}
		else if (state == State::DOWN) {
			state = State::HOLD;
		}
	}
	else {
		if (state != State::UP) {
			state = State::UP;
		}
	}
}

bool Touch::isTouch() const {
	return state == State::DOWN;
}

Vec2i Touch::GetPos() const {
	return Vec2i(touchX, touchY);
}
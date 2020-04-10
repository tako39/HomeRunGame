#include "Gauge.hpp"
#include "DxLib.h"

Gauge::Gauge(Gauge::Param param) :
	value(param.iniV),
	minValue(param.minV),
	maxValue(param.maxV),
	speed(param.speed) {
	Run();
}

Gauge::~Gauge() {
	
}

void Gauge::Update() {
	if(isRunning) ChangeValue();
}

float Gauge::GetValue() const {
	return value;
}

float Gauge::GetRatio() const {
	return (float)value / (float)(maxValue - minValue);
}

bool Gauge::InRange() const {
	return (minValue <= value) && (value <= maxValue);
}

void Gauge::Run() {
	isRunning = true;
}

void Gauge::Stop() {
	isRunning = false;
}

void Gauge::ChangeValue() {
	value += speed;
	
	if (value < minValue) {
		value = minValue;
	}
	else if (value > maxValue) {
		value = maxValue;
	}

	if (value == minValue || 
		value == maxValue) {
		InvSpeed();
	}
}

void Gauge::InvSpeed() {
	speed *= -1.0f;
}
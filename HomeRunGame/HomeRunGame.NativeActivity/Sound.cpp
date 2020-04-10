#include "Sound.hpp"
#include "DxLib.h"

Sound::Sound(const char* addr) :
	address(addr) {
	soundHandle = LoadSoundMem(address);
}

Sound::~Sound() {
	DeleteSoundMem(soundHandle);
}

void Sound::Play() const {
	PlaySoundMem(soundHandle, DX_PLAYTYPE_NORMAL);
}
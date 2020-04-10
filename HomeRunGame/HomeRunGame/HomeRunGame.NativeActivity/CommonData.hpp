#ifndef ___Class_CommonData
#define ___Class_CommonData

#include "Touch.h"
#include "Vec2.hpp"
#include "Texture.hpp"
#include "Font.hpp"
#include "Sound.hpp"

class CommonData {
public:
	CommonData();
	~CommonData();

	void TouchUpdate();

public:
	static const Vec2i SCREEN;
	static const float PI;
	static const float GRAVITY;
	static const float COEFFICIENT;

	int powerValue;
	int directValue;
	int score;

	Touch *const touch;

	//Common
	Texture *const backGround;
	Texture *const networkError;
	//Title
	Texture *const titleBack;
	Texture *const rankButton;
	//Ranking
	Texture *const rankingBack;
	//Game
	Texture *const power_Back;
	Texture *const power_Bar;
	Texture *const power_Frame;
	Texture *const direct_Arrow;
	Texture *const batting0;
	Texture *const batting1;
	//Result
	Texture *const resultBack;

	Font *const nikoFont;

	Sound *const nextSound;
	Sound *const decideSound;
};

#endif // !___Class_CommonData
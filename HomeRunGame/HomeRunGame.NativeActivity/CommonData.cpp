#include "CommonData.hpp"

const Vec2i CommonData::SCREEN = Vec2i(720, 1280);
const float CommonData::PI = 3.14159f;
const float CommonData::GRAVITY  = 9.80665f;
const float CommonData::COEFFICIENT = 0.4f;

CommonData::CommonData() :
	powerValue(0),
	directValue(0),
	score(0),
	touch		(new Touch()),
	backGround	(new Texture(Vec2i(720, 1280), "Image/Common/BackGround.png")),
	networkError(new Texture(Vec2i(400, 100) , "Image/Common/NetworkError.png")),
	titleBack	(new Texture(Vec2i(720, 1280), "Image/Title/TitleBack.png")),
	rankButton	(new Texture(Vec2i(250, 80)	 , "Image/Title/RankButton.png")),
	rankingBack	(new Texture(Vec2i(720, 1280), "Image/Ranking/RankingBack.png")),
	power_Back	(new Texture(Vec2i(400, 80)	 , "Image/Game/Power_Back.png")),
	power_Bar	(new Texture(Vec2i(400, 80)	 , "Image/Game/Power_Bar.png")),
	power_Frame	(new Texture(Vec2i(400, 80)  , "Image/Game/Power_Frame.png")),
	direct_Arrow(new Texture(Vec2i(400, 50)  , "Image/Game/Direct_Arrow.png")),
	batting0	(new Texture(Vec2i(400, 400) , "Image/Game/Batting0.JPG")),
	batting1	(new Texture(Vec2i(400, 400) , "Image/Game/Batting1.JPG")),
	resultBack  (new Texture(Vec2i(720, 1280), "Image/Result/ResultBack.png")),
	nikoFont	(new Font (50, 8, "Font/nicomoji-plus_1.11.ttf")),
	nextSound	(new Sound("Sound/NextSound.wav")),
	decideSound (new Sound("Sound/DecideSound.wav"))
{
	
}

CommonData::~CommonData() {
	delete touch;
	delete backGround;
	delete networkError;
	delete titleBack;
	delete rankButton;
	delete rankingBack;
	delete power_Back;
	delete power_Bar;
	delete power_Frame;
	delete direct_Arrow;
	delete batting0;
	delete batting1;
	delete resultBack;
	delete nikoFont;
	delete nextSound;
	delete decideSound;
}

void CommonData::TouchUpdate() {
	touch->Update();
}
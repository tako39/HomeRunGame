#ifndef ___Class_Power
#define ___Class_Power

#include "Game.hpp"

class Gauge;

class Power : public Game {
public:
	Power(Game *game);
	virtual ~Power();

	Scene *Update() override;
	void Draw() const override;

private:
	bool TouchCount();
	void DrawBackGround() const;
	void DrawGauge() const;
	void DrawBatting() const;
	void SaveValue() const;

private:
	Gauge *const gauge;
	int touchCount;
};

template<>
Scene *Game::makeScene<Power>();

#endif // !___Class_Power
#ifndef ___Class_Direction
#define ___Class_Direction

#include "Game.hpp"

class Gauge;

class Direction : public Game {
public:
	Direction(Game *game);
	virtual ~Direction();

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
Scene *Game::makeScene<Direction>();

#endif // !___Class_Direction
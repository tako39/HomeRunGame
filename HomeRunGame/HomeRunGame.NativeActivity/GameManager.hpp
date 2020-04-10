#ifndef ___Class_GameManager
#define ___Class_GameManager

#include "Game.hpp"

class GameManager : public Game {
public:
	GameManager(Scene *scene);
	~GameManager();

private:
	Scene *mScene;

public:
	virtual Scene *Update() override;
	virtual void Draw() const override;
};

#endif // !___Class_GameManager
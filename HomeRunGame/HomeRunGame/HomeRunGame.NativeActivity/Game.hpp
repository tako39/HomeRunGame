#ifndef ___Class_Game
#define ___Class_Game

#include "Scene.hpp"

class Game : public Scene {
protected:
	Game(Scene *scene) :
		Scene(*scene)
	{}
	Game(const Game &) = default;

public:
	virtual ~Game() = default;
	virtual Scene *Update() override = 0;
	virtual void Draw() const override = 0;

public:
	template<typename T>
	Scene *makeScene();
};

#endif // !___Class_Game
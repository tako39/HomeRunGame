#ifndef ___Class_SceneManager
#define ___Class_SceneManager

#include "Scene.hpp"

class SceneManager : public Scene {
public:
	SceneManager();
	~SceneManager();

private:
	Scene *mScene;

public:
	Scene *Update() override;
	void Draw() const override;
};

#endif // !___Class_SceneManager
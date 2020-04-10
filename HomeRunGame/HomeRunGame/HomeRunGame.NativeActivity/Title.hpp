#ifndef ___Class_Title
#define ___Class_Title

#include "Scene.hpp"

class Title : public Scene {
public:
	Title(CommonData *const commonData);
	virtual ~Title();
	virtual Scene *Update() override;
	virtual void Draw() const override;

private:
	bool InRankButtonRange() const;
	void DrawBackGround() const;
	void DrawRankButton() const;
};

template<>
Scene *Scene::makeScene<Title>();

#endif // !___Class_Title
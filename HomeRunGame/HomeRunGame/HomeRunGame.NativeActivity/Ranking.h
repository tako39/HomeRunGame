#ifndef ___Class_Ranking
#define ___Class_Ranking

#include "Scene.hpp"
#include <string>

class Ranking : public Scene {
public:
	Ranking(Scene* scene);
	virtual ~Ranking();
	virtual Scene *Update() override;
	virtual void Draw() const override;

private:
	void GetRanking();
	void DrawBackGround() const;
	void DrawRanking() const;

private:
	bool isConnect;
	const int interval;
	std::string *rankingStr;
	int rankNum;
};

template<>
Scene *Scene::makeScene<Ranking>();

#endif // !___Class_Ranking
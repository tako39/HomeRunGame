#ifndef ___Class_Result
#define ___Class_Result

#include "Scene.hpp"
#include <string>

//class HttpRequest;

class Result : public Scene {
public:
	Result(Scene* scene);
	virtual ~Result();
	virtual Scene *Update() override;
	virtual void Draw() const override;

private:
	void Calculate();
	void StringSave();
	void DrawBackGround() const;
	void DrawResult() const;

private:
	//HttpRequest *httpRequest;
	bool isConnect;
	std::string scoreStr;
	std::string rankStr;
};

template<>
Scene *Scene::makeScene<Result>();

#endif // !___Class_Result
#ifndef ___Class_Scene
#define ___Class_Scene

class CommonData;

class Scene {
protected:
	Scene(CommonData *const commonData) :
		commonData(commonData) 
	{}
	Scene(const Scene &) = default;

public:
	virtual ~Scene() = default;

protected:
	CommonData *const commonData;

public:
	virtual Scene *Update() = 0;
	virtual void Draw() const = 0;

protected:
	template<typename T>
	Scene *makeScene();
};

#endif // !___Class_Scene
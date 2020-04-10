#ifndef ___Class_Touch
#define ___Class_Touch

#include "Vec2.hpp"

class Touch {
public:
	Touch();
	~Touch();
	void Update();
	bool isTouch() const;
	Vec2i GetPos() const;

public:
	enum State {
		UP,
		DOWN,
		HOLD
	};
	State state;
	
private:
	int touchNum;
	int touchX, touchY;
};

#endif // !___Class_Touch
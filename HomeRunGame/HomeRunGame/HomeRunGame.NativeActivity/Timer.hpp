#ifndef ___Class_Timer
#define ___Class_Timer

class Timer {
public:
	Timer(int timeLimit_);
	~Timer();
	bool IsTimeUp();

private:
	int startTime;
	int timeLimit;
};

#endif // !___Class_Timer
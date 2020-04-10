#ifndef ___Class_Fps
#define ___Class_Fps

class Fps {
public:
	Fps();
	~Fps();
	bool Update();
	void Wait();

private:
	int mStartTime;     //測定開始時刻
	int mCount;         //カウンタ
	float mFps;         //fps
	const int N;		//平均を取るサンプル数
	const int FPS;		//設定したFPS
};

#endif // !___Class_Fps
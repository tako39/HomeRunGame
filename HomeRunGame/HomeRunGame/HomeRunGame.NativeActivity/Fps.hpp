#ifndef ___Class_Fps
#define ___Class_Fps

class Fps {
public:
	Fps();
	~Fps();
	bool Update();
	void Wait();

private:
	int mStartTime;     //����J�n����
	int mCount;         //�J�E���^
	float mFps;         //fps
	const int N;		//���ς����T���v����
	const int FPS;		//�ݒ肵��FPS
};

#endif // !___Class_Fps
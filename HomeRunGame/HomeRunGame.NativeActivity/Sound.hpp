#ifndef ___Class_Sound
#define ___Class_Sound

class Sound {
public:
	Sound(const char* addr);
	~Sound();
	void Play() const;

private:
	const char* address;
	int soundHandle;
};

#endif // !___Class_Sound
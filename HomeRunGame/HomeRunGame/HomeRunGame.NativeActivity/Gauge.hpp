#ifndef ___Class_Gauge
#define ___Class_Gauge

class Gauge {
public:
	class Param {
	public:
		Param(float iniV_, unsigned int minV_, unsigned int maxV_, float speed_) :
			iniV(iniV_), minV(minV_), maxV(maxV_), speed(speed_) {}

		float iniV;
		float minV;
		float maxV;
		float speed;
	};

	Gauge(Param param);
	~Gauge();

	void Update();

	float GetValue() const;
	float GetRatio() const;
	bool InRange() const;

	void Run();
	void Stop();
	bool isRunning;

private:
	void ChangeValue();
	void InvSpeed();

private:
	float value;
	const unsigned int minValue, maxValue;
	float speed;
};

#endif // !___Class_Gauge
#ifndef ___Class_Vec2
#define ___Class_Vec2

template <class T>
class Vec2 {
public:
	T x, y;

	Vec2() :x(0), y(0) {}
	Vec2(T x, T y) : x(x), y(y) {}
	Vec2(const Vec2& v) : x(v.x), y(v.y) {}

	Vec2& operator=(const Vec2& v) {
		x = v.x;
		y = v.y;
		return *this;
	}

	Vec2 operator+(Vec2& v) {
		return Vec2(x + v.x, y + v.y);
	}
	Vec2 operator-(Vec2& v) {
		return Vec2(x - v.x, y - v.y);
	}

	Vec2& operator+=(Vec2& v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	Vec2& operator-=(Vec2& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Vec2 operator+(T s) {
		return Vec2(x + s, y + s);
	}
	Vec2 operator-(T s) {
		return Vec2(x - s, y - s);
	}
	Vec2 operator*(T s) {
		return Vec2(x * s, y * s);
	}
	Vec2 operator/(T s) {
		return Vec2(x / s, y / s);
	}


	Vec2& operator+=(T s) {
		x += s;
		y += s;
		return *this;
	}
	Vec2& operator-=(T s) {
		x -= s;
		y -= s;
		return *this;
	}
	Vec2& operator*=(T s) {
		x *= s;
		y *= s;
		return *this;
	}
	Vec2& operator/=(T s) {
		x /= s;
		y /= s;
		return *this;
	}
};

typedef Vec2<int> Vec2i;
typedef Vec2<float> Vec2f;

#endif // !___Class_Vec2
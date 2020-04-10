#ifndef ___Class_Texture
#define ___Class_Texture

#include "Vec2.hpp"

class Texture {
public:
	Texture(Vec2i size_, const char* addr);
	~Texture();
	void SetPos(Vec2i pos_);
	Vec2i GetPos()  const;
	Vec2i GetSize() const;
	void Draw(bool isTrans = false) const;
	void DrawExtend(Vec2f aspect,bool isTrans = false) const;
	void DrawRotate(Vec2i center, float angle, bool isTrans = false) const;

private:
	int texture;
	Vec2i pos;
	Vec2i size;
	const char* address;
};

#endif // !___Class_Texture
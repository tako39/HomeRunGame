#ifndef ___Class_Font
#define ___Class_Font

#include "Vec2.hpp"

class Font {
public:
	Font(int size, int thick, const char* addr);
	~Font();
	int GetFontHandle() const;
	void DrawString(Vec2i pos, unsigned int color, const char* str) const;
	void DrawCenter(Vec2i pos, unsigned int color, const char* str) const;

private:
	int fontHandle;
};

#endif // !___Class_Font
#include "Font.hpp"
#include "DxLib.h"
#include <string>

Font::Font(int size, int thick, const char* addr) {
	fontHandle = CreateFontToHandle(addr, size, thick);
}

Font::~Font() {
	DeleteFontToHandle(fontHandle);
}

int Font::GetFontHandle() const {
	return fontHandle;
}

void Font::DrawString(Vec2i pos, unsigned int color, const char* str) const {
	DrawStringToHandle(pos.x, pos.y, str, color, fontHandle);
}

void Font::DrawCenter(Vec2i pos, unsigned int color, const char* str) const {
	int strWidth = GetDrawStringWidthToHandle(str, (int)strlen(str), fontHandle);
	int strHeight = GetFontSizeToHandle(fontHandle);
	Vec2i cPos = Vec2i(pos.x - strWidth / 2, pos.y - strHeight / 2);
	DrawStringToHandle(cPos.x, cPos.y, str, color, fontHandle);
}
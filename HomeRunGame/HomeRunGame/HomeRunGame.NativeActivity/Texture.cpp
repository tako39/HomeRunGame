#include "Texture.hpp"
#include "DxLib.h"

Texture::Texture(Vec2i size_, const char* addr) :
	size(size_),
	address(addr) {
	SetPos(Vec2i(0, 0));
	texture = LoadGraph(address);
}

Texture::~Texture() {
	DeleteGraph(texture);
}

void Texture::SetPos(Vec2i pos_) {
	pos = pos_;
}

Vec2i Texture::GetPos() const {
	return pos;
}

Vec2i Texture::GetSize() const {
	return size;
}

void Texture::Draw(bool isTrans /*= false*/) const {
	DrawGraph(pos.x, pos.y, texture, isTrans);
}

void Texture::DrawExtend(Vec2f aspect, bool isTrans /*= false*/) const {
	DrawExtendGraph(pos.x, pos.y,
		pos.x + size.x * aspect.x, pos.y + size.y * aspect.y, texture, isTrans);
}

void Texture::DrawRotate(Vec2i center, float angle, bool isTrans /*= false*/) const {
	DrawRotaGraph2(pos.x, pos.y, center.x, center.y, 1.0, angle, texture, isTrans);
}
#include "Sprite.h"
#include "BoxTicker.h"


Sprite::Sprite(const char* a_imgDir, Vec2 a_imageSize)
	: BASESIZE(a_imageSize)
{
	dir = a_imgDir;
	id = CreateSprite(dir, BASESIZE.x, BASESIZE.y, true);
}

void Sprite::Draw()
{
	DrawSprite(id);
}

void Sprite::SetMatrix(float* a_matrix)
{
	SetSpriteMatrix(id, a_matrix);
}

Sprite::~Sprite(void)
{
	DestroySprite(id);
}


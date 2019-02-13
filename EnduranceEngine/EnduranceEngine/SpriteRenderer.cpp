#include "stdafx.h"
#include "SpriteRenderer.h"

void SpriteRenderer::LoadSprite(String str)
{
	texture.loadFromFile(str);
	image.setTexture(texture);
}

#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

#include <string>

using namespace sf;

class SpriteRenderer {
public:
	SpriteRenderer() {};
	~SpriteRenderer() {};
	void LoadSprite(String str);
	void PlayAnim() {};

	Texture texture;
	Sprite image;
};
#pragma once
#include "PlayerInput.h"
#include "AI.h"
#include <SFML\Graphics.hpp>

class Animation
{
public:
	Animation(const sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	void Update(int row, float deltaTime);

public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchtime;
};
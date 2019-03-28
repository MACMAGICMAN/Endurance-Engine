#pragma once
#include "SFML/Graphics.hpp"

class Collision
{
public:
	Collision();
	void HandleCollisions(sf::Sprite& objectA, sf::Sprite& objectB);
};
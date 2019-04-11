#pragma once
#include "SFML/Graphics.hpp"
class Collision
{
public:
	Collision();
	void CollideWithPlayer(sf::Sprite& CollideObjectOne, sf::Sprite& CollideObjectTwo, bool damagable);
	int ishit = 1;
};


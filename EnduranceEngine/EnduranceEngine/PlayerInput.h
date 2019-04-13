#pragma once
#include "Actor.h"
#include "SFML/Graphics.hpp"

class PlayerInput {
public:
	PlayerInput();
	void MovePlayer(sf::Event Events, sf::Sprite& GameObject, float speed, sf::RenderWindow &win);
};
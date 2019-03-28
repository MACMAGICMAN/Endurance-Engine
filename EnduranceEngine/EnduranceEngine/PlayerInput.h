#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class PlayerInput {
private:
	Vector2f direction;

public:
	PlayerInput();
	void MovePlayer(sf::Event Events, sf::Sprite& GameObject, float speed);
};
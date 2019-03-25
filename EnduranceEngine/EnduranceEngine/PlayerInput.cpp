#include "stdafx.h"
#include "PlayerInput.h"
#include <windows.h>
#include "SpriteRenderer.h"
#include "SceneGraph.h"

#include <sstream>
#include <string>

PlayerInput::PlayerInput()
{
}

void PlayerInput::MovePlayer(Event events, sf::Sprite& player, float speed) {

	//keyboard input
	if (events.type == Event::EventType::KeyPressed)
	{
		//cardinal directions
		if (events.key.code == Keyboard::Left) {
			player.move(Vector2f(-speed, 0));
		}

		else if (events.key.code == Keyboard::Right) {
			player.move(Vector2f(speed, 0));
		}

		else if (events.key.code == Keyboard::Up) {
			player.move(Vector2f(0, -speed));
		}

		else if (events.key.code == Keyboard::Down) {
			player.move(Vector2f(0, speed));
		}

		//ordinal directions
		if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Down))
		{
			player.move(Vector2f(-speed, speed));
		}

		if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Down))
		{
			player.move(Vector2f(speed, speed));
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Up))
		{
			player.move(Vector2f(-speed, -speed));
		}

		if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Up))
		{
			player.move(Vector2f(speed, -speed));
		}
	}

	//mouse input
	if (events.type == Event::EventType::MouseMoved) {
		Vector2i vec = Mouse::getPosition();

	}
}

void SetPlayerSpeed() {

}
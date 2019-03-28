#include "PlayerInput.h"
#include <windows.h>

PlayerInput::PlayerInput()
{
}

void PlayerInput::MovePlayer(Event events, Sprite& sprite, float speed) {

	//keyboard input
	if (events.type == Event::KeyPressed)
	{
		//cardinal directions
		if (events.key.code == Keyboard::Left) {
			sprite.move(-speed, 0);
		}

		if (events.key.code == Keyboard::Right) {
			sprite.move(speed, 0);
		}

		if (events.key.code == Keyboard::Up) {
			sprite.move(0, -speed);
		}

		if (events.key.code == Keyboard::Down) {
			sprite.move(0, speed);
		}
		
		//ordinal directions
		if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Down))
		{
			sprite.move(-speed, speed);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Down))
		{
			sprite.move(speed, speed);
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Up))
		{
			sprite.move(-speed, -speed);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Up))
		{
			sprite.move(speed, -speed);
		}
		
	}
}
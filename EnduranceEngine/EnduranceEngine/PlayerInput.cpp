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

void PlayerInput::MovePlayer(sf::Event events, sf::Sprite& GameObject, float speed) {


	if (events.type == sf::Event::EventType::KeyPressed)
	{
		if (events.key.code == Keyboard::Left) {

			//OutputDebugString("Left pressed\n");
			GameObject.move(sf::Vector2f(-speed, 0));
		}

		else if (events.key.code == Keyboard::Right) {

			//OutputDebugString("Right pressed\n");
			GameObject.move(sf::Vector2f(speed, 0));
		}


		else if (events.key.code == Keyboard::Up) {

			//OutputDebugString("Up pressed\n");
			GameObject.move(sf::Vector2f(0, -speed));
		}


		else if (events.key.code == Keyboard::Down) {

			//OutputDebugString("Down pressed\n");
			GameObject.move(sf::Vector2f(0, speed));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			GameObject.move(sf::Vector2f(-speed, speed));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			GameObject.move(sf::Vector2f(speed, speed));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			GameObject.move(sf::Vector2f(-speed, -speed));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			GameObject.move(sf::Vector2f(speed, -speed));
		}


		if (events.type == sf::Event::EventType::MouseMoved) {
			sf::Vector2i vec = sf::Mouse::getPosition();

		}
	}


}

void SetPlayerSpeed() {

}
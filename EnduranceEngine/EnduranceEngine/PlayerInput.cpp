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



void PlayerInput::MovePlayer(sf::Event events, sf::Sprite& GameObject, float speed, sf::RenderWindow &win) {


	if (events.type == sf::Event::EventType::KeyPressed)
	{

		//Left, Right, Up, Down
		if (events.key.code == Keyboard::Left) {
			GameObject.move(sf::Vector2f(-speed, 0));
		}

		else if (events.key.code == Keyboard::Right) {

			GameObject.move(sf::Vector2f(speed, 0));
		}


		else if (events.key.code == Keyboard::Up) {

			GameObject.move(sf::Vector2f(0, -speed));

		}


		else if (events.key.code == Keyboard::Down) {

			GameObject.move(sf::Vector2f(0, speed));
		}

		else if (events.key.code == Keyboard::Space){
			//shoot?
		}

		//Diangonal Input
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

		//Mouse Input
		
	}


		//get current Position
		sf::Vector2f curPos; 
		//get Pivot Point
		curPos.x = GameObject.getGlobalBounds().left; 
		curPos.y = GameObject.getGlobalBounds().top;
		sf::Vector2i position = sf::Mouse::getPosition(win);

		const float PI = 3.14159;

		float dx = position.x - curPos.x;
		float dy = position.y - curPos.y;

		float rotation = (atan2(dy/2, dx / 2)) * 180 / PI;
		GameObject.setOrigin(400, 400);
		GameObject.setRotation(rotation);
		


}
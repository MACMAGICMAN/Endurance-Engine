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

void PlayerInput::MovePlayer(sf::Event events, sf::Sprite& GameObject) {


	if (events.type == sf::Event::EventType::KeyPressed)
	{
		switch (events.key.code)
		{
		case sf::Keyboard::Left:
		{
			OutputDebugString("Left pressed\n");

			GameObject.move(sf::Vector2f(2, 0));
			
			return;
		}
		case sf::Keyboard::Right:
		{
			OutputDebugString("Right pressed\n");
			break;
		}
		case sf::Keyboard::Up:
		{
			OutputDebugString("Up pressed\n");
			break;
		}

		case sf::Keyboard::Down:
		{
			OutputDebugString("Down pressed\n");
			//window.close();
			break;
		}

		case sf::Keyboard::Space:
		{
			OutputDebugString("Space pressed\n");
			break;
		}
		case sf::Keyboard::Enter:
		{
			OutputDebugString("Enter pressed\n");
			break;
		}


		}
	}

	if (events.type == sf::Event::EventType::MouseMoved) {
		sf::Vector2i vec = sf::Mouse::getPosition();
		
	}
}
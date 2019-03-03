#include "stdafx.h"
#include "PlayerInput.h"

PlayerInput::PlayerInput()
{

}

PlayerInput::~PlayerInput()
{
}

void PlayerInput::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
	
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		SceneGraph().t_object.Translate(10.0f, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		SceneGraph().t_object.Rotate(90.0f);

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		SceneGraph().t_object.Scale(15.0f, 15.0f);
	}

	sf::Vector2i globalPosition = sf::Mouse::getPosition();
}

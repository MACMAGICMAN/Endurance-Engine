#include "stdafx.h"
#include "Collision.h"
#include <windows.h>
#include "SpriteRenderer.h"
#include "SceneGraph.h"
#include <sstream>
#include <string>


Collision::Collision()
{
}


void Collision::CollideWithPlayer(sf::Sprite& CollideObjectOne, sf::Sprite& CollideObjectTwo,bool damagable, bool reverse) {

	FloatRect playerBounds = CollideObjectOne.getGlobalBounds();
	FloatRect wallBounds = CollideObjectTwo.getGlobalBounds();
	FloatRect nexPos;
	float windowWidth = 1350;
	float windowHeight = 775;


	nexPos = playerBounds;
	/*
	if (CollideObjectOne.getPosition().x < 25.f)
		CollideObjectOne.setPosition(25.f, CollideObjectOne.getPosition().y);

	if (CollideObjectOne.getPosition().y < 25.f)
		CollideObjectOne.setPosition(CollideObjectOne.getPosition().x, 25.f);

	if (CollideObjectOne.getPosition().x + CollideObjectOne.getGlobalBounds().width > windowWidth)
		CollideObjectOne.setPosition(windowWidth - CollideObjectOne.getGlobalBounds().width, CollideObjectOne.getPosition().y);

	if (CollideObjectOne.getPosition().y + CollideObjectOne.getGlobalBounds().height > windowHeight)
		CollideObjectOne.setPosition(CollideObjectOne.getPosition().x,windowHeight - CollideObjectOne.getGlobalBounds().height);
*/
	//if (CollideObjectOne.getGlobalBounds().intersects(CollideObjectTwo.getGlobalBounds())) {

		//OutputDebugString("Colliding\n");
		//CollideObjectOne.move(sf::Vector2f(0,-6));

	//}
	//else {
	//	OutputDebugString("Not Colliding\n");
	//}

	if (wallBounds.intersects(nexPos))
	{   
		//Player Bottom
		if (playerBounds.top < wallBounds.top
			&& playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
			&& playerBounds.left < wallBounds.left + wallBounds.width
			&& playerBounds.left + playerBounds.width > wallBounds.left)
		{
			if (damagable == true)
			{
				
				ishit = ishit - 1;
			}

			if (reverse == true)
			{
				rot = 1;
				//CollideObjectOne.
			}
			
				//CollideObjectOne.move(sf::Vector2f(0, 0));
				//CollideObjectOne.setPosition(CollideObjectOne.getPosition().x, CollideObjectTwo.getPosition().y + wallBounds.top - wallBounds.height - 6);
			
			
			
		}

		//Player Top
		else if (playerBounds.top > wallBounds.top
			&& playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
			&& playerBounds.left < wallBounds.left + wallBounds.width
			&& playerBounds.left + playerBounds.width >wallBounds.left)
		{
			if (damagable == true)
			{
				ishit = ishit - 1;
			}
			if (reverse == true)
			{
				rot = 2;
				//CollideObjectOne.
			}
			
				//CollideObjectOne.move(sf::Vector2f(0, 0));
				//CollideObjectOne.setPosition(CollideObjectOne.getPosition().x, CollideObjectTwo.getPosition().y + wallBounds.top - wallBounds.height - 6);
			
		}

		//Player Right
		else if (playerBounds.left < wallBounds.left
			&& playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
			&& playerBounds.top < wallBounds.top + wallBounds.height
			&& playerBounds.top + playerBounds.height > wallBounds.top)
		{
			if (damagable == true)
			{
				ishit = ishit - 1;
			}
			if (reverse == true)
			{
				rot = 3;
				//CollideObjectOne.
			}
			
				//CollideObjectOne.move(sf::Vector2f(0, 0));
				//CollideObjectOne.setPosition(CollideObjectOne.getPosition().x, CollideObjectTwo.getPosition().y + wallBounds.top - wallBounds.height - 6);
			
		}

		//Player Left
		else if (playerBounds.left > wallBounds.left
			&& playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
			&& playerBounds.top < wallBounds.top + wallBounds.height
			&& playerBounds.top + playerBounds.height > wallBounds.top)
		{
			if (damagable == true)
			{
				ishit = ishit - 1;
			}
			if (reverse == true)
			{
				rot = 4;
				//CollideObjectOne.
			}
			
				//CollideObjectOne.move(sf::Vector2f(0, 0));
				//CollideObjectOne.setPosition(CollideObjectOne.getPosition().x, CollideObjectTwo.getPosition().y + wallBounds.top - wallBounds.height - 6);
			
		}
			
			
		
	}
}

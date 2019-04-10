#include "stdafx.h"
#include "Collision.h"
#include <windows.h>
#include "SpriteRenderer.h"
#include <sstream>
#include <string>


Collision::Collision()
{
}

void Collision::HandleCollisions(sf::Sprite& objectA, sf::Sprite& objectB) {



	FloatRect playerBounds = CollideObjectOne.getGlobalBounds();
	FloatRect wallBounds = CollideObjectTwo.getGlobalBounds();
	FloatRect nexPos;
	float windowWidth = 1350;
	float windowHeight = 775;

	//FloatRect a = objectA.getGlobalBounds();
	//FloatRect b = objectB.getGlobalBounds();

	if (CollideObjectOne.getPosition().x < 25.f)
		CollideObjectOne.setPosition(25.f, CollideObjectOne.getPosition().y);

	if (CollideObjectOne.getPosition().y < 25.f)
		CollideObjectOne.setPosition(CollideObjectOne.getPosition().x, 25.f);

	if (CollideObjectOne.getPosition().x + CollideObjectOne.getGlobalBounds().width > windowWidth)
		CollideObjectOne.setPosition(windowWidth - CollideObjectOne.getGlobalBounds().width, CollideObjectOne.getPosition().y);

	if (CollideObjectOne.getPosition().y + CollideObjectOne.getGlobalBounds().height > windowHeight)
		CollideObjectOne.setPosition(CollideObjectOne.getPosition().x,windowHeight - CollideObjectOne.getGlobalBounds().height);

		/*
		//bottom of A / top of B
		if (a.top + a.height > b.top && a.top < b.top) {
			OutputDebugString("bottom edge collided. \n");
			objectA.move(Vector2f(0, 0));
			objectA.setPosition(a.left, b.top - a.height);
		}


	if (wallBounds.intersects(nexPos))
	{   
		//Player Bottom
		if (playerBounds.top < wallBounds.top
			&& playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
			&& playerBounds.left < wallBounds.left + wallBounds.width
			&& playerBounds.left + playerBounds.width > wallBounds.left)
		{
			CollideObjectOne.move(sf::Vector2f(0, 0));
			CollideObjectOne.setPosition(CollideObjectOne.getPosition().x, CollideObjectTwo.getPosition().y + wallBounds.top - wallBounds.height - 6);
		}

		//Player Top
		else if (playerBounds.top > wallBounds.top
			&& playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
			&& playerBounds.left < wallBounds.left + wallBounds.width
			&& playerBounds.left + playerBounds.width >wallBounds.left)
		{
			CollideObjectOne.move(sf::Vector2f(0, 0));
			CollideObjectOne.setPosition(CollideObjectOne.getPosition().x, wallBounds.top + wallBounds.height + (playerBounds.height / 2));
		}

		//Player Right
		else if (playerBounds.left < wallBounds.left
			&& playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
			&& playerBounds.top < wallBounds.top + wallBounds.height
			&& playerBounds.top + playerBounds.height > wallBounds.top)
		{
			CollideObjectOne.move(sf::Vector2f(0, 0));
			CollideObjectOne.setPosition(CollideObjectTwo.getPosition().x + wallBounds.left - wallBounds.width +50, CollideObjectOne.getPosition().y);
		}

		//Player Left
		else if (playerBounds.left > wallBounds.left
			&& playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
			&& playerBounds.top < wallBounds.top + wallBounds.height
			&& playerBounds.top + playerBounds.height > wallBounds.top)
		{
			CollideObjectOne.move(sf::Vector2f(0, 0)); 
				CollideObjectOne.setPosition(CollideObjectTwo.getPosition().x + wallBounds.left / 8 + wallBounds.width, CollideObjectOne.getPosition().y);
		}
		*/
	//}
}
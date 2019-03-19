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


void Collision::CollideWithPlayer(sf::Sprite& CollideObjectOne, sf::Sprite& CollideObjectTwo) {

	FloatRect playerBounds = CollideObjectOne.getGlobalBounds();
	FloatRect wallBounds = CollideObjectTwo.getGlobalBounds();
	FloatRect nexPos;

	nexPos = playerBounds;


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
			CollideObjectOne.move(sf::Vector2f(0, 0));
			CollideObjectOne.setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
		}

		//Player Top
		else if (playerBounds.top > wallBounds.top
			&& playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
			&& playerBounds.left < wallBounds.top + wallBounds.width
			&& playerBounds.left + playerBounds.width >wallBounds.left)
		{
			CollideObjectOne.move(sf::Vector2f(0, 0));
			CollideObjectOne.setPosition(playerBounds.left, wallBounds.top - wallBounds.height);
		}

		//Player Right
		if (playerBounds.left < wallBounds.left
			&& playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
			&& playerBounds.top < wallBounds.top + wallBounds.height
			&& playerBounds.top + playerBounds.height > wallBounds.top)
		{
			CollideObjectOne.move(sf::Vector2f(0, 0));
			CollideObjectOne.setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
		}
			
			
		
	}
}

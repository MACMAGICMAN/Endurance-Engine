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


void Collision::CollideWithPlayer(sf::Sprite& CollideObjectOne, sf::Sprite& CollideObjectTwo){

	if (CollideObjectOne.getGlobalBounds().intersects(CollideObjectTwo.getGlobalBounds())) {

		OutputDebugString("Colliding");
	}
	else {
		OutputDebugString("Not Colliding");
	}

}

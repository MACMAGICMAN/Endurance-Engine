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

	FloatRect a = objectA.getGlobalBounds();
	FloatRect b = objectB.getGlobalBounds();

	if (b.intersects(a))
	{
		//Player Bottom
		/*if (a.top < b.top
			&& a.top + a.height < b.top + b.height
			&& a.left < b.left + b.width
			&& a.left + a.width > b.left)
		{
			CollideObjectOne.move(sf::Vector2f(0, 0));
			CollideObjectOne.setPosition(a.left, b.top - a.height);
		}*/

		//bottom of A / top of B
		if (a.top + a.height > b.top && a.top < b.top ) {
			objectA.move(Vector2f(0, 0));
			objectA.setPosition(a.left, b.top - a.height);
		}
		
		//top of A / bottom of B
		else if (a.top < b.top + b.height && a.top + a.height > b.top + b.height) {
			objectA.move(Vector2f(0, 0));
			objectA.setPosition(a.left, b.top + b.height);
		}

		//right of A / left of B
		else if (a.left + a.width > b.left && a.left < b.left ) {
			objectA.move(Vector2f(0, 0));
			objectA.setPosition(b.left - a.left, a.top);
		}

		//left of A / right of B
		else if (a.left < b.left + b.width && a.left + a.width > b.left + b.width) {
			objectA.move(Vector2f(0, 0));
			objectA.setPosition(b.left + b.width, a.top);
		}
	}
}
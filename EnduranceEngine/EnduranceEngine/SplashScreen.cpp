#include "SplashScreen.h"
#include "SceneGraph.h"
#include "PlayerInput.h"
#include "Menu.h"

#include <windows.h>
#include <sstream>
#include <string>


PlayerInput* playerInput = new PlayerInput();
int bulletcount = 0;
bool isplay = false;
int ishittemp = 0;
bool doonce = true;

//SceneGraph bullets[];

SplashScreen::SplashScreen()
{
}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::bulletSpawn(sf::Sprite& p, sf::Sprite& b, RenderWindow& w)
{

	b.setScale(.05, .01);
	sf::Vector2f curPos;
	curPos.x = p.getGlobalBounds().left;
	curPos.y = p.getGlobalBounds().top;
	sf::Vector2i position = sf::Mouse::getPosition(w);

	const float PI = 3.14159;

	float dx = position.x - curPos.x;
	float dy = position.y - curPos.y;

	float rotation = (atan2(dy / 2, dx / 2)) * 180 / PI;
	b.setRotation(rotation);
	b.setPosition(sf::Vector2f(curPos.x + p.getGlobalBounds().width/2, curPos.y + p.getGlobalBounds().height / 2));

	
	
	

}

void checkedge(sf::Sprite& a, RenderWindow& w)
{
	if (a.getPosition().x >= w.getSize().x)
	{
		a.setPosition(.25, a.getPosition().y);
	}
	else if (a.getPosition().x <= 0)
	{
		a.setPosition(w.getSize().x - .25, a.getPosition().y);
	}
	else if (a.getPosition().y >= w.getSize().y)
	{
		a.setPosition(a.getPosition().x, .25);
	}
	else if (a.getPosition().y <= 0)
	{
		a.setPosition(a.getPosition().x, w.getSize().y - .25);
	}
}

void objectUpdate(sf::Sprite& b, sf::Sprite& a, sf::Sprite& a2, sf::Sprite& a3, sf::Sprite& a4, sf::Sprite& a5, sf::Sprite& a6)
{
	if (doonce == true)
	{
		a.setRotation(rand()%360);
		a2.setRotation(rand() % 360);
		a3.setRotation(rand() % 360);
		a4.setRotation(rand() % 360);
		a5.setRotation(rand() % 360);
		a6.setRotation(rand() % 360);
		
		
		doonce = false;
	}
	const float PI = 3.14159;
	b.move(sf::Vector2f(-sin((b.getRotation() - 90) / 180 * PI) * 2, cos((b.getRotation() - 90) / 180 * PI) * 2));
	//a.setRotation(a.getRotation() + .01);
	a.move(sf::Vector2f(-sin((a.getRotation()) / 180 * PI) * 0.01, cos((a.getRotation()) / 180 * PI) * 0.01));
	a2.move(sf::Vector2f(-sin((a2.getRotation()) / 180 * PI) * 0.02, cos((a2.getRotation()) / 180 * PI) * 0.02));
	a3.move(sf::Vector2f(-sin((a3.getRotation()) / 180 * PI) * 0.03, cos((a3.getRotation()) / 180 * PI) * 0.03));
	a4.move(sf::Vector2f(-sin((a4.getRotation()) / 180 * PI) * 0.04, cos((a4.getRotation()) / 180 * PI) * 0.04));
	a5.move(sf::Vector2f(-sin((a5.getRotation()) / 180 * PI) * 0.05, cos((a5.getRotation()) / 180 * PI) * 0.05));
	a6.move(sf::Vector2f(-sin((a6.getRotation()) / 180 * PI) * 0.06, cos((a6.getRotation()) / 180 * PI) * 0.06));
	return;
}

void SplashScreen::Update(Time dt)
{
	int count = 0;

	Clock c;
	SceneGraph splash;
	SceneGraph background;
	SceneGraph menuBackground;
	SceneGraph optionsBackground;
	SceneGraph player;
	//SceneGraph wall;
	SceneGraph bullet;
	SceneGraph asteroid;
	SceneGraph asteroid2;
	SceneGraph asteroid3;
	SceneGraph asteroid4;
	SceneGraph asteroid5;
	SceneGraph asteroid6;
	SceneGraph life1;
	SceneGraph life2;
	SceneGraph life3;
	
	srand(time(NULL));
	//Sprite Files
	splash.sprite.LoadSprite("../Documents/Import/back_Logo.jpg");
	background.sprite.LoadSprite("../Documents/Import/back_Game.jpg");
	menuBackground.sprite.LoadSprite("../Documents/Import/back_Main.jpg");
	optionsBackground.sprite.LoadSprite("../Documents/Import/back_Options.jpg");
	//wall.sprite.LoadSprite("../Documents/Import/back_Logo.jpg");
	player.sprite.LoadSprite("../Documents/Import/player_Sprite.png");
	bullet.sprite.LoadSprite("../Documents/Import/back_Logo.jpg");
	asteroid.sprite.LoadSprite("../Documents/Import/asteroid.png");
	asteroid2.sprite.LoadSprite("../Documents/Import/asteroid.png");
	asteroid3.sprite.LoadSprite("../Documents/Import/asteroid.png");
	asteroid4.sprite.LoadSprite("../Documents/Import/asteroid.png");
	asteroid5.sprite.LoadSprite("../Documents/Import/asteroid.png");
	asteroid6.sprite.LoadSprite("../Documents/Import/asteroid.png");
	life1.sprite.LoadSprite("../Documents/Import/player_Sprite.jpg");
	life2.sprite.LoadSprite("../Documents/Import/player_Sprite.jpg");
	life3.sprite.LoadSprite("../Documents/Import/player_Sprite.jpg");

	//Audio Files
	splash.audio.PlayAudio("../Documents/Import/startup.wav");

	RenderWindow window(VideoMode(1280, 720), "Splash screen test"/*, Style::None*/);
	Menu menu(window.getSize().x, window.getSize().y);

	//wall.sprite.image.setPosition(sf::Vector2f(500, 500));
	//wall.sprite.image.setScale(0, 0);

	bullet.sprite.image.setScale(0, 0);
	bullet.sprite.image.setPosition(rand()%window.getSize().x, rand() % window.getSize().y);

	life1.sprite.image.setScale(0, 0);
	life1.sprite.image.setPosition(50, window.getSize().y - 50);

	life2.sprite.image.setScale(0, 0);
	life2.sprite.image.setPosition(100, window.getSize().y - 50);

	life3.sprite.image.setScale(0, 0);
	life3.sprite.image.setPosition(150, window.getSize().y - 50);

	asteroid.sprite.image.setPosition(rand() % window.getSize().x, rand() % window.getSize().y);
	asteroid2.sprite.image.setPosition(rand() % window.getSize().x, rand() % window.getSize().y);
	asteroid3.sprite.image.setPosition(rand() % window.getSize().x, rand() % window.getSize().y);
	asteroid4.sprite.image.setPosition(rand() % window.getSize().x, rand() % window.getSize().y);
	asteroid5.sprite.image.setPosition(rand() % window.getSize().x, rand() % window.getSize().y);
	asteroid6.sprite.image.setPosition(rand() % window.getSize().x, rand() % window.getSize().y);
	//asteroid.sprite.image.setRotation(180);

	player.sprite.image.setPosition(sf::Vector2f(300, 200));
	player.sprite.image.setScale(0, 0);
	player.Collision.ishit = 3;
	background.sprite.image.setScale(0, 0);
	optionsBackground.sprite.image.setScale(0, 0);
	menuBackground.sprite.image.setScale(1,1);

	//background.sprite.image.setPosition(sf::Vector2f(300, 200));
	//background.sprite.image.setScale(1, 1);

	Font bluehighway;
	bluehighway.loadFromFile("../Documents/Import/blue highway.ttf");

	
	Text text;
	text.setFont(bluehighway);
	text.setFillColor(Color::Red);
	text.setCharacterSize(32);


	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			//playerInput->MovePlayer(event, splash.sprite.image);
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch(event.key.code){
				case sf::Keyboard::Up:
					menu.moveUp();
					break;
				case sf::Keyboard::RControl:
					bulletSpawn(player.sprite.image, bullet.sprite.image, window);
					break;
				case sf::Keyboard::Down:
					menu.moveDown();
					break;
				case sf::Keyboard::P:
					menu.show(window);
					menuBackground.sprite.image.setScale(1, 1);
					isplay = false;
					break;
				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						menuBackground.sprite.image.setScale(0, 0);
						optionsBackground.sprite.image.setScale(0, 0);
						background.sprite.image.setScale(1, 1);
						player.sprite.image.setScale(0.1, 0.1);
						//wall.sprite.image.setScale(0.3, 0.3);

						menu.clear(window);
						isplay = true;
						break;
					case 1:
						optionsBackground.sprite.image.setScale(1, 1);
						menu.back(window);
						break;
					case 2:
						window.close();
						break;
					case 3:
						optionsBackground.sprite.image.setScale(0, 0);
						break;
					}

					
				}
			



			}

		}
		if (isplay == true)
		{
			if (player.Collision.ishit < 3)
			{
				life3.sprite.image.setScale(0, 0);
			}
			else
			{
				life3.sprite.image.setScale(0.1,0.1);
			}
			if (player.Collision.ishit < 2)
			{
				life2.sprite.image.setScale(0, 0);
			}
			else
			{
				life2.sprite.image.setScale(0.1, 0.1);
			}
			if (player.Collision.ishit < 1)
			{
				life3.sprite.image.setScale(0, 0);
			}
			else
			{
				life1.sprite.image.setScale(0.1, 0.1);
			}
			splash.keyboard.MovePlayer(event, player.sprite.image, 0.2, window);
			//splash.Collision.CollideWithPlayer(player.sprite.image, wall.sprite.image, false, false);
			//asteroid.Collision.CollideWithPlayer(asteroid.sprite.image, wall.sprite.image, false, true);

			//asteroid hit by bullet
			asteroid.Collision.CollideWithPlayer(asteroid.sprite.image, bullet.sprite.image, true, false);
			if (asteroid.Collision.ishit <= 0)
			{
				asteroid.sprite.image.setScale(0, 0);
				count = count + 1;
				asteroid.Collision.ishit = 1;
			}
			//asteroid hit by bullet
			asteroid2.Collision.CollideWithPlayer(asteroid2.sprite.image, bullet.sprite.image, true, false);
			if (asteroid2.Collision.ishit <= 0)
			{
				asteroid2.sprite.image.setScale(0, 0);
				count = count + 1;
				asteroid2.Collision.ishit = 1;
			}
			//asteroid hit by bullet
			asteroid3.Collision.CollideWithPlayer(asteroid3.sprite.image, bullet.sprite.image, true, false);
			if (asteroid3.Collision.ishit <= 0)
			{
				asteroid3.sprite.image.setScale(0, 0);
				count = count + 1;
				asteroid3.Collision.ishit = 1;
			}
			//asteroid hit by bullet
			asteroid4.Collision.CollideWithPlayer(asteroid4.sprite.image, bullet.sprite.image, true, false);
			if (asteroid4.Collision.ishit <= 0)
			{
				asteroid4.sprite.image.setScale(0, 0);
				count = count + 1;
				asteroid4.Collision.ishit = 1;
			}
			//asteroid hit by bullet
			asteroid5.Collision.CollideWithPlayer(asteroid5.sprite.image, bullet.sprite.image, true, false);
			if (asteroid5.Collision.ishit <= 0)
			{
				asteroid5.sprite.image.setScale(0, 0);
				count = count + 1;
				asteroid5.Collision.ishit = 1;
			}
			//asteroid hit by bullet
			asteroid6.Collision.CollideWithPlayer(asteroid6.sprite.image, bullet.sprite.image, true, false);
			if (asteroid6.Collision.ishit <= 0)
			{
				asteroid6.sprite.image.setScale(0, 0);
				count = count + 1;
				asteroid6.Collision.ishit = 1;
			}

			ishittemp = player.Collision.ishit;
			player.Collision.CollideWithPlayer(player.sprite.image, asteroid.sprite.image, true, false);
			//asteroid hit by player
			if (player.Collision.ishit < ishittemp)
			{
				asteroid.sprite.image.setScale(0, 0);
				count = count + 1;
			}
			ishittemp = player.Collision.ishit;
			player.Collision.CollideWithPlayer(player.sprite.image, asteroid2.sprite.image, true, false);
			//asteroid hit by player
			if (player.Collision.ishit < ishittemp)
			{
				asteroid2.sprite.image.setScale(0, 0);
				count = count + 1;
			}
			ishittemp = player.Collision.ishit;
			player.Collision.CollideWithPlayer(player.sprite.image, asteroid3.sprite.image, true, false);
			//asteroid hit by player
			if (player.Collision.ishit < ishittemp)
			{
				asteroid3.sprite.image.setScale(0, 0);
				count = count + 1;
			}
			ishittemp = player.Collision.ishit;
			player.Collision.CollideWithPlayer(player.sprite.image, asteroid4.sprite.image, true, false);
			//asteroid hit by player
			if (player.Collision.ishit < ishittemp)
			{
				asteroid4.sprite.image.setScale(0, 0);
				count = count + 1;
			}
			ishittemp = player.Collision.ishit;
			player.Collision.CollideWithPlayer(player.sprite.image, asteroid5.sprite.image, true, false);
			//asteroid hit by player
			if (player.Collision.ishit < ishittemp)
			{
				asteroid5.sprite.image.setScale(0, 0);
				count = count + 1;
			}
			ishittemp = player.Collision.ishit;
			player.Collision.CollideWithPlayer(player.sprite.image, asteroid6.sprite.image, true, false);
			//asteroid hit by player
			if (player.Collision.ishit < ishittemp)
			{
				asteroid6.sprite.image.setScale(0, 0);
				count = count + 1;
			}
			//player death
			if (player.Collision.ishit <= 0)
			{
				player.sprite.image.setScale(0, 0);
				menu.show(window);
				menuBackground.sprite.image.setScale(1, 1);
				isplay = false;
				player.sprite.image.setPosition(250, 250);
				player.Collision.ishit = 3;
				count = 0;
				asteroid.sprite.image.setScale(.1, .1);
				asteroid.Collision.ishit = 1;
				asteroid2.sprite.image.setScale(.1, .1);
				asteroid2.Collision.ishit = 1;
				asteroid3.sprite.image.setScale(.1, .1);
				asteroid3.Collision.ishit = 1;
				asteroid4.sprite.image.setScale(.1, .1);
				asteroid4.Collision.ishit = 1;
				asteroid5.sprite.image.setScale(.1, .1);
				asteroid5.Collision.ishit = 1;
				asteroid6.sprite.image.setScale(.1, .1);
				asteroid6.Collision.ishit = 1;
			}
			if (count >= 6)
			{
				player.sprite.image.setScale(1, 1);
				menu.show(window);
				menuBackground.sprite.image.setScale(1, 1);
				isplay = false;
				player.sprite.image.setPosition(250, 250);
				player.Collision.ishit = 3;
				count = 0;
				asteroid.sprite.image.setScale(.1, .1);
				asteroid.Collision.ishit = 1;
				asteroid2.sprite.image.setScale(.1, .1);
				asteroid2.Collision.ishit = 1;
				asteroid3.sprite.image.setScale(.1, .1);
				asteroid3.Collision.ishit = 1;
				asteroid4.sprite.image.setScale(.1, .1);
				asteroid4.Collision.ishit = 1;
				asteroid5.sprite.image.setScale(.1, .1);
				asteroid5.Collision.ishit = 1;
				asteroid6.sprite.image.setScale(.1, .1);
				asteroid6.Collision.ishit = 1;
			}
		}
		
		window.clear();
		if (isplay == true)
		{
			checkedge(asteroid.sprite.image, window);
			checkedge(asteroid2.sprite.image, window);
			checkedge(asteroid3.sprite.image, window);
			checkedge(asteroid4.sprite.image, window);
			checkedge(asteroid5.sprite.image, window);
			checkedge(asteroid6.sprite.image, window);
			checkedge(player.sprite.image, window);
			objectUpdate(bullet.sprite.image, asteroid.sprite.image, asteroid2.sprite.image, asteroid3.sprite.image, asteroid4.sprite.image, asteroid5.sprite.image, asteroid6.sprite.image);
		}
		

		window.draw(background.sprite.image);
		//window.draw(wall.sprite.image);
		window.draw(player.sprite.image);
		window.draw(bullet.sprite.image);
		window.draw(asteroid.sprite.image);
		window.draw(asteroid2.sprite.image);
		window.draw(asteroid3.sprite.image);
		window.draw(asteroid4.sprite.image);
		window.draw(asteroid5.sprite.image);
		window.draw(asteroid6.sprite.image);
		window.draw(life1.sprite.image);
		window.draw(life2.sprite.image);
		window.draw(life3.sprite.image);
		window.draw(menuBackground.sprite.image);
		window.draw(optionsBackground.sprite.image);
		
		menu.draw(window);
		window.draw(splash.sprite.image);
		/*for (int i = 0; i < bulletcount; i++)
		{
			window.draw(bullets[i].sprite.image);
		}*/
		
		
		
		//window.setFramerateLimit(50);
		c.restart();
		dt += c.getElapsedTime();
		float seconds = dt.asSeconds();

		std::ostringstream oss;
		oss << seconds * 1000;
		std::string s(oss.str());

		text.setString(s);
		window.draw(text);
		//menu.draw(window);
		if (seconds * 1000 >= 1) {
			//window.close();
			
		splash.sprite.image.setScale(0, 0);
		//RenderWindow window(VideoMode(background.sprite.texture.getSize().x, background.sprite.texture.getSize().y), "Splash screen test"/*, Style::None*/);
		
		}

		window.display();

	}




}
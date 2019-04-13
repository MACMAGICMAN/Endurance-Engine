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
		a.setPosition(10, a.getPosition().y);
	}
	else if (a.getPosition().x <= 0)
	{
		a.setPosition(w.getSize().x - 10, a.getPosition().y);
	}
	else if (a.getPosition().y >= w.getSize().y)
	{
		a.setPosition(a.getPosition().x, 10);
	}
	else if (a.getPosition().y <= 0)
	{
		a.setPosition(a.getPosition().x, w.getSize().y - 10);
	}
}

void objectUpdate(sf::Sprite& b, sf::Sprite& a)
{
	if (doonce == true)
	{
		a.setRotation(107);
		doonce = false;
	}
	const float PI = 3.14159;
	b.move(sf::Vector2f(-sin((b.getRotation() - 90) / 180 * PI) * 2, cos((b.getRotation() - 90) / 180 * PI) * 2));
	//a.setRotation(a.getRotation() + .01);
	a.move(sf::Vector2f(-sin((a.getRotation()) / 180 * PI) * 0.01, cos((a.getRotation()) / 180 * PI) * 0.01));
	return;
}

void SplashScreen::Update(Time dt)
{

	Clock c;
	SceneGraph splash;
	SceneGraph background;
	SceneGraph menuBackground;
	SceneGraph optionsBackground;
	SceneGraph player;
	SceneGraph wall;
	SceneGraph bullet;
	SceneGraph asteroid;
	

	//Sprite Files
	splash.sprite.LoadSprite("../Documents/Import/back_Logo.jpg");
	background.sprite.LoadSprite("../Documents/Import/back_Game.jpg");
	menuBackground.sprite.LoadSprite("../Documents/Import/back_Main.jpg");
	optionsBackground.sprite.LoadSprite("../Documents/Import/back_Options.jpg");
	wall.sprite.LoadSprite("../Documents/Import/back_Logo.jpg");
	player.sprite.LoadSprite("../Documents/Import/player_Sprite.png");
	bullet.sprite.LoadSprite("../Documents/Import/back_Logo.jpg");
	asteroid.sprite.LoadSprite("../Documents/Import/back_Logo.jpg");

	//Audio Files
	splash.audio.PlayAudio("../Documents/Import/startup.wav");

	RenderWindow window(VideoMode(1280, 720), "Splash screen test"/*, Style::None*/);
	Menu menu(window.getSize().x, window.getSize().y);

	wall.sprite.image.setPosition(sf::Vector2f(500, 500));
	wall.sprite.image.setScale(0, 0);

	bullet.sprite.image.setScale(0, 0);
	bullet.sprite.image.setPosition(250, 250);

	asteroid.sprite.image.setScale(.1, .1);
	asteroid.sprite.image.setPosition(750, 250);
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
						wall.sprite.image.setScale(0.3, 0.3);
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
			
			splash.keyboard.MovePlayer(event, player.sprite.image, 0.5, window);
			splash.Collision.CollideWithPlayer(player.sprite.image, wall.sprite.image, false, false);
			//asteroid.Collision.CollideWithPlayer(asteroid.sprite.image, wall.sprite.image, false, true);

			//asteroid hit by bullet
			asteroid.Collision.CollideWithPlayer(asteroid.sprite.image, bullet.sprite.image, true, false);
			if (asteroid.Collision.ishit <= 0)
			{
				asteroid.sprite.image.setScale(0, 0);
			}

			ishittemp = player.Collision.ishit;
			player.Collision.CollideWithPlayer(player.sprite.image, asteroid.sprite.image, true, false);
			//asteroid hit by player
			if (player.Collision.ishit < ishittemp)
			{
				asteroid.sprite.image.setScale(0, 0);
			}
			//player death
			if (player.Collision.ishit <= 0)
			{
				player.sprite.image.setScale(0, 0);
				menu.show(window);
				menuBackground.sprite.image.setScale(1, 1);
				isplay = false;
				player.Collision.ishit = 3;
			}
		}
		
		window.clear();

		checkedge(asteroid.sprite.image, window);
		checkedge(player.sprite.image, window);
		objectUpdate(bullet.sprite.image, asteroid.sprite.image);

		window.draw(background.sprite.image);
		//window.draw(wall.sprite.image);
		window.draw(player.sprite.image);
		window.draw(bullet.sprite.image);
		window.draw(asteroid.sprite.image);
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
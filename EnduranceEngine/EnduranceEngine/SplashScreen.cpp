#include "SplashScreen.h"
#include "SceneGraph.h"
#include "PlayerInput.h"
#include "Menu.h"

#include <windows.h>
#include <sstream>
#include <string>


PlayerInput* playerInput = new PlayerInput();
int bulletcount = 0;
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

void bulletUpdate(sf::Sprite& b)
{
	const float PI = 3.14159;
	b.move(sf::Vector2f(-sin((b.getRotation() - 90) / 180 * PI), cos((b.getRotation() - 90) / 180 * PI)));
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
	

	//Sprite Files
	splash.sprite.LoadSprite("../Documents/Import/back_Logo.jpg");
	background.sprite.LoadSprite("../Documents/Import/back_Game.jpg");
	menuBackground.sprite.LoadSprite("../Documents/Import/back_Main.jpg");
	optionsBackground.sprite.LoadSprite("../Documents/Import/back_Options.jpg");
	wall.sprite.LoadSprite("../Documents/Import/back_Logo.jpg");
	player.sprite.LoadSprite("../Documents/Import/player_Sprite.png");
	bullet.sprite.LoadSprite("../Documents/Import/back_Logo.jpg");

	//Audio Files
	splash.audio.PlayAudio("../Documents/Import/startup.wav");

	RenderWindow window(VideoMode(1280, 720), "Splash screen test"/*, Style::None*/);
	Menu menu(window.getSize().x, window.getSize().y);

	wall.sprite.image.setPosition(sf::Vector2f(500, 500));
	wall.sprite.image.setScale(0, 0);

	bullet.sprite.image.setScale(0, 0);
	bullet.sprite.image.setPosition(250, 250);

	player.sprite.image.setPosition(sf::Vector2f(300, 200));
	player.sprite.image.setScale(0, 0);
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
		splash.keyboard.MovePlayer(event, player.sprite.image, 0.5, window);
		splash.Collision.CollideWithPlayer(player.sprite.image, wall.sprite.image, false);
		/*player.Collision.CollideWithPlayer(player.sprite.image, asteroid.sprite.image, true);
		astroid.Collision.CollideWithPlayer(astroid.sprite.image, player.sprite.image, true);
		if (astroid.Collision.ishit <= 0)
		{
			astroid.sprite.image.setScale(0, 0);
		}
		if (player.Collision.ishit <= 0)
		{
			player.sprite.image.setScale(0, 0);
			menu.show(window);
		}*/
		window.clear();

		bulletUpdate(bullet.sprite.image);

		window.draw(background.sprite.image);
		window.draw(wall.sprite.image);
		window.draw(player.sprite.image);
		window.draw(menuBackground.sprite.image);
		window.draw(optionsBackground.sprite.image);
		menu.draw(window);
		window.draw(splash.sprite.image);
		/*for (int i = 0; i < bulletcount; i++)
		{
			window.draw(bullets[i].sprite.image);
		}*/
		window.draw(bullet.sprite.image);
		
		
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
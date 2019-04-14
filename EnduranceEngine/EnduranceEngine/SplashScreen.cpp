#include "SplashScreen.h"
#include <Windows.h>

PlayerInput* playerInput = new PlayerInput();
int bulletcount = 0;
bool isplay = false;
int ishittemp = 0;
bool doonce = true;

SplashScreen::SplashScreen()
{
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::SpawnBullet(Sprite& p, Sprite& b, RenderWindow& w)
{
	b.setScale(.05, .01);
	sf::Vector2f curPos;
	curPos.x = p.getGlobalBounds().left;
	curPos.y = p.getGlobalBounds().top;
	sf::Vector2i position = sf::Mouse::getPosition(w);

	float dx = position.x - curPos.x;
	float dy = position.y - curPos.y;

	float rotation = (atan2(dy / 2, dx / 2)) * 180 / M_PI;
	b.setRotation(rotation);
	b.setPosition(sf::Vector2f(curPos.x + p.getGlobalBounds().width / 2, curPos.y + p.getGlobalBounds().height / 2));
}

void CheckEdge(Sprite& sprite, RenderWindow& window)
{
	if (sprite.getPosition().x >= window.getSize().x)
	{
		sprite.setPosition(.25, sprite.getPosition().y);
	}
	else if (sprite.getPosition().x <= 0)
	{
		sprite.setPosition(window.getSize().x - .25, sprite.getPosition().y);
	}
	else if (sprite.getPosition().y >= window.getSize().y)
	{
		sprite.setPosition(sprite.getPosition().x, .25);
	}
	else if (sprite.getPosition().y <= 0)
	{
		sprite.setPosition(sprite.getPosition().x, window.getSize().y - .25);
	}
}

void objectUpdate(sf::Sprite& b, sf::Sprite& a, sf::Sprite& a2, sf::Sprite& a3, sf::Sprite& a4, sf::Sprite& a5, sf::Sprite& a6)
{
	if (doonce)
	{
		a.setRotation(rand() % 360);
		a2.setRotation(rand() % 360);
		a3.setRotation(rand() % 360);
		a4.setRotation(rand() % 360);
		a5.setRotation(rand() % 360);
		a6.setRotation(rand() % 360);
		doonce = false;
	}

	b.move(sf::Vector2f(-sin((b.getRotation() - 90) / 180 * M_PI) * 2, cos((b.getRotation() - 90) / 180 * M_PI) * 2));
	a.move(sf::Vector2f(-sin((a.getRotation()) / 180 * M_PI) * 0.01, cos((a.getRotation()) / 180 * M_PI) * 0.01));
	a2.move(sf::Vector2f(-sin((a2.getRotation()) / 180 * M_PI) * 0.02, cos((a2.getRotation()) / 180 * M_PI) * 0.02));
	a3.move(sf::Vector2f(-sin((a3.getRotation()) / 180 * M_PI) * 0.03, cos((a3.getRotation()) / 180 * M_PI) * 0.03));
	a4.move(sf::Vector2f(-sin((a4.getRotation()) / 180 * M_PI) * 0.04, cos((a4.getRotation()) / 180 * M_PI) * 0.04));
	a5.move(sf::Vector2f(-sin((a5.getRotation()) / 180 * M_PI) * 0.05, cos((a5.getRotation()) / 180 * M_PI) * 0.05));
	a6.move(sf::Vector2f(-sin((a6.getRotation()) / 180 * M_PI) * 0.06, cos((a6.getRotation()) / 180 * M_PI) * 0.06));
	return;
}

void UpdateAsteroidMovement(Sprite& asteroid, float speed)
{
	asteroid.move(-sin((asteroid.getRotation()) / 180 * M_PI), cos((asteroid.getRotation()) / 180 * M_PI) * speed);
}

void UpdateBulletMovement(Sprite& bullet, float speed)
{
	bullet.move(Vector2f(-sin((bullet.getRotation() - 90) / 180 * M_PI), cos((bullet.getRotation() - 90) / 180 * M_PI)) * speed);
}

void SplashScreen::Update()
{
	RenderWindow window(VideoMode(1280, 720), "Splash screen test"/*, Style::None*/);
	Menu menu(window.getSize().x, window.getSize().y);

	Clock c;
	c.restart();

	SceneGraph gameBackground;
	gameBackground.sprite.LoadSprite("../Documents/Import/back_Game.jpg");
	gameBackground.sprite.image.setScale(1, 1);
	gameObjects.push_back(gameBackground);

	SceneGraph player;
	player.sprite.LoadSprite("../Documents/Import/player_Sprite.png");
	player.sprite.image.setPosition(300, 200);
	player.sprite.image.setScale(0, 0);
	player.collision.lives = 3;
	gameObjects.push_back(player);

	SceneGraph bullet;
	bullet.sprite.LoadSprite("../Documents/Import/back_Logo.jpg");
	bullet.sprite.image.setScale(0, 0);
	gameObjects.push_back(bullet);

	srand(time(NULL));
	std::vector<SceneGraph> asteroids(6);
	for (unsigned i = 0; i < asteroids.size(); i++)
	{
		asteroids[i].sprite.LoadSprite("../Documents/Import/asteroid.png");
		asteroids[i].sprite.image.setPosition(rand() % window.getSize().x, rand() % window.getSize().y);
		asteroids[i].sprite.image.setRotation(rand() & 360);
		gameObjects.push_back(asteroids[i]);
	}

	std::vector<SceneGraph> lifeIcons(3);
	for (unsigned i = 0; i < lifeIcons.size(); i++)
	{
		lifeIcons[i].sprite.LoadSprite("../Documents/Import/life_icon.png");
		lifeIcons[i].sprite.image.setPosition(50 * i, window.getSize().y - 50);

		gameObjects.push_back(lifeIcons[i]);
	}

	SceneGraph menuBackground;
	menuBackground.sprite.LoadSprite("../Documents/Import/back_Main.jpg");
	gameObjects.push_back(menuBackground);

	SceneGraph optionsBackground;
	optionsBackground.sprite.LoadSprite("../Documents/Import/back_Options.jpg");
	optionsBackground.sprite.image.setScale(0, 0);
	gameObjects.push_back(optionsBackground);

	SceneGraph splash;
	splash.sprite.LoadSprite("../Documents/Import/back_Logo.jpg");
	splash.audio.PlayAudio("../Documents/Import/startup.wav");
	gameObjects.push_back(splash);

	int killCount = 0;

	Font bluehighway;
	bluehighway.loadFromFile("../Documents/Import/blue highway.ttf");

	Text text;
	text.setFont(bluehighway);
	text.setFillColor(Color::Red);
	text.setCharacterSize(32);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) { window.close(); }

			if (event.type == Event::KeyReleased)
			{
				switch (event.key.code) {
				case Keyboard::Up:
					menu.moveUp();
					break;
				case Keyboard::RControl:
					SpawnBullet(player.sprite.image, bullet.sprite.image, window);
					break;
				case Keyboard::Down:
					menu.moveDown();
					break;
				case Keyboard::P:
					menu.show(window);
					menuBackground.sprite.image.setScale(1, 1);
					isplay = false;
					break;
				case Keyboard::Return:
				case Keyboard::Space:
					switch (menu.GetPressedItem())
					{
					case 0:
						menuBackground.sprite.image.setScale(0, 0);
						optionsBackground.sprite.image.setScale(0, 0);
						gameBackground.sprite.image.setScale(1, 1);
						player.sprite.image.setScale(0.1, 0.1);
						menu.clear(window);
						killCount = 0;
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
					default:
						break;
					}
					break;
				default:
					break;
				}
			}
		}

		if (isplay)
		{
			splash.keyboard.MovePlayer(event, player.sprite.image, 5, window);

			for (unsigned i = 0; i < lifeIcons.size(); i++)
			{
				if (i < player.collision.lives)
				{
					lifeIcons[i].sprite.image.setScale(1, 1);					
				}
				else
				{
					lifeIcons[i].sprite.image.setScale(0, 0);
				}
			}

			//asteroid hit by bullet
			for (unsigned i = 0; i < asteroids.size(); i++)
			{
				asteroids[i].collision.CollideWithPlayer(bullet.sprite.image, asteroids[i].sprite.image, true);

				if (asteroids[i].collision.lives <= 0)
				{
					asteroids[i].sprite.image.setScale(0, 0);
					bullet.sprite.image.setScale(0, 0);
					//asteroids.erase(asteroids.begin() + i);
					killCount++;
					OutputDebugString("asteroid hit by bullet.\n");
				}
			}

			//asteroid hit by player
			ishittemp = player.collision.lives;
			for (unsigned i = 0; i < asteroids.size(); i++)
			{
				player.collision.CollideWithPlayer(player.sprite.image, asteroids[i].sprite.image, true);
				if (player.collision.lives < ishittemp)
				{
					asteroids[i].sprite.image.setScale(0, 0);
					killCount++;
					OutputDebugString("asteroid hit by player.\n");
				}
			}

			//game over
			if (player.collision.lives <= 0 || killCount >= asteroids.capacity())
			{
				if (player.collision.lives <= 0)
				{
					player.sprite.image.setScale(0, 0);
					OutputDebugString("GAME LOSE\n");
				}

				menu.show(window);
				menuBackground.sprite.image.setScale(1, 1);
				isplay = false;
				player.sprite.image.setPosition(250, 250);
				player.collision.lives = 3;
				killCount = 0;
				for (SceneGraph sg : asteroids)
				{
					sg.sprite.image.setScale(.1, .1);
					sg.collision.lives = 1;
				}
			}
		}

		window.clear();
		if (isplay)
		{
			CheckEdge(player.sprite.image, window);

			for (SceneGraph sg : asteroids)
			{
				CheckEdge(sg.sprite.image, window);
			}

			UpdateBulletMovement(bullet.sprite.image, 10);

			for (unsigned i = 0; i < asteroids.size(); i++)
			{
				UpdateAsteroidMovement(asteroids[i].sprite.image, i * 0.1);
			}
		}

		window.draw(gameBackground.sprite.image);
		window.draw(player.sprite.image);
		window.draw(bullet.sprite.image);
		for (SceneGraph sg : asteroids)
		{
			window.draw(sg.sprite.image);
		}
		for (SceneGraph sg : lifeIcons)
		{
			window.draw(sg.sprite.image);
		}
		window.draw(menuBackground.sprite.image);
		window.draw(optionsBackground.sprite.image);
		menu.draw(window);
		window.draw(splash.sprite.image);
		/*
		for (SceneGraph sg : gameObjects)
		{
			window.draw(sg.sprite.image);
		}
		*/

		float seconds = c.getElapsedTime().asSeconds();
		/*
		std::ostringstream oss;
		oss << seconds;
		std::string s(oss.str());
		text.setString(s);
		window.draw(text);
		*/

		if (seconds >= 5) {
			splash.sprite.image.setScale(0, 0);
		}

		window.display();
	}
}
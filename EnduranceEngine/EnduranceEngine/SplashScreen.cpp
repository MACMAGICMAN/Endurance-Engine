#include "SplashScreen.h"

SplashScreen::SplashScreen()
{

}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::Update(Time dt)
{
	Clock c;
	
	Texture t_logo;
	t_logo.loadFromFile("../Documents/Import/logo.jpg");

	Sprite s_logo;
	s_logo.setTexture(t_logo);
	
	RenderWindow window(VideoMode(t_logo.getSize().x, t_logo.getSize().y), "Splash screen test"/*, Style::None*/);

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
		}

		window.clear();
		window.draw(s_logo);

		c.restart();
		dt += c.getElapsedTime();
		float seconds = dt.asSeconds();

		ostringstream oss;
		oss << seconds * 1000;
		string s(oss.str());

		text.setString(s);
		window.draw(text);

		if (seconds * 1000 >= 2) {
			window.close();
		}

		window.display();
	}
}
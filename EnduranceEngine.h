#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

class EnduranceEngine
{
public:
	EnduranceEngine();
	~EnduranceEngine();
	void Initialize();
	int Start(void/*_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow*/);
private:
	static bool IsExiting();
	static void GameLoop();

	enum GameState { Unitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
};

#pragma once
#include "Snake.hpp"

class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	void UpdateBlocksize();
	int GetStrartPosition();
	void RestartTimer();
	void GameOver();
	void Death();
	bool FruitEat();




	std::unique_ptr<Window>& GetWindow();


private:

	std::unique_ptr<Textbox> m_textBox;
	std::unique_ptr<Window> m_window;
	std::unique_ptr<World> m_world;
	std::unique_ptr<Snake> m_snake;
	float m_blockSize;
	unsigned int m_numBlocks;
	sf::Clock m_Timer;
	float m_elapsedTime;
	bool keypressed;





};


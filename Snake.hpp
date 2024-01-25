#pragma once
#include "World.hpp"
enum Direction { None, Up, Down, Left, Right };
class Snake
{
public:
	Snake(const float& l_bloackSize, const int& l_startposition);
	~Snake();


	void Update(const float& l_blockSize, const int& l_startposition);
	void Render(sf::RenderWindow& l_window);
	void Reset();
	void Move();
	void Tick(const unsigned int& l_numblocks);
	Direction GetSnakeDirection();
	void SetDirection(const Direction& l_direction);
	void SpeedUP();
	float GetSpeed();
	bool CheckCollision(const unsigned int& l_numblocks);
	int GetLives();
	void SnakeDeath(sf::RenderWindow& l_window);
	std::vector<sf::Vector2i>& GetSnakeAdress();
	void SnakeGrow();
	void recivePoints();
	std::string GetPoints();
	void ResetLivePoints();

private:

	std::vector<sf::Vector2i> m_Snake;
	int m_lives;
	float m_speed;
	float m_blockSize;
	int m_startposition;
	Direction snake_Direction;
	long long m_points;
	int m_eatenFruits;


	sf::RectangleShape m_shape_snake;


};



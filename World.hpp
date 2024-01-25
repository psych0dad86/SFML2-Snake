#pragma once
#include "Textbox.hpp"



class World
{
public:
	World(const float& l_blockSize, const unsigned int& l_numBlocks, const int& l_startpositon);
	~World();

	void Render(sf::RenderWindow& l_window);
	void Update(const float& l_blockSize, const unsigned int& l_numBlocks,
		const int& l_startpositon);
	void BorderUpdate();
	void CreateFruit();
	void CreateFruit(std::vector<sf::Vector2i>& l_Snake);
	void UpdateFruit();
	sf::Vector2u GetFruitPositon();

private:
	std::random_device m_device;
	std::mt19937 m_generator;
	std::uniform_int_distribution<int> m_distribution;

	float m_BlockSize;
	unsigned int m_numBlocks;
	unsigned int m_startposition;
	sf::RectangleShape m_bounds[4];



	sf::Vector2u m_FruitPosition;
	sf::CircleShape m_shape_fruit;


};


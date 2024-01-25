#include "World.hpp"

World::World(const float& l_blockSize, const unsigned int& l_numBlocks,
	const int& l_startposition) : m_device(), m_generator(m_device()),
	m_distribution(1, l_numBlocks - 2)
{
	m_BlockSize = l_blockSize;
	m_numBlocks = l_numBlocks;
	m_startposition = l_startposition;

	BorderUpdate();



	CreateFruit();
}

World::~World()
{
}

void World::Render(sf::RenderWindow& l_window)
{

	for (sf::RectangleShape element : m_bounds)
	{
		l_window.draw(element);
	}
	l_window.draw(m_shape_fruit);
}

void World::Update(const float& l_blockSize, const unsigned int& l_numBlocks,
	const int& l_startpositon)
{
	m_BlockSize = l_blockSize;
	m_numBlocks = l_numBlocks;
	m_startposition = l_startpositon;
	BorderUpdate();
	UpdateFruit();
}

void World::BorderUpdate()
{

	for (int i = 0; i < 4; i++)
	{
		m_bounds[i].setFillColor(sf::Color::Red);
		if (i % 2)
		{
			m_bounds[i].setSize(sf::Vector2f(m_BlockSize * m_numBlocks, m_BlockSize));
		}
		else
		{
			m_bounds[i].setSize(sf::Vector2f(m_BlockSize, m_BlockSize * m_numBlocks));
		}

		if (i < 2)
		{
			m_bounds[i].setPosition((m_startposition * m_BlockSize), 0);
		}
		else
		{
			m_bounds[i].setOrigin(sf::Vector2f(m_bounds[i].getSize()));
			m_bounds[i].setPosition(sf::Vector2f(m_BlockSize * (m_startposition + m_numBlocks), m_BlockSize * m_numBlocks));
		}
	}
}

void World::CreateFruit()
{

	m_shape_fruit.setRadius(m_BlockSize / 2 - 1);
	m_shape_fruit.setFillColor(sf::Color::Red);

	do
	{
		m_FruitPosition.x = m_distribution(m_generator);
		m_FruitPosition.y = m_distribution(m_generator);
	} while (m_FruitPosition.x == 10 || m_FruitPosition.x == 11 || m_FruitPosition.x == 12 || m_FruitPosition.y == 10);

	m_shape_fruit.setPosition(sf::Vector2f((m_startposition + m_FruitPosition.x) * m_BlockSize, m_FruitPosition.y * m_BlockSize));

}

void World::CreateFruit(std::vector<sf::Vector2i>& l_Snake)
{
	bool FreePosition = true;


	m_shape_fruit.setRadius(m_BlockSize / 2 - 1);
	m_shape_fruit.setFillColor(sf::Color::Red);

	do
	{
		FreePosition = true;
		m_FruitPosition.x = m_distribution(m_generator);
		m_FruitPosition.y = m_distribution(m_generator);


		for (sf::Vector2i segment : l_Snake)
		{
			if (segment.x == m_FruitPosition.x && segment.y == m_FruitPosition.y)
			{
				FreePosition = false;
				//Break; ????
			}
		}
	} while (FreePosition == false);
	//std::cout << m_FruitPosition.x << " < X Y > " << m_FruitPosition.y << std::endl;
	m_shape_fruit.setPosition(sf::Vector2f((m_startposition + m_FruitPosition.x) * m_BlockSize, m_FruitPosition.y * m_BlockSize));

}

void World::UpdateFruit()
{
	m_shape_fruit.setRadius(m_BlockSize / 2 - 1);
	m_shape_fruit.setPosition(sf::Vector2f((m_startposition + m_FruitPosition.x) * m_BlockSize, m_FruitPosition.y * m_BlockSize));

}

sf::Vector2u World::GetFruitPositon()
{
	return m_FruitPosition;
}





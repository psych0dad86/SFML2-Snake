#include "Snake.hpp"

Snake::Snake(const float& l_bloackSize, const int& l_startposition)
{
	m_shape_snake.setSize(sf::Vector2f(l_bloackSize - 1, l_bloackSize - 1));
	m_blockSize = l_bloackSize;
	this->Reset();
	m_lives = 3;
	m_points = 0;
	m_eatenFruits = 0;
}

Snake::~Snake()
{
}


void Snake::Update(const float& l_blockSize, const int& l_startposition)
{
	m_blockSize = l_blockSize;
	m_startposition = l_startposition;
	m_shape_snake.setSize(sf::Vector2f(m_blockSize - 1, m_blockSize - 1));
}

void Snake::Render(sf::RenderWindow& l_window)
{
	m_shape_snake.setFillColor(sf::Color::Yellow);
	m_shape_snake.setPosition((m_startposition + m_Snake.begin()->x) * m_blockSize,
		m_Snake.begin()->y * m_blockSize);
	l_window.draw(m_shape_snake);

	m_shape_snake.setFillColor(sf::Color::Green);
	for (auto itr = m_Snake.begin() + 1; itr != m_Snake.end(); ++itr)
	{
		m_shape_snake.setPosition((m_startposition + itr->x) * m_blockSize,
			itr->y * m_blockSize);
		l_window.draw(m_shape_snake);
	}

}

void Snake::Reset()
{

	m_speed = 2;
	m_eatenFruits = 0;
	snake_Direction = Direction::None;

	m_Snake.clear();
	m_Snake.push_back(sf::Vector2i(10, 10));
	m_Snake.push_back(sf::Vector2i(11, 10));
	m_Snake.push_back(sf::Vector2i(12, 10));


}

void Snake::Move()
{
	for (auto itr = m_Snake.end() - 1; itr != m_Snake.begin(); --itr)
	{
		itr->x = (itr - 1)->x;
		itr->y = (itr - 1)->y;
		//	std::cout << itr->x << " < x Y > " << itr->y << std::endl;
	}
	auto head = m_Snake.begin();

	//if (!m_Snake.empty())
	{
		if (Direction::Up == snake_Direction)
		{
			head->y--;
		}
		else if (Direction::Down == snake_Direction)
		{
			head->y++;
		}
		else if (Direction::Left == snake_Direction)
		{
			head->x--;
		}
		else if (Direction::Right == snake_Direction)
		{
			head->x++;
		}
	}


}

void Snake::Tick(const unsigned int& l_numblocks)
{
	if (Direction::None == snake_Direction) { return; }
	this->Move();

}

Direction Snake::GetSnakeDirection()
{
	return snake_Direction;
}

void Snake::SetDirection(const Direction& l_direction)
{
	snake_Direction = l_direction;
}

void Snake::SpeedUP()
{
	m_speed = m_speed + 0.5f;
}

float Snake::GetSpeed()
{
	return m_speed;
}

bool Snake::CheckCollision(const unsigned int& l_numblocks)
{
	for (auto itr = m_Snake.begin() + 1; itr != m_Snake.end(); ++itr)
	{
		if (itr->x == m_Snake.begin()->x && itr->y == m_Snake.begin()->y)
		{
			this->m_lives--;
			return true;
		}
	}

	if (m_Snake.begin()->x == 0 || m_Snake.begin()->x == l_numblocks - 1
		|| m_Snake.begin()->y == 0 || m_Snake.begin()->y == l_numblocks - 1)
	{
		this->m_lives--;
		return true;
	}
	return false;
}



int Snake::GetLives()
{
	return m_lives;
}

void Snake::SnakeDeath(sf::RenderWindow& l_window)
{
	Sleep(150);
	static bool flag = false;

	m_shape_snake.setFillColor(sf::Color::Red);
	if (flag == false)
	{
		for (auto itr = m_Snake.begin(); itr != m_Snake.end(); ++itr)
		{
			m_shape_snake.setPosition((m_startposition + itr->x) * m_blockSize,
				itr->y * m_blockSize);
			l_window.draw(m_shape_snake);
		}
		flag = true;
		return;
	}
	if (flag == true)
	{
		m_shape_snake.setFillColor(sf::Color::Yellow);
		for (auto itr = m_Snake.begin() + 1; itr != m_Snake.end(); ++itr)
		{
			m_shape_snake.setPosition((m_startposition + itr->x) * m_blockSize,
				itr->y * m_blockSize);
			l_window.draw(m_shape_snake);
		}
		flag = false;
		return;
	}
}

std::vector<sf::Vector2i>& Snake::GetSnakeAdress()
{
	return m_Snake;
}

void Snake::SnakeGrow()
{
	auto tail = m_Snake.back();

	m_Snake.push_back(tail);
}

void Snake::recivePoints()
{
	m_eatenFruits++;
	m_points = m_points + static_cast<long long>((m_eatenFruits * m_speed * 10));
	std::cout << m_points << " POINTS" << std::endl;
}

std::string Snake::GetPoints()
{
	return std::to_string(m_points);
}

void Snake::ResetLivePoints()
{
	m_lives = 3;
	m_points = 0;
}

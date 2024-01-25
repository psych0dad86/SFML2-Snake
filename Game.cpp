#include "Game.hpp"


Game::Game()
{
	m_window = std::make_unique<Window>();
	this->m_numBlocks = 20;
	this->UpdateBlocksize();
	m_textBox = std::make_unique<Textbox>(5, m_blockSize / 2, GetStrartPosition(),
		sf::Vector2f(0, 0));
	m_world = std::make_unique<World>(m_blockSize, m_numBlocks, GetStrartPosition());
	m_snake = std::make_unique<Snake>(m_blockSize, GetStrartPosition());
	m_Timer.restart();
	m_elapsedTime = 0.0f;
	keypressed = false;
	m_textBox->Add("Score: ", "0");
}

Game::~Game()
{
	std::cout << "Game wurde Beendet" << std::endl;
}

void Game::HandleInput()
{

	if (keypressed == false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_snake->GetSnakeDirection() != Direction::Down)
		{
			m_snake->SetDirection(Direction::Up);
			keypressed = true;

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_snake->GetSnakeDirection() != Direction::Up)
		{
			m_snake->SetDirection(Direction::Down);
			keypressed = true;


		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_snake->GetSnakeDirection() != Direction::Right)
		{
			m_snake->SetDirection(Direction::Left);
			keypressed = true;


		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snake->GetSnakeDirection() != Direction::Left)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snake->GetSnakeDirection() != Direction::None)
			{
				m_snake->SetDirection(Direction::Right);
				keypressed = true;



			}
		}
	}


}

void Game::Update()
{
	m_window->Update();
	this->UpdateBlocksize();
	float timestep = 1.0f / m_snake->GetSpeed();
	if (m_elapsedTime >= timestep)
	{
		m_snake->Tick(m_numBlocks);
		if (this->FruitEat() == true)
		{
			m_world->CreateFruit(m_snake->GetSnakeAdress());
			m_snake->recivePoints();
			m_snake->SpeedUP();
			m_snake->SnakeGrow();
		}
		m_elapsedTime -= timestep;
		keypressed = false;
	}

	m_world->Update(m_blockSize, m_numBlocks, GetStrartPosition());
	m_snake->Update(m_blockSize, GetStrartPosition());
	m_textBox->Setup(5, m_blockSize / 2, GetStrartPosition(),
		sf::Vector2f(0, 0));
	m_textBox->Add("Score: ", m_snake->GetPoints());




}

void Game::Render()
{
	m_window->startDraw();

	m_world->Render(m_window->ReturnRenderWindow());
	m_snake->Render(m_window->ReturnRenderWindow());
	m_textBox->Render(m_window->ReturnRenderWindow());


	m_window->endDraw();
}

void Game::UpdateBlocksize()
{

	m_blockSize = static_cast<float>(m_window->GetWindowSize().y) / static_cast<float>(m_numBlocks);
}

int Game::GetStrartPosition()
{

	return static_cast<int>((m_window->GetWindowSize().x - m_window->GetWindowSize().y) / 2 / m_blockSize);

}

void Game::RestartTimer()
{
	m_elapsedTime += m_Timer.restart().asSeconds();
}


std::unique_ptr<Window>& Game::GetWindow()
{
	return m_window;
}

void Game::GameOver()
{
	bool keyWasPressed = false;
	if (m_snake->CheckCollision(m_numBlocks) == true)
	{
		if (m_snake->GetLives() <= 0)
		{
			this->Death();
			std::cout << "Game Over" << std::endl;
			m_textBox->EndSetUP(m_numBlocks, m_blockSize, sf::Vector2i(GetStrartPosition(), 0));
			do
			{
				this->Render();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					m_window->CloseWindow();
					keyWasPressed = true;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					m_snake->ResetLivePoints();
					m_snake->Reset();
					keyWasPressed = true;
				}
				Sleep(250);
			} while (keyWasPressed == false);
		}
		else if (m_snake->GetLives() != 0)
		{
			this->Death();
			m_snake->Reset();
		}

	}




}

void Game::Death()
{
	for (int i = 0; i < 10; i++)
	{
		m_window->startDraw();
		m_world->Render(m_window->ReturnRenderWindow());
		m_snake->SnakeDeath(m_window->ReturnRenderWindow());
		m_window->endDraw();
	}

}

bool Game::FruitEat()
{
	const auto& head = m_snake->GetSnakeAdress()[0];
	if (head.x == m_world->GetFruitPositon().x &&
		head.y == m_world->GetFruitPositon().y)
	{
		return true;
	}
	return false;
}

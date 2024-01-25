#include "Window.hpp"


Window::Window()
{
	std::cout << "Erster Konstruktor wurde erstellt" << std::endl;
	Setup("My First Window", sf::Vector2u(800, 600));

}

Window::~Window()
{
	Destroy();
	std::cout << "Fenster wurde geschlossen" << std::endl;
}

void Window::Setup(const std::string s_window_title, const sf::Vector2u v2u_window_size)
{
	m_window_size = v2u_window_size;
	m_window_title = s_window_title;
	m_fullscreen = false;

	Create();

}



void Window::Update()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
		{
			m_window.close();
			m_isOpen = false;
		}
		else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::F5)
		{
			std::cout << "F5 wurde ausgelöst" << std::endl;
			this->isFullscreen();

		}
	}
	m_window.setFramerateLimit(60);

}

void Window::Create()
{
	auto style = (m_fullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.create(sf::VideoMode(m_window_size.x, m_window_size.y), m_window_title, style);
	m_isOpen = true;
	std::cout << "Fenster wurde Erstellt" << std::endl;
}

void Window::Destroy()
{
	m_window.close();
}



void Window::startDraw()
{
	m_window.clear(sf::Color::Black);
}

void Window::Draw(sf::Drawable& handle)
{
}

void Window::endDraw()
{
	m_window.display();
}

sf::RenderWindow& Window::ReturnRenderWindow()
{
	return m_window;
}

sf::Vector2u Window::GetWindowSize()
{
	return m_window_size;
}

void Window::isFullscreen()
{
	m_fullscreen = !m_fullscreen;
	if (m_fullscreen)
	{
		m_window_size.x = sf::VideoMode::getDesktopMode().width;
		m_window_size.y = sf::VideoMode::getDesktopMode().height;

	}
	else
	{
		m_window_size.x = 800;
		m_window_size.y = 600;
	}
	Destroy();
	Create();
}

bool Window::isOpen()
{
	return m_isOpen;
}

void Window::CloseWindow()
{
	m_isOpen = false;
}


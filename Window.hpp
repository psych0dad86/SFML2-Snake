#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <iostream>
#include <Windows.h>
#include <random>

class Window
{
public:
	Window();
	~Window();

	void Setup(const std::string s_window_title, sf::Vector2u v_window_size);

	void Update();
	void Create();
	void Destroy();

	void startDraw();
	void Draw(sf::Drawable& handle);
	void endDraw();

	sf::RenderWindow& ReturnRenderWindow();

	sf::Vector2u GetWindowSize();

	void isFullscreen();
	bool isOpen();
	void CloseWindow();


private:
	sf::RenderWindow m_window;
	sf::Vector2u m_window_size;
	std::string m_window_title;

	bool m_fullscreen;


	bool m_isOpen;


};




#pragma once
#include "Window.hpp"
class Textbox
{
public:
	Textbox();
	Textbox(int l_visible, int l_charSize,
		int l_width, sf::Vector2f l_screenPos);
	~Textbox();

	void Setup(int l_visible, int l_charSize,
		int l_width, sf::Vector2f l_screenPos);
	void Add(std::string l_message, std::string l_message_score);
	void EndSetUP(unsigned int l_numblock, float l_blocksize, sf::Vector2i l_startposition);

	void Render(sf::RenderWindow& l_window);

private:
	std::string m_messages;
	std::string m_score;
	int m_numVisible;

	sf::RectangleShape m_backdrop;
	sf::Font m_font;
	sf::Text m_content;
};

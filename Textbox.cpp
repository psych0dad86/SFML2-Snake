#include "Textbox.hpp"
Textbox::Textbox()
{
	Setup(5, 20, 200, sf::Vector2f(0, 0));
}

Textbox::Textbox(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos)
{
	Setup(l_visible, l_charSize, l_width, l_screenPos);
}

Textbox::~Textbox()
{
}

void Textbox::Setup(int l_visible, int l_charSize, int  l_width, sf::Vector2f l_screenPos)
{
	sf::Vector2f l_offset(2.0f, 2.0f);
	m_font.loadFromFile("arial.ttf");
	m_content.setFont(m_font);
	//m_content.setString("");
	m_content.setCharacterSize(l_charSize);
	m_content.setFillColor(sf::Color::White);
	m_content.setPosition(l_screenPos + l_offset);

	m_backdrop.setSize(sf::Vector2f(l_width, (l_visible * (l_charSize * 1.2f))));
	m_backdrop.setFillColor(sf::Color(90, 90, 90, 90));
	m_backdrop.setPosition(l_screenPos);
}

void Textbox::Add(std::string l_message, std::string l_message_score)
{
	m_messages = l_message;
	m_score = l_message_score;
}


void Textbox::EndSetUP(unsigned int l_numblock, float l_blocksize, sf::Vector2i l_startposition)
{
	sf::Vector2f l_offset((l_startposition.x + 2) * l_blocksize, (l_startposition.x + 2) * l_blocksize);
	m_messages = "Drücke Enter um ein neues Spiel zu Spielen\n\nDrücke Escape um das Spiel zu beenden\n\nDein Score war: ";
	m_font.loadFromFile("arial.ttf");
	m_content.setFont(m_font);

	m_content.setCharacterSize(l_blocksize * 0.8);
	m_content.setFillColor(sf::Color::Red);
	m_content.setPosition(l_offset);

	m_backdrop.setSize(sf::Vector2f(l_numblock * l_blocksize, (100 * ((l_blocksize / 2) * 1.2f))));
	m_backdrop.setFillColor(sf::Color::Black);
	m_backdrop.setPosition(l_startposition.x * l_blocksize, l_startposition.y);
}

void Textbox::Render(sf::RenderWindow& l_window)
{
	std::string l_messages = m_messages + m_score;
	m_content.setString(l_messages);
	l_window.draw(m_backdrop);
	l_window.draw(m_content);
}

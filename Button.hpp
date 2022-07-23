#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/String.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

class Button{
public:
	Button(const sf::Vector2f& pos_, const sf::Vector2f& size_, const sf::Color& col_, const std::string& s) : 
		rec(size_)
	{
		rec.setOutlineColor(col_);
		rec.setOutlineThickness(2.);
		rec.setPosition(pos_);
		rec.setFillColor(sf::Color::Black);

		if (font.loadFromFile("/usr/share/fonts/truetype/msttcorefonts/arial.ttf"))
			std::cout << "Font loaded correctly" << std::endl;

		text.setFont(font);
		text.setString(s);
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::White);
		text.setStyle(sf::Text::Regular);
		text.setPosition(pos_);
	}

	void draw(sf::RenderWindow& w);
	
	bool isClicked(const sf::RenderWindow& w) const;
	
private: 
	sf::RectangleShape rec;
	sf::Font font;
	sf::Text text; 
	bool isPointed(const sf::RenderWindow& w) const;
};

#endif

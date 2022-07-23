#include "Button.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>

void Button::draw(sf::RenderWindow &w) 
{
	if (isPointed(w))
	{
		rec.setFillColor(sf::Color::White);
		text.setFillColor(sf::Color::Black);
	}
	else 
	{
		rec.setFillColor(sf::Color::Black);
		text.setFillColor(sf::Color::White);
	}

	if (isClicked(w))
	{
		rec.setFillColor(sf::Color::Black);
		text.setFillColor(sf::Color::White);
	}
	w.draw(rec);
	w.draw(text);
}

bool Button::isClicked(const sf::RenderWindow& w) const
{
	if(isPointed(w) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		return true;
	else 
		return false;
}

bool Button::isPointed(const sf::RenderWindow& w) const
{
	if (rec.getPosition().x < sf::Mouse::getPosition(w).x &&
		rec.getPosition().x + rec.getSize().x > sf::Mouse::getPosition(w).x &&
		rec.getPosition().y < sf::Mouse::getPosition(w).y &&
		rec.getPosition().y + rec.getSize().y > sf::Mouse::getPosition(w).y)
		return true;
	else 
		return false;
}
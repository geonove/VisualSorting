#include "BubbleSort.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <random>
#include <iostream>

void BubbleSort::oneStep()
{
	//std::cout << "=== Performing one step ===" << std::endl;

	if (current == counter - 1)	
	{
		counter--;
		current = 0;
	}
	
	if (!isSorted && vec[current].getSize().x > vec[current + 1].getSize().x)
	{
		// Swap
		sf::Vector2f temp_size = vec[current].getSize();
		vec[current].setSize(vec[current + 1].getSize());
		vec[current + 1].setSize(temp_size);
	}

	current++;

	if(isSorted) 
	{
		counter = vec.size();
		current = 0;		
		//std::cout << "=== Sorted! ===" << std::endl;
	}
}

void BubbleSort::draw(sf::RenderWindow &window, bool start)
{	
	if (start)
		vec[current].setFillColor(sf::Color::Red);

	for (const auto& el : vec)
		window.draw(el);
	vec[current].setFillColor(sf::Color::White);
} 

void BubbleSort::shuffle(const sf::RenderWindow& window)
{
	//std::cout << "=== Shuffling ===" << std::endl;
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(vec.begin(), vec.end(), g);
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i].setPosition(sf::Vector2f(rec_size.x * i, window.getSize().x));					
	}

	isSorted = false;
	counter = vec.size();
	current = 0;
}

bool BubbleSort::is_Sorted()  
	{
		isSorted = true;

		for (size_t i = 0; i < vec.size()-1; i++) 
		{
			if (vec[i].getSize().x > vec[i + 1].getSize().x)
				return isSorted = false;
		}	
	
		return isSorted;
	}
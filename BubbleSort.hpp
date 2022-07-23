#ifndef _BUBBBLE_SORT_HPP_
#define _BUBBBLE_SORT_HPP_

#include <SFML/Graphics.hpp>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstddef>
#include <vector>
#include <iostream>

class BubbleSort
{
public:
	BubbleSort(const size_t N, const float window_width) : counter(N)
	{
		vec.reserve(N);
		for (int i = 0; i < N; i++)
		{
			rec_size.y = i * int(window_width / N);
			rec_size.x = window_width / float(N);
			vec.push_back(sf::RectangleShape(sf::Vector2f(rec_size.y, rec_size.x)));
			vec[i].rotate(270);
			vec[i].setPosition(sf::Vector2f(rec_size.x * i, window_width));
			vec[i].setFillColor(sf::Color::White);
		}	
	}
	
	void oneStep();
	void draw(sf::RenderWindow& window, bool start);
	void shuffle(const sf::RenderWindow& window);
	bool is_Sorted();
		
private:
	std::vector<sf::RectangleShape> vec;	
	// Number of comparisons
	unsigned int comparisons = 0;
	// Boolean to indicate if vector is sorted or not
	bool isSorted = true;
	// Index of the element on which to perform one step of the sorted
	size_t current = 0;
	// Number of elements that still need to be sorted
	size_t counter;
	// Rectangle size
	sf::Vector2f rec_size;

};

#endif

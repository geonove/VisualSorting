#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <type_traits>
#include <vector>
#include <random>
#include <iostream>

#include "Button.hpp"

#include "BubbleSort.hpp"
void bubble_sort(std::vector<sf::RectangleShape>& v, sf::RenderWindow& w);

void Bsort(std::vector<sf::RectangleShape>& v, sf::RenderWindow& w);


int main()
{
  const unsigned int window_width = 400;
  const unsigned int window_height = 500;

	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Visual Sorting");
  window.setFramerateLimit(60);  
  const size_t N = 50;

	BubbleSort bubble_sort(N, window.getSize().x);
	Button shuffle_button(sf::Vector2f(0, int(window_width)), sf::Vector2f(int(window_width / 2), int(window_width / 4)), sf::Color::White, "Shuffle");	
	Button start_button(sf::Vector2f(int(window_width / 2), int(window_width)), sf::Vector2f(int(window_width / 2), int(window_width / 4)), sf::Color::White, "Start");

  bool start = false;
	// GAME LOOP 
	while(window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
      if (start_button.isClicked(window))
				  start = true;
			if (shuffle_button.isClicked(window)) 
      {
				bubble_sort.shuffle(window);
        start = false;
      }
    }
    // Draw
    if (start)
      bubble_sort.oneStep();

    if (bubble_sort.is_Sorted() && start) {
      bubble_sort.oneStep();
      start = false;
    }

		window.clear();
		bubble_sort.draw(window, start);
		shuffle_button.draw(window);
		start_button.draw(window);
    window.display();
  }
  return 0;
}

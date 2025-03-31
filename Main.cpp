#include <iostream>
#include <SFML/Graphics.hpp>
#include "Snake.h";

int main()
{
	sf::Vector2f windowSize(800, 600);
	sf::Vector2f segmentSize(20, 20);
	sf::Color segmentColor(150, 150, 150, 255);
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Snake");
	sf::Clock clock;
	float moveDelay = 0.2f;
	sf::Vector2f moveDirection(1, 0);
	
	while (window.isOpen())
	{
		window.clear();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		sf::RectangleShape segment(segmentSize);
		sf::Vector2f segPos(windowSize.x / 2 - segment.getSize().x / 2, 
			windowSize.y / 2 - segment.getSize().y / 2);
		segment.setPosition(segPos);
		segment.setFillColor(segmentColor);
		window.draw(segment);

		window.display();
	}
	return 0;
}
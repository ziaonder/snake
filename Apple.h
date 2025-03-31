#pragma once
#include <SFML/Graphics.hpp>

class Apple
{
public:
	Apple(sf::Vector2f position, sf::Vector2f size);
	sf::Vector2f position, appleSize;
	void draw(sf::RenderWindow& window);
};


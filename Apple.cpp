#include "Apple.h"

Apple::Apple(sf::Vector2f position, sf::Vector2f size) {
	this->position = position;
	appleSize = size;
}

void Apple::draw(sf::RenderWindow& window) {
	sf::RectangleShape apple(appleSize);
	apple.setPosition(position);
	apple.setFillColor(sf::Color(17, 189, 134, 255));
	apple.setOutlineColor(sf::Color::Magenta);
	apple.setOutlineThickness(1.f);
	window.draw(apple);
}
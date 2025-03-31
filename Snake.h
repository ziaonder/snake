#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Apple.h";

struct Segment
{
	sf::Vector2f position, previousPosition, nextPosition;
};

class Snake
{
private:
    std::vector<Segment> segments;
	sf::Vector2f segmentSize;
    sf::Vector2f headPos;

public:
    bool hasSelfCollided;
    Snake(int count, sf::Vector2f segmentSize, sf::Vector2f center);
    void move(sf::Vector2f moveDirection, sf::Vector2f windowSize);
    void grow();
    void draw(sf::RenderWindow& window, sf::Color color);
    void eatApple(std::vector<Apple>& apples);
};


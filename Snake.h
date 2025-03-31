#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

struct Segment
{
	sf::Vector2f position, nextPosition, segmentSize;
};

class Snake
{
private:
    std::vector<Segment> segments;
    float segmentSize;
	sf::Vector2f moveDirection;

public:
    Snake(float size) {
		moveDirection = sf::Vector2f(1, 0);
		segmentSize = size;
        for (int i = 0; i < size; i++) {
			segments.push_back(Segment());
			segments[i].position = sf::Vector2f(i * , 0);
			segments[i].nextPosition = sf::Vector2f(0, 0);
        }
    };
    void move();
    void grow();
    void draw(sf::RenderWindow& window);
};


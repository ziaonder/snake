#include "Snake.h"
#include <iostream>

bool checkSelfCollision(const std::vector<Segment> &segments);

Snake::Snake(int count, sf::Vector2f segmentSize, sf::Vector2f center) {
	this->segmentSize = segmentSize;
	for (int i = 0; i < count; i++) {
		segments.push_back(Segment());
		segments[i].position = sf::Vector2f(center.x + i * -segmentSize.x, center.y);
		if (i == 0)
			segments[i].nextPosition = sf::Vector2f(0, 0);
		else
			segments[i].nextPosition = segments[i - 1].position;
	}
};

void Snake::move(sf::Vector2f moveDirection, sf::Vector2f windowSize) {
	for (int i = 0; i < segments.size(); i++) {
		if (i == 0) {
			segments[i].position += moveDirection * segmentSize.x;
			
			if (segments[i].position.x < 0) 
				segments[i].position.x = windowSize.x - segmentSize.x;
			if (segments[i].position.x > windowSize.x)
				segments[i].position.x = 0;
			if (segments[i].position.y < 0)
				segments[i].position.y = windowSize.y - segmentSize.y;
			if (segments[i].position.y > windowSize.y)
				segments[i].position.y = 0;
		}
		else {
			segments[i].previousPosition = segments[i].position;
			segments[i].position = segments[i].nextPosition;
			segments[i].nextPosition = segments[i - 1].position;
		}
	}
	
	hasSelfCollided = checkSelfCollision(segments);
};

void Snake::draw(sf::RenderWindow& window, sf::Color color) {
	for (int i = 0; i < segments.size(); i++) {
		sf::RectangleShape segment(segmentSize);
		segment.setPosition(segments[i].position);
		if (i == 0)
			segment.setFillColor(sf::Color(190, 180, 17, 255));
		else
			segment.setFillColor(color);

		segment.setOutlineColor(sf::Color::Black);
		segment.setOutlineThickness(2.f);
		window.draw(segment);
	}
};

void Snake::eatApple(std::vector<Apple>& apples) {
	for (int i = 0; i < apples.size(); i++) {
		if (segments[0].position == apples[i].position) {
			grow();
			apples.erase(apples.begin() + i);
			break;
		}
	}
}

void Snake::grow() {
	segments.push_back(Segment());
	segments[segments.size() - 1].position = segments[segments.size() - 2].previousPosition;
	segments[segments.size() - 1].nextPosition = segments[segments.size() - 2].position;
};

bool checkSelfCollision(const std::vector<Segment> &segments) {
	for (int i = 1; i < segments.size(); i++) {
		if (segments[0].position == segments[i].position) {
			return true;
		}
	}

	return false;
}

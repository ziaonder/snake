#include <iostream>
#include <SFML/Graphics.hpp>
#include "Snake.h";
#include "Apple.h";
#include <random>

int getRandomInt(int min, int max) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(min, max);
	return dist(gen);
}

int main()
{
	sf::Vector2f windowSize(800, 600);
	sf::Vector2f segmentSize(20, 20);
	sf::Color segmentColor(150, 150, 150, 255), redColor(194, 21, 21, 255);
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Snake");
	sf::Clock clockMove, clockApple;
	float moveDelay = .1f;
	sf::Vector2f moveDirection(1, 0);
	sf::Vector2f center(windowSize.x / 2, windowSize.y / 2);
	Snake snake(5, segmentSize, center);
	sf::Vector2f right(1, 0), left(-1, 0), up(0, -1), down(0, 1);
	bool isEnded = false;
	std::vector<Apple> apples;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		if (isEnded) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				isEnded = false;
				snake = Snake(5, segmentSize, center);
				moveDirection = right;
				apples.clear();
				clockApple.restart();
				clockMove.restart();
			}
		}

		if (snake.hasSelfCollided && !isEnded) {
			window.clear();
			snake.draw(window, redColor);
			window.display();
			std::cout << "Game Over!" << std::endl;
			isEnded = true;
		}
		else if(!isEnded) {
			window.clear();

			if (clockMove.getElapsedTime().asSeconds() >= moveDelay) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && moveDirection != right)
					moveDirection = left;
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && moveDirection != left)
					moveDirection = right;
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && moveDirection != down)
					moveDirection = up;
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && moveDirection != up)
					moveDirection = down;

				snake.move(moveDirection, windowSize);
				snake.eatApple(apples);
				clockMove.restart();
			}

			for (Apple apple : apples) {
				apple.draw(window);
			}

			snake.draw(window, segmentColor);
			window.display();
		}

		if (clockApple.getElapsedTime().asSeconds() >= 3) {
			int posX = getRandomInt(0, (windowSize.x - segmentSize.x) / segmentSize.x);
			int posY = getRandomInt(0, (windowSize.y - segmentSize.y) / segmentSize.y);
			sf::Vector2f position(posX, posY);
			position *= segmentSize.x;
			Apple apple(position, segmentSize);
			apples.push_back(apple);
			clockApple.restart();
		}
	}

	return 0;
}
#include "Game.hpp"
#include <stdexcept>
#include <iostream>


int main()
{
	unsigned int lv_width = 0, lv_length = 0;

	std::cout << "Please enter the width and length of window screen respectively in that order with space in between: ";
	std::cin >> lv_width >> lv_length;

	Game::SnakeGame lv_game("Snake Game", sf::Vector2u(lv_width, lv_length), 1);

	try {
		lv_game.MainGameLoop();
	}

	catch (const std::out_of_range& error) {
		std::cout << error.what() << std::endl;
	}
	

	return 0;
}
#include "Window.hpp"
#include <SFML/Window/Keyboard.hpp>


void MoveRight(sf::Transformable& l_transformable) {
	l_transformable.move(sf::Vector2f(0.2f, 0.f));
}
void MoveLeft(sf::Transformable& l_transformable)
{
	l_transformable.move(sf::Vector2f(-0.2f,0.f));
}

void MoveUp(sf::Transformable& l_transformable)
{
	l_transformable.move(sf::Vector2f(0.f, -0.2f));
}

void MoveDown(sf::Transformable& l_transformable)
{
	l_transformable.move(sf::Vector2f(0.f, 0.2f));
}

sf::Keyboard::Key DetectArrowKey()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		return sf::Keyboard::Right;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		return sf::Keyboard::Left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		return sf::Keyboard::Up;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		return sf::Keyboard::Down;
	}
}

int main()
{
	Window lv_window("Snake", sf::Vector2u(600, 600));

	sf::Texture texture;
	texture.loadFromFile("C:/Users/farhan/Desktop/SFML_stuff/Green-square.png", sf::IntRect(0, 0, 10, 10));
	sf::Sprite sprite(texture);

	while (!lv_window.IsDone()) {
		lv_window.Update();
		lv_window.BeginDraw();
		
		switch (DetectArrowKey()) {
			case sf::Keyboard::Right:
				MoveRight(sprite);
				break;
			case sf::Keyboard::Left:
				MoveLeft(sprite);
				break;
			case sf::Keyboard::Up:
				MoveUp(sprite);
				break;
			case sf::Keyboard::Down:
				MoveDown(sprite);
				break;
		}

		lv_window.Draw(sprite);
		lv_window.EndDraw();
	}

	return 0;
}
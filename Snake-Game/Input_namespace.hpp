#include "SFML/Graphics.hpp"
#include "SFML/Window/Keyboard.hpp"


namespace Input
{

	void MoveRight(sf::Transformable& l_transformable);
	void MoveLeft(sf::Transformable& l_transformable);
	void MoveUp(sf::Transformable& l_transformable);
	void MoveDown(sf::Transformable& l_transformable);

	sf::Keyboard::Key DetectArrowKey();
}
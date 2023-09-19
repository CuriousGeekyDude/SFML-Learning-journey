#ifndef  INPUT_NAMESPACE_HPP
#define INPUT_NAMESPACE_HPP



#include "SFML/Graphics.hpp"
#include "SFML/Window/Keyboard.hpp"


namespace Input
{
	namespace Keyboard
	{
		typedef sf::Keyboard Key;

		void MoveRight(sf::Transformable& l_transformable);
		void MoveLeft(sf::Transformable& l_transformable);
		void MoveUp(sf::Transformable& l_transformable);
		void MoveDown(sf::Transformable& l_transformable);

		sf::Keyboard::Key DetectArrowKey();

		void HandleKeyboardInput(sf::Transformable& l_transformable);
	}
}

#endif
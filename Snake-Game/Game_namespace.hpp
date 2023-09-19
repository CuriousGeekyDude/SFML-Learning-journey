#ifndef GAME_NAMESPACE_HPP
#define GAME_NAMESPACE_HPP

#include "SFML/Graphics.hpp"
#include "SFML/Window/Keyboard.hpp"

namespace Game
{
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


	namespace Objects
	{
		class Apple
		{
		public:
			Apple(const sf::Texture& l_textureApple) :m_textureApple(l_textureApple) { SetRandomPosition(); }

		private:
			void SetRandomPosition();

			sf::Sprite m_textureApple;
			
		};
	}
}



#endif

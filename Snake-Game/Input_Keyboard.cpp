#include "Game_namespace.hpp"

namespace Game{

	namespace Input
	{
		namespace Keyboard {

			void MoveRight(sf::Transformable& l_transformable) {
				l_transformable.move(sf::Vector2f(0.2f, 0.f));
			}

			void MoveLeft(sf::Transformable& l_transformable)
			{
				l_transformable.move(sf::Vector2f(-0.2f, 0.f));
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
				if (sf::Keyboard::isKeyPressed(Key::Right)) {
					return Key::Right;
				}
				else if (sf::Keyboard::isKeyPressed(Key::Left)) {
					return Key::Left;
				}
				else if (sf::Keyboard::isKeyPressed(Key::Up)) {
					return Key::Up;
				}
				else if (sf::Keyboard::isKeyPressed(Key::Down)) {
					return Key::Down;
				}
			}

			void HandleKeyboardInput(sf::Transformable& l_transformable)
			{
				switch (DetectArrowKey()) {
				case Key::Right:
					MoveRight(l_transformable);
					break;
				case Key::Left:
					MoveLeft(l_transformable);
					break;
				case Key::Up:
					MoveUp(l_transformable);
					break;
				case Key::Down:
					MoveDown(l_transformable);
					break;
				}
			}

		}
	}
}
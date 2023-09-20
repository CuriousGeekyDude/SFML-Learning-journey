#ifndef GAME_NAMESPACE_HPP
#define GAME_NAMESPACE_HPP

#include "SFML/Graphics.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "Random_generator.hpp"
#include <vector>
#include <string>

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

		class TextureContainer
		{
		public:
			TextureContainer(const std::string& l_pathApple, const std::string& l_pathSquare);

			sf::Texture& operator[](const int l_index);
			const sf::Texture& operator[](const int l_index) const;


		private:
			std::vector<sf::Texture> m_textureContainer;
		};

		class Apple
		{
		public:
			Apple(const sf::Texture& l_textureApple, Random_generator::Float& l_randomFloat) :m_apple(l_textureApple), m_randomFloat(l_randomFloat) { SetRandomPosition(); }

			sf::Sprite& GetAppleSprite() { return m_apple; }

			void UpdatePosition();

		private:
			void SetRandomPosition();

			sf::Sprite m_apple;
			Random_generator::Float& m_randomFloat;
		};

		class GreenSquare
		{
		public:


			GreenSquare(const sf::Texture& l_squareTexture, const bool l_isHead) : m_squareSprite(l_squareTexture), m_position(m_squareSprite.getPosition()), m_isHead(l_isHead) {}


			




			enum class RelativePosition	//Relative position with respect to the green square that it is attached to
			{
				Up,
				Down,
				Right,
				Left,
				NotApplicable
			};
			
			enum class MovementDirection
			{
				MoveUp,
				MoveDown,
				MoveRight,
				MoveLeft,
				Still
			};

		private:
			sf::Sprite m_squareSprite;
			sf::Vector2f m_position;
			bool m_isHead;	//To know whether the square is at the head of the snake 
			RelativePosition m_relativePosition{RelativePosition::NotApplicable};
			MovementDirection m_movementDirection{MovementDirection::Still};

		};


	}
}



#endif

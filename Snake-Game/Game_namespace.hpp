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
		typedef sf::Keyboard Key;

		namespace Keyboard
		{


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


			//l_squareBefore: This is the square that the current new square is attached to

			GreenSquare(const sf::Texture& l_squareTexture, const bool l_isHead, GreenSquare* l_squareBefore) 
		    :m_squareBefore(l_squareBefore), m_squareSprite(l_squareTexture), m_isHead(l_isHead)
			{
				InitializePosition(); UpdateRelativePosition(); UpdateMovementDirection();
			}



			

			void Move();

			RelativePosition GetRelativePosition() const { return m_relativePosition; }
			MovementDirection GetMovementDirection() const { return m_movementDirection; }
			sf::Vector2f GetPosition() const { return m_position; }
			sf::Sprite& GetSquareSprite() { return m_squareSprite; };

			void SetMovementDirection_Still() { m_movementDirection = MovementDirection::Still; }

		private:

			void UpdateRelativePosition();	//NOT TESTED
			void UpdateMovementDirection();	//NOT TESTED
			void InitializePosition();
			void UpdatePosition() { m_position = m_squareSprite.getPosition(); }

			void Set_RelativePosUpMovementDir();
			void Set_RelativePosDownMovementDir();
			void Set_RelativePosRightMovementDir();
			void Set_RelativePosLeftMovementDir();

			GreenSquare* m_squareBefore;
			sf::Sprite m_squareSprite;
			sf::Vector2f m_position{sf::Vector2f(0.f,0.f)};
			bool m_isHead = true;	//To know whether the square is at the head of the snake 
			RelativePosition m_relativePosition{RelativePosition::NotApplicable};
			MovementDirection m_movementDirection{MovementDirection::Still};

		};


		class Snake
		{
		public:

			Snake(const sf::Texture& l_textureSquare, const int l_lengthOfSnake = 2);


			void Move();

			std::vector<GreenSquare>& GetSquareContainer() { return m_greenSquareContainer; }


		private:
			std::vector<GreenSquare> m_greenSquareContainer;

		};

	}
}



#endif

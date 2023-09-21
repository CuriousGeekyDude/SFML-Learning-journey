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

			GreenSquare(const sf::Texture& l_squareTexture, const bool l_isHead, const GreenSquare& l_squareBefore) 
		    : m_squareSprite(l_squareTexture), m_position(m_squareSprite.getPosition()), m_isHead(l_isHead) 
			{ UpdateRelativePosition(l_squareBefore); UpdateMovementDirection(l_squareBefore); }



			

			void Move(const GreenSquare& l_squareBefore);

			RelativePosition GetRelativePosition() const { return m_relativePosition; }
			MovementDirection GetMovementDirection() const { return m_movementDirection; }
			sf::Vector2f GetPosition() const { return m_position; }


			

		private:

			void UpdateRelativePosition(const GreenSquare& l_squareBefore);	//NOT TESTED
			void UpdateMovementDirection(const GreenSquare& l_squareBefore);	//NOT TESTED

			void Set_RelativePosUpMovementDir(const GreenSquare& l_squareBefore);
			void Set_RelativePosDownMovementDir(const GreenSquare& l_squareBefore);
			void Set_RelativePosRightMovementDir(const GreenSquare& l_squareBefore);
			void Set_RelativePosLeftMovementDir(const GreenSquare& l_squareBefore);


			sf::Sprite m_squareSprite;
			sf::Vector2f m_position{sf::Vector2f(0.f,0.f)};
			bool m_isHead = true;	//To know whether the square is at the head of the snake 
			RelativePosition m_relativePosition{RelativePosition::NotApplicable};
			MovementDirection m_movementDirection{MovementDirection::Still};

		};


	}
}



#endif

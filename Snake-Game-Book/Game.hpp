#pragma once

#include "SFML/Window/Keyboard.hpp"
#include "SFML/Graphics.hpp"
#include "Window.hpp"
#include <vector>



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
			bool HandleKeyboardInput(sf::Transformable& l_transformable);
		}
	}


	namespace GameObjects
	{

		class Apple
		{
		public:
			Apple(const std::vector<sf::RectangleShape>& l_snake, const sf::Vector2u& l_windowSize)
				: m_snake(l_snake), m_windowSize(l_windowSize), m_circle(7.f * sqrtf(2.f)) {
				m_circle.setFillColor(sf::Color::Red);
				UpdateApplePosition();
			}

			void UpdateApplePosition();




			sf::CircleShape GetCircle() const { return m_circle; }


		private:

			unsigned int LowestSnakeSquarePosX();
			unsigned int LowestSnakeSquarePosY();
			unsigned int HighestSnakeSquarePosX();
			unsigned int HighestSnakeSquarePosY();

			sf::Vector2f GetBiggestFreeIntervalX();
			sf::Vector2f GetBiggestFreeIntervalY();

			sf::Vector2f RandomPosition();
			void  AdjustApplePosition();	//Called in UpdateApplePosition() when apple falls out of the window

			const std::vector<sf::RectangleShape>& m_snake;
			sf::CircleShape m_circle;
			const sf::Vector2u& m_windowSize;
		};

		class Snake
		{
		public:

			Snake(const int l_size, const sf::Vector2u& l_windowSize);	

			std::vector<sf::RectangleShape>& GetSnake() { return m_snake; }
			std::vector<sf::RectangleShape>::size_type GetSizeSnake() { return m_sizeSnake; }

			void Move();

			void Extend();

			void CollisionAppleHandler(Apple& l_apple);

		private:
			void InitializeSquare(const sf::Vector2f& l_position);
			void InitializeSnake();

			void CheckCollision();

			bool CheckCollisionApple(const sf::CircleShape& l_apple);

			void WrapAroundBorders();

			std::vector<sf::RectangleShape> m_snake;
			std::vector<sf::RectangleShape>::size_type m_sizeSnake;
			sf::Vector2f m_positionHead;
			sf::Vector2u m_windowSize;
		};

		
	}


	class SnakeGame
	{
	public:
		SnakeGame(const std::string& l_windowTitle, const sf::Vector2u& l_windowSize, const int l_snakeSize)
		: m_window(l_windowTitle, l_windowSize), m_snake(l_snakeSize, m_window.GetWindowSize()), m_apple(m_snake.GetSnake(), m_window.GetWindowSize()) {}


		void MainGameLoop();

	private:
		Window m_window;
		GameObjects::Snake m_snake;
		GameObjects::Apple m_apple;
	};
}
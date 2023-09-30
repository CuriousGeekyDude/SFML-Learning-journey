#include "Game.hpp"
#include <algorithm>

namespace Game
{
	namespace GameObjects
	{
		Snake::Snake(const int l_size, const sf::Vector2u& l_windowSize) 
		: m_sizeSnake(l_size), m_windowSize(l_windowSize)
		{
			if (l_size <= 0) {
				return;
			}
			InitializeSnake();
		}

		void Snake::InitializeSquare(const sf::Vector2f& l_position)
		{
			sf::RectangleShape lv_square(sf::Vector2f(10.f, 10.f));
			lv_square.setFillColor(sf::Color::Green);
			lv_square.setPosition(l_position);

			m_snake.push_back(lv_square);
			m_sizeSnake = m_snake.size();
		}

		void Snake::InitializeSnake()
		{
			int j = 0;
			for (int i = m_sizeSnake - 1; 0 <= i; --i) {
				InitializeSquare(sf::Vector2f((m_sizeSnake - 1 - i) * 10.f + j, 0.f));
				++j;
			}
			std::reverse(m_snake.begin(), m_snake.end());
			m_positionHead = m_snake.at(0).getPosition();
		}


		void Snake::Move()
		{
			if (m_sizeSnake == 0) { return; }
			
			if (Game::Input::Keyboard::HandleKeyboardInput(m_snake.at(0)))
			{
				CheckCollision();
				for (int i = m_sizeSnake - 1; m_sizeSnake > 1 && i > 0; --i) {
					m_snake.at(i).setPosition(m_snake.at(i - 1).getPosition());
				}

				if (m_sizeSnake > 1) {
					m_snake.at(1).setPosition(m_positionHead);
				}
				m_positionHead = m_snake.at(0).getPosition();
				WrapAroundBorders();
			}
			
			
		}


		void Snake::Extend()
		{
			if (m_sizeSnake == 0) { return; }
			switch (m_sizeSnake) {
				case 1:
					InitializeSquare(sf::Vector2f(m_snake.at(0).getPosition().x+11.f, m_snake.at(0).getPosition().y));
					break;
				default:
					if (m_snake.at(m_sizeSnake - 1).getPosition().x - m_snake.at(m_sizeSnake - 2).getPosition().x > 0) {
						InitializeSquare(sf::Vector2f(m_snake.at(m_sizeSnake-1).getPosition().x + 11.f, m_snake.at(m_sizeSnake-1).getPosition().y));
					}
					else if (m_snake.at(m_sizeSnake - 1).getPosition().x - m_snake.at(m_sizeSnake - 2).getPosition().x < 0) {
						InitializeSquare(sf::Vector2f(m_snake.at(m_sizeSnake - 1).getPosition().x - 11.f, m_snake.at(m_sizeSnake - 1).getPosition().y));
					}
					else if (m_snake.at(m_sizeSnake - 1).getPosition().y - m_snake.at(m_sizeSnake - 2).getPosition().y < 0) {
						InitializeSquare(sf::Vector2f(m_snake.at(m_sizeSnake - 1).getPosition().x, m_snake.at(m_sizeSnake - 1).getPosition().y - 11.f));
					}
					else if (m_snake.at(m_sizeSnake - 1).getPosition().y - m_snake.at(m_sizeSnake - 2).getPosition().y > 0) {
						InitializeSquare(sf::Vector2f(m_snake.at(m_sizeSnake - 1).getPosition().x, m_snake.at(m_sizeSnake - 1).getPosition().y + 11.f));
					}
			}
		}


		bool Snake::CheckCollisionApple(const sf::CircleShape& l_apple)
		{
			auto lv_deltaX = l_apple.getPosition().x - m_snake.at(0).getPosition().x;
			auto lv_deltaY = l_apple.getPosition().y - m_snake.at(0).getPosition().y;
			
			auto lv_distanceAppleSnake = sqrtf((lv_deltaX * lv_deltaX)+(lv_deltaY * lv_deltaY));

			if (lv_distanceAppleSnake < 15.f) {
				return true;
			}
			else {
				return false;
			}
		}

		void Snake::CollisionAppleHandler(Apple& l_apple)
		{
			if (CheckCollisionApple(l_apple.GetCircle())) {
				Extend();
				l_apple.UpdateApplePosition();
			}
		}

		void Snake::CheckCollision()
		{
			if (m_sizeSnake > 1) {
				auto lv_iterEnd = m_snake.cend();
				auto lv_iterBegin = m_snake.cbegin();
				

				for (auto lv_iter = ++m_snake.begin(); lv_iter != lv_iterEnd; ++lv_iter) {
					if (lv_iter->getPosition() == lv_iterBegin->getPosition()) {
							m_snake.erase(lv_iter, lv_iterEnd);
							m_sizeSnake = m_snake.size();
							break;
					}
				}
			}
		}


		void Snake::WrapAroundBorders()
		{
			if (m_positionHead.x >= m_windowSize.x) {
				m_positionHead = sf::Vector2f(0.f, m_snake.at(0).getPosition().y);
			}
			else if (m_positionHead.x <= -10) {
				m_positionHead = sf::Vector2f(m_windowSize.x - 10.f, m_snake.at(0).getPosition().y);
			}
			else if (m_positionHead.y <= -10) {
				m_positionHead = sf::Vector2f(m_snake.at(0).getPosition().x, m_windowSize.y - 10.f);
			}
			else if (m_positionHead.y >= m_windowSize.y) {
				m_positionHead = sf::Vector2f(m_snake.at(0).getPosition().x, 0.f);
			}
			m_snake.at(0).setPosition(m_positionHead);
		}
	}
}
#include "Game.hpp"
#include <algorithm>
#include <cmath>
#include "RandomGenerator.hpp"


namespace Game
{
	namespace GameObjects
	{
		sf::Vector2f Apple::RandomPosition()
		{
			auto lv_minX = GetBiggestFreeIntervalX();
			auto lv_minY = GetBiggestFreeIntervalY();
			float lv_posX = 0.f, lv_posY = 0.f;
			const float lv_radiusCircle = 7.f * sqrtf(2);

			switch (static_cast<int>(lv_minX.y)) {
				case 0:
					lv_posX = RandomGenerator::Float(lv_radiusCircle, lv_minX.x + lv_radiusCircle).Generate();
					break;
				case 1:
					if (lv_minX.x > m_windowSize.y) { lv_posX = m_windowSize.x - 24.f; }
					else {
						lv_posX = RandomGenerator::Float(lv_minX.x, m_windowSize.x).Generate();
					}
					break;
			}

			switch (static_cast<int>(lv_minY.y)) {
				case 0:
					lv_posY = RandomGenerator::Float(lv_radiusCircle, lv_minY.x + lv_radiusCircle).Generate();
					break;
				case 1:
					if (lv_minY.x > m_windowSize.y) { lv_posY = m_windowSize.y - 24.f; }
					else {
						lv_posY = RandomGenerator::Float(lv_minY.x, m_windowSize.y).Generate();
					}
					break;
			}


			return sf::Vector2f(lv_posX, lv_posY);

		}



		void Apple::AdjustApplePosition()
		{
			if (abs(m_circle.getPosition().x - m_windowSize.x) < 8) {
				m_circle.setPosition(sf::Vector2f(m_windowSize.x - 24.f, m_circle.getPosition().y));
			}

			if (abs(m_circle.getPosition().y - (float)m_windowSize.y) < 8) {
				m_circle.setPosition(sf::Vector2f(m_circle.getPosition().x, m_windowSize.y - 24.f));
			}

		}

		void Apple::UpdateApplePosition()
		{
			m_circle.setPosition(RandomPosition());
			AdjustApplePosition();

		}

		unsigned int Apple::HighestSnakeSquarePosX()
		{
			auto lv_sizeSnake = m_snake.size();
			std::vector<unsigned int> lv_posX;

			for (int i = 0; i < lv_sizeSnake; ++i) {
				lv_posX.push_back(m_snake.at(i).getPosition().x);
			}

			return static_cast<unsigned int>(*std::max_element(lv_posX.begin(), lv_posX.end()));
		}

		unsigned int Apple::HighestSnakeSquarePosY()
		{
			auto lv_sizeSnake = m_snake.size();
			std::vector<unsigned int> lv_posY;

			for (int i = 0; i < lv_sizeSnake; ++i) {
				lv_posY.push_back(m_snake.at(i).getPosition().y);
			}
			
			return static_cast<unsigned int>(*std::max_element(lv_posY.begin(), lv_posY.end()));
		}

		unsigned int Apple::LowestSnakeSquarePosY()
		{
			auto lv_sizeSnake = m_snake.size();
			std::vector<unsigned int> lv_posY;

			for (int i = 0; i < lv_sizeSnake; ++i) {
				lv_posY.push_back(m_snake.at(i).getPosition().y);
			}

			return static_cast<unsigned int>(*std::min_element(lv_posY.begin(), lv_posY.end()));
		}

		unsigned int Apple::LowestSnakeSquarePosX()
		{
			auto lv_sizeSnake = m_snake.size();
			std::vector<unsigned int> lv_posX;

			for (int i = 0; i < lv_sizeSnake; ++i) {
				lv_posX.push_back(m_snake.at(i).getPosition().x);
			}

			return static_cast<unsigned int>(*std::min_element(lv_posX.begin(), lv_posX.end()));
		}

		sf::Vector2f Apple::GetBiggestFreeIntervalX()
		{
			auto lv_minPosX = LowestSnakeSquarePosX();
			auto lv_maxPosX = HighestSnakeSquarePosX();
			auto lv_windowSizeX = m_windowSize.x;
			
			if (lv_minPosX < lv_windowSizeX - lv_maxPosX) {
				return sf::Vector2f(lv_maxPosX, 1);
			}
			else {
				return sf::Vector2f(lv_minPosX, 0);
			}
		}

		sf::Vector2f Apple::GetBiggestFreeIntervalY()
		{
			auto lv_minPosY = LowestSnakeSquarePosY();
			auto lv_maxPosY = HighestSnakeSquarePosY();
			auto lv_windowSizeY = m_windowSize.y;

			if (lv_minPosY < lv_windowSizeY - lv_maxPosY) {
				return sf::Vector2f(lv_maxPosY, 1);
			}
			else {
				return sf::Vector2f(lv_minPosY, 0);
			}
		}
	}
}
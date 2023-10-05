#include "Game_namespace.hpp"

namespace Game
{
	namespace Objects
	{
		Snake::Snake(const sf::Texture& l_textureSquare, const int l_lengthOfSnake)
		{
			for (int i = 0; i < l_lengthOfSnake; ++i) {
				if (i == 0) {
					m_greenSquareContainer.push_back(GreenSquare(l_textureSquare, true, nullptr));
				}
				else {
					m_greenSquareContainer.push_back(GreenSquare(l_textureSquare, false, &m_greenSquareContainer[i - 1]));
				}
			}
		}


		void Snake::Move()
		{
			auto lv_size = m_greenSquareContainer.size();
			for (int i = 0; i < lv_size; ++i) {
				m_greenSquareContainer[i].Move();
			}

			for (int i = 0; i < lv_size; ++i) {
				m_greenSquareContainer[i].SetMovementDirection_Still();
			}
		}
	}
}
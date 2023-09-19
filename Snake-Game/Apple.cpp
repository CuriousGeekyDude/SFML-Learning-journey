#include "Game_namespace.hpp"

namespace Game
{
	namespace Objects
	{

		void Apple::UpdatePosition()
		{
			SetRandomPosition();
		}

		void Apple::SetRandomPosition()
		{
			m_apple.setPosition(sf::Vector2f(m_randomFloat.Generate(), m_randomFloat.Generate()));
		}
	}
}
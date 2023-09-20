#include "Game_namespace.hpp"

namespace Game
{
	namespace Objects
	{
		void GreenSquare::FindRelativePosition(const GreenSquare& l_squareBefore)
		{
			if (m_position.x == l_squareBefore.GetPosition().x) {
				
				if (m_position.y == l_squareBefore.GetPosition().y) {
					throw "1)Two Green squares overlap!";
				}

				if (m_position.y < l_squareBefore.GetPosition().y) {
					m_relativePosition = RelativePosition::Up;	//The positive y-axis is downward
				}
				else {
					m_relativePosition = RelativePosition::Down;	//The negative y-axis is upward
				}

				return;
			}


			if (m_position.y == l_squareBefore.GetPosition().y) {
				if (m_position.x == l_squareBefore.GetPosition().x) {
					throw "2)Two Green squares overlap!";
				}

				if (m_position.x < l_squareBefore.GetPosition().x) {
					m_relativePosition = RelativePosition::Left;
				}
				else {
					m_relativePosition = RelativePosition::Right;
				}
			}
		}
	}
}
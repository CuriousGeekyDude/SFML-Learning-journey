#include "Game_namespace.hpp"

namespace Game
{
	namespace Objects
	{
		void GreenSquare::UpdateRelativePosition(const GreenSquare& l_squareBefore)
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

		void GreenSquare::UpdateMovementDirection(const GreenSquare& l_squareBefore)
		{
			switch (m_relativePosition) {
				case RelativePosition::Up:
					Set_RelativePosUpMovementDir(l_squareBefore);
					break;

				case RelativePosition::Down:
					Set_RelativePosDownMovementDir(l_squareBefore);
					break;

				case RelativePosition::Right:
					Set_RelativePosRightMovementDir(l_squareBefore);
					break;

				case RelativePosition::Left:
					Set_RelativePosLeftMovementDir(l_squareBefore);
					break;
			}
		}



		void GreenSquare::Move(const GreenSquare& l_squareBefore)
		{
			UpdateRelativePosition(l_squareBefore);
			UpdateMovementDirection(l_squareBefore);

			switch (m_movementDirection) {
				case MovementDirection::MoveUp:
					Input::Keyboard::MoveUp(m_squareSprite);
					break;
				case MovementDirection::MoveDown:
					Input::Keyboard::MoveDown(m_squareSprite);
					break;
				case MovementDirection::MoveRight:
					Input::Keyboard::MoveRight(m_squareSprite);
					break;
				case MovementDirection::MoveLeft:
					Input::Keyboard::MoveLeft(m_squareSprite);
					break;
			}
		}



		void GreenSquare::Set_RelativePosUpMovementDir(const GreenSquare& l_squareBefore)
		{
			switch (l_squareBefore.GetMovementDirection()) {
			case MovementDirection::MoveDown:
			case MovementDirection::MoveRight:
			case MovementDirection::MoveLeft:
				m_movementDirection = MovementDirection::MoveDown;
				break;
			}
		}
		void GreenSquare::Set_RelativePosDownMovementDir(const GreenSquare& l_squareBefore)
		{
				switch (l_squareBefore.GetMovementDirection()) {
				case MovementDirection::MoveUp:
				case MovementDirection::MoveRight:
				case MovementDirection::MoveLeft:
					m_movementDirection = MovementDirection::MoveUp;
					break;
				}
		}
		void GreenSquare::Set_RelativePosRightMovementDir(const GreenSquare& l_squareBefore)
		{
			switch (l_squareBefore.GetMovementDirection()) {
			case MovementDirection::MoveLeft:
			case MovementDirection::MoveUp:
			case MovementDirection::MoveDown:
				m_movementDirection = MovementDirection::MoveLeft;
				break;
			}
		}
		void GreenSquare::Set_RelativePosLeftMovementDir(const GreenSquare& l_squareBefore)
		{
			switch (l_squareBefore.GetMovementDirection()) {
			case MovementDirection::MoveUp:
			case MovementDirection::MoveDown:
			case MovementDirection::MoveRight:
				m_movementDirection = MovementDirection::MoveRight;
			}
		}
	}
}
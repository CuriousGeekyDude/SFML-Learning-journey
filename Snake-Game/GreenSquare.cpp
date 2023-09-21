#include "Game_namespace.hpp"

namespace Game
{
	namespace Objects
	{
		void GreenSquare::UpdateRelativePosition()
		{
			if (m_position.x == m_squareBefore.GetPosition().x) {
				
				if (m_position.y == m_squareBefore.GetPosition().y) {
					throw "1)Two Green squares overlap!";
				}

				if (m_position.y < m_squareBefore.GetPosition().y) {
					m_relativePosition = RelativePosition::Up;	//The positive y-axis is downward
				}
				else {
					m_relativePosition = RelativePosition::Down;	//The negative y-axis is upward
				}

				return;
			}


			if (m_position.y == m_squareBefore.GetPosition().y) {
				if (m_position.x == m_squareBefore.GetPosition().x) {
					throw "2)Two Green squares overlap!";
				}

				if (m_position.x < m_squareBefore.GetPosition().x) {
					m_relativePosition = RelativePosition::Left;
				}
				else {
					m_relativePosition = RelativePosition::Right;
				}
			}
		}

		void GreenSquare::UpdateMovementDirection()
		{
			switch (m_relativePosition) {
				case RelativePosition::Up:
					Set_RelativePosUpMovementDir();
					break;

				case RelativePosition::Down:
					Set_RelativePosDownMovementDir();
					break;

				case RelativePosition::Right:
					Set_RelativePosRightMovementDir();
					break;

				case RelativePosition::Left:
					Set_RelativePosLeftMovementDir();
					break;
			}
		}



		void GreenSquare::Move()
		{
			UpdateRelativePosition();
			UpdateMovementDirection();

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



		void GreenSquare::Set_RelativePosUpMovementDir()
		{
			switch (m_squareBefore.GetMovementDirection()) {
			case MovementDirection::MoveDown:
			case MovementDirection::MoveRight:
			case MovementDirection::MoveLeft:
				m_movementDirection = MovementDirection::MoveDown;
				break;
			}
		}
		void GreenSquare::Set_RelativePosDownMovementDir()
		{
				switch (m_squareBefore.GetMovementDirection()) {
				case MovementDirection::MoveUp:
				case MovementDirection::MoveRight:
				case MovementDirection::MoveLeft:
					m_movementDirection = MovementDirection::MoveUp;
					break;
				}
		}
		void GreenSquare::Set_RelativePosRightMovementDir()
		{
			switch (m_squareBefore.GetMovementDirection()) {
			case MovementDirection::MoveLeft:
			case MovementDirection::MoveUp:
			case MovementDirection::MoveDown:
				m_movementDirection = MovementDirection::MoveLeft;
				break;
			}
		}
		void GreenSquare::Set_RelativePosLeftMovementDir()
		{
			switch (m_squareBefore.GetMovementDirection()) {
			case MovementDirection::MoveUp:
			case MovementDirection::MoveDown:
			case MovementDirection::MoveRight:
				m_movementDirection = MovementDirection::MoveRight;
			}
		}
	}
}
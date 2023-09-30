#include "Game.hpp"
#include "SFML/System/Clock.hpp"

namespace Game
{
	void SnakeGame::MainGameLoop()
	{
		const auto lv_frameRate = 1 / 30.f;
		sf::Clock lv_clock;

		while (!m_window.IsDone())
		{
			m_window.BeginDraw();
			m_window.Update();

			auto lv_blocksOfSnake = m_snake.GetSnake();
			if (lv_clock.getElapsedTime().asSeconds() > lv_frameRate) {
				m_snake.Move();
				lv_clock.restart();

			}

			for (auto l_square : lv_blocksOfSnake) {
				m_window.Draw(l_square);
			}
			auto lv_circle = m_apple.GetCircle();
			m_window.Draw(lv_circle);

			m_snake.CollisionAppleHandler(m_apple);

			m_window.EndDraw();
		}
	}
}
#include "Window.hpp"
#include "Game_namespace.hpp"
#include <iostream>

int main()
{
	try {
		Window lv_window("Snake", sf::Vector2u(600, 600));
		sf::RectangleShape lv_rectangle(sf::Vector2f(10.f, 10.f));
		lv_rectangle.setFillColor(sf::Color::Green);
		

		while (!lv_window.IsDone()) {
			lv_window.Update();
			lv_window.BeginDraw();
			Game::Input::Keyboard::HandleKeyboardInput(lv_rectangle);
			lv_window.Draw(lv_rectangle);
			lv_window.EndDraw();
		}
	}

	catch (const char* error) {
		std::cout << error << std::endl;
		return -1;
	}

	return 0;
}


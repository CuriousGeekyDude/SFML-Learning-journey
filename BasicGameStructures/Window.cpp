#include "Window.hpp"

Window::Window(const std::string& l_title, const sf::Vector2u& l_size)
{
	Setup(l_title, l_size);
}
Window::~Window()
{
	Destroy();
}





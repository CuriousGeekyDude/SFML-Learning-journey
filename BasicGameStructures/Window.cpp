#include "Window.hpp"

Window::Window(const std::string& l_title, const sf::Vector2u& l_size)
{
	Setup(l_title, l_size);
}





void Window::Setup(const std::string& l_title, const sf::Vector2u& l_size)
{
	m_windowTitle = l_title;
	m_windowSize = l_size;
	m_isDone = false;
	m_isFullscreen = false;
	Create();
}

void Window::Destroy()
{
	m_window.close();
}

void Window::Create()
{
	auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.create({m_windowSize.x, m_windowSize.y}, m_windowTitle, style);
}

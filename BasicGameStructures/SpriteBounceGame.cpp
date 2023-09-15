#include "SpriteBounceGame.hpp"

SpriteBounceGame::SpriteBounceGame()
{
	m_window = &Window("First Game!", sf::Vector2u(400, 400));
	m_texture = &sf::Texture();
	
}

void SpriteBounceGame::HandleInput()
{
	
}


void SpriteBounceGame::LoadFileTexture(const std::string& l_locationTexture, const sf::IntRect& l_area)
{
	m_texture->loadFromFile(l_locationTexture, l_area);
}
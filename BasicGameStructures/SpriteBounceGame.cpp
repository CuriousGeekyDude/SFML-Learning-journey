#include "SpriteBounceGame.hpp"

SpriteBounceGame::SpriteBounceGame()
{
	m_window = &Window("First Game!", sf::Vector2u(400, 400));
	m_texture = &sf::Texture();
	
}

void SpriteBounceGame::HandleInput()
{
	LoadFileTexture("C:/Users/farhan/Desktop/SFML_stuff/mosques.jpg", sf::IntRect(0, 0, 100, 150));
	m_sprite = sf::Sprite(*m_texture);

}


void SpriteBounceGame::LoadFileTexture(const std::string& l_locationTexture, const sf::IntRect& l_area)
{
	if (!m_texture->loadFromFile(l_locationTexture, l_area)) {
		throw - 1;
	}
}


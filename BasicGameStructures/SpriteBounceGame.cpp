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

void SpriteBounceGame::SetTransparency(sf::Color& l_color)
{
    if (m_opaqueX == false || m_opaqueY == false) {
        l_color.a = 255;
        if (m_opaqueX == false) {
            m_opaqueX = true;
        }
        else {
            m_opaqueY = true;
        }
    }
    else {
        l_color.a = 50;
        if (m_opaqueX == true) {
            m_opaqueX = false;
        }
        else {
            m_opaqueY = false;
        }
    }
}

void SpriteBounceGame::SetTransparencySprite(sf::Sprite& l_sprite)
{
    sf::Color color = l_sprite.getColor();
    SetTransparency(color);
    l_sprite.setColor(color);
}


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


void SpriteBounceGame::Update()
{
    m_window->Update();
    SpriteHitBoundary_X();
    SpriteHitBoundary_Y();

    m_window->BeginDraw();
    SpriteMove(m_clock.getElapsedTime());
}

void SpriteBounceGame::Render()
{
    m_window->Draw(m_sprite);
    m_window->EndDraw();
}


Window* SpriteBounceGame::GetWindow()
{
    return m_window;
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

void SpriteBounceGame::SpriteHitBoundary_X()
{
    const float xPos = m_sprite.getPosition().x;

    if (xPos >= 300 || xPos < 0) {
        SetTransparencySprite(m_sprite);
        m_displacementX = -m_displacementX;
    }
}

void SpriteBounceGame::SpriteHitBoundary_Y()
{
    const float yPos = m_sprite.getPosition().y;

    if (yPos >= 250 || yPos < 0) {
        SetTransparencySprite(m_sprite);
        m_displacementY = -m_displacementY;
    }
}

void SpriteBounceGame::SpriteMove(const sf::Time& l_time)
{
    m_sprite.move(sf::Vector2f(m_displacementX*l_time.asSeconds(), m_displacementY * l_time.asSeconds()));
}


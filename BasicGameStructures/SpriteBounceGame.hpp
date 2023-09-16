#ifndef SPRITE_BOUNCE_GAME_HPP
#define SPRITE_BOUNCE_GAME_HPP

#include "Window.hpp"
#include <SFML/Graphics.hpp>
#include <string>

class SpriteBounceGame
{
public:
	SpriteBounceGame();
	~SpriteBounceGame() {}

	void HandleInput();
	void Update();
	void Render();

	Window* GetWindow();
private:

	void LoadFileTexture(const std::string& l_locationTexture, const sf::IntRect& l_area);

	void SetTransparency(sf::Color& l_color);
	void SetTransparencySprite(sf::Sprite& l_sprite);

	void SpriteHitBoundary_Y();
	void SpriteHitBoundary_X();

	void SpriteMove(const sf::Time& l_time);

	Window* m_window = nullptr;
	sf::Texture* m_texture = nullptr;
	sf::Sprite m_sprite;
	sf::Clock m_clock;
	float m_displacementX = 0.2f;
	float m_displacementY = 0.2f;
	bool m_opaqueX = true;
	bool m_opaqueY = true;
};


#endif
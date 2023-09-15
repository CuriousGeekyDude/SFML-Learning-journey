#ifndef SPRITE_BOUNCE_GAME_HPP
#define SPRITE_BOUNCE_GAME_HPP

#include "Window.hpp"
#include <SFML/Graphics.hpp>

class SpriteBounceGame
{
public:
	SpriteBounceGame();
	~SpriteBounceGame();

	void HandleInput();
	void Update();
	void Render();


private:

	void setTransparency(sf::Color& l_color);
	void SetTransparencySprite(sf::Sprite& l_sprite);

	void SpriteHitBoundary_Y();
	void SpriteHitBoundary_X();

	void SpriteMove();

	Window* m_window = nullptr;
	sf::Texture* m_texture = nullptr;
	const float m_displacementX = 0.2f;
	const float m_displacementY = 0.2f;
	bool m_opaqueX = true;
	bool m_opaqueY = true;
};


#endif
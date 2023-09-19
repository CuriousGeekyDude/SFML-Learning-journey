#include "Game_namespace.hpp"

namespace Game
{
	namespace Objects
	{
		TextureContainer::TextureContainer(const std::string& l_pathApple, const std::string& l_pathSquare)
		{
			for (int i = 0; i < 2; ++i) {
				m_textureContainer.push_back(sf::Texture());
			}
			m_textureContainer[0].loadFromFile(l_pathApple);
			m_textureContainer[1].loadFromFile(l_pathSquare);
		}
	}
}
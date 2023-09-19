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
		sf::Texture& TextureContainer::operator[](const int l_index)
		{
			if (l_index < 0 || l_index > 1) {
				throw "Out of Bounds index!";
			}

			return m_textureContainer[l_index];
		}

		const sf::Texture& TextureContainer::operator[](const int l_index) const
		{
			if (l_index < 0 || l_index > 1) {
				throw "Out of Bounds index!";
			}

			return m_textureContainer[l_index];
		}
	}
}
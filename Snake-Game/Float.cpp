#include "Random_generator.hpp"

namespace Random_generator
{
	float Float::Generate()
	{
		return m_distribution(m_generator);
	}

}
#include "RandomGenerator.hpp"

namespace RandomGenerator
{
	float Float::Generate()
	{
		return m_distribution(m_generator);
	}

}
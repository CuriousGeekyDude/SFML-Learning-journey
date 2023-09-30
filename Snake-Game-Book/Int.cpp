#include "RandomGenerator.hpp"

namespace RandomGenerator
{
	int Int::Generate()
	{
		return m_distribution(m_generator);
	}
}
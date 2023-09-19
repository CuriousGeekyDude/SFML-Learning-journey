#include "Random_generator.hpp"


namespace Random_generator
{
	int Int::Generate()
	{
		return m_distribution(m_generator);
	}
}
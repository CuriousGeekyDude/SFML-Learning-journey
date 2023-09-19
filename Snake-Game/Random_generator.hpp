#include <random>


namespace Random_generator
{
	class Float
	{
	public:
		Float(const float l_min, const float l_max):m_distribution(l_min, l_max){}

		float generate();


	private:
		std::default_random_engine m_generator;
		std::uniform_real_distribution<float> m_distribution;
	};

	class Int
	{
	public:
		Int(const int l_min, const float l_max):m_distribution(l_min,l_max) {}

		int generate();


	private:
		std::default_random_engine m_generator;
		std::uniform_int_distribution<int> m_distribution;
	};
}
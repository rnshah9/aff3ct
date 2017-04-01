#ifndef INTERLEAVER_RANDOM_HPP
#define	INTERLEAVER_RANDOM_HPP

#include <algorithm>
#include <time.h>
#include <random>

#include "../Interleaver.hpp"

namespace aff3ct
{
namespace module
{
template <typename T = int>
class Interleaver_random : public Interleaver<T>
{
private:
	std::random_device rd;
	std::mt19937       rd_engine;

public:
	Interleaver_random(int size, const int seed = 0, const int n_frames = 1,
	                   const std::string name = "Interleaver_random")
	: Interleaver<T>(size, n_frames, name), rd(), rd_engine(rd())
	{
		rd_engine.seed(seed);
		gen_lookup_tables();
	}

	void gen_lookup_tables()
	{
		for (auto i = 0; i < (int)this->pi.size(); i++)
			this->pi[i] = i;

		std::shuffle(this->pi.begin(), this->pi.end(), rd_engine);

		for (auto i = 0; i < (int)this->pi_inv.size(); i++)
			this->pi_inv[this->pi[i]] = i;
	}
};
}
}

#endif	/* INTERLEAVER_RANDOM_HPP */


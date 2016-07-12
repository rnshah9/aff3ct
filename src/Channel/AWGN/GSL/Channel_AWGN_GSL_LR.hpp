#ifdef CHANNEL_GSL

#ifndef CHANNEL_AWGN_GSL_LR_HPP_
#define CHANNEL_AWGN_GSL_LR_HPP_

#include "Channel_AWGN_GSL_LLR.hpp"

template <typename R>
class Channel_AWGN_GSL_LR : public Channel_AWGN_GSL_LLR<R>
{
public:
	Channel_AWGN_GSL_LR(const R& sigma, const int seed = 0);

	virtual ~Channel_AWGN_GSL_LR();

	void add_noise(const mipp::vector<R>& X_N, mipp::vector<R>& Y_N);
};

#endif // CHANNEL_AWGN_GSL_LR_HPP_

#endif

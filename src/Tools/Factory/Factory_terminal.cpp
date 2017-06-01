#include <stdexcept>

#include "Tools/Display/Terminal/BFER/Terminal_BFER.hpp"
#include "Tools/Display/Terminal/BFER/Terminal_BFER_legacy.hpp"

#include "Factory_terminal.hpp"

using namespace aff3ct::module;
using namespace aff3ct::tools;

template <typename B>
Terminal* Factory_terminal<B>
::build(const std::string                                                                   type,
        const int                                                                           K,
        const int                                                                           N,
        const float                                                                        &snr_s,
        const float                                                                        &snr_b,
        const Monitor<B>                                                                   &monitor,
        const std::chrono::nanoseconds                                                     *d_decod_total)
{
	     if (type == "STD"   ) return new Terminal_BFER       <B>(K, N, monitor, &snr_s, &snr_b, d_decod_total);
	else if (type == "LEGACY") return new Terminal_BFER_legacy<B>(K, N, monitor,          snr_b               );

	throw std::runtime_error("aff3ct::tools::Factory_terminal: the factory could not allocate the object.");
}

// ==================================================================================== explicit template instantiation 
#include "Tools/types.h"
#ifdef MULTI_PREC
template struct aff3ct::tools::Factory_terminal<B_8>;
template struct aff3ct::tools::Factory_terminal<B_16>;
template struct aff3ct::tools::Factory_terminal<B_32>;
template struct aff3ct::tools::Factory_terminal<B_64>;
#else
template struct aff3ct::tools::Factory_terminal<B>;
#endif
// ==================================================================================== explicit template instantiation

#ifndef TERMINAL_BFER_LEGACY_HPP_
#define TERMINAL_BFER_LEGACY_HPP_

#include <string>
#include <chrono>

#include "Module/Monitor/Monitor.hpp"
#include "../Terminal.hpp"

namespace aff3ct
{
namespace tools
{
template <typename B = int>
class Terminal_BFER_legacy : public Terminal
{
protected:
	const int                                                                           K;
	const int                                                                           N;
	const float                                                                        &snr;
	const module::Monitor<B>                                                           &monitor;
	      std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds>  t_snr;
	unsigned short                                                                      real_time_state;

public:
	Terminal_BFER_legacy(const int K,
	                     const int N,
	                     const module::Monitor<B> &monitor,
	                     const float &snr);
	virtual ~Terminal_BFER_legacy() {}

	void temp_report (std::ostream &stream = std::cout);
	void final_report(std::ostream &stream = std::cout);

private:
	static std::string get_time_format(float secondes);
	void _report(std::ostream &stream);
};
}
}

#endif /* TERMINAL_BFER_LEGACY_HPP_ */

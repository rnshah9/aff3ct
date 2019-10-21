/*!
 * \file
 * \brief Class factory::Codec_RA.
 */
#ifndef FACTORY_CODEC_RA_HPP
#define FACTORY_CODEC_RA_HPP

#include <string>
#include <map>
#include <cli.hpp>

#include "Module/CRC/CRC.hpp"
#include "Module/Codec/RA/Codec_RA.hpp"
#include "Factory/Module/Codec/Codec_SIHO.hpp"

namespace aff3ct
{
namespace factory
{
extern const std::string Codec_RA_name;
extern const std::string Codec_RA_prefix;
class Codec_RA : public Codec_SIHO
{
public:
	explicit Codec_RA(const std::string &p = Codec_RA_prefix);
	virtual ~Codec_RA() = default;
	Codec_RA* clone() const;

	// parameters construction
	void get_description(cli::Argument_map_info &args) const;
	void store          (const cli::Argument_map_value &vals);
	void get_headers    (std::map<std::string,header_list>& headers, const bool full = true) const;

	// builder
	template <typename B = int, typename Q = float>
	module::Codec_RA<B,Q>* build(module::CRC<B> *crc = nullptr) const;
};
}
}

#endif /* FACTORY_CODEC_RA_HPP */
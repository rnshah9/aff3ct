/*!
 * \file
 * \brief Class factory::Command_parser.
 */
#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cli.hpp>

#include "Factory/Factory.hpp"

namespace aff3ct
{
namespace factory
{

class Command_parser
{
private:
	cli::Argument_handler ahandler;
	std::vector<Factory::parameters*> &params;
	std::ostream& err_stream;
	std::vector<std::string> warnings;
	std::vector<std::string> errors;
	cli::Argument_map_info args;
	static const cli::Argument_tag help_tag;
	bool help_asked;

public:
	Command_parser(int argc, char** argv, std::vector<Factory::parameters*> &params, bool add_help_tag = false,
	               std::ostream& err_stream = std::cerr);

	void print_help    ();
	void print_errors  ();
	void print_warnings();

	bool help_required    (); // return true if the help tag is set
	bool parsing_failed   (); // return true if there are errors
	bool parsing_succeeded(); // return true if no errors

private:
	void parse(bool add_help_tag);
};

}
}

#endif
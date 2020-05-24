#ifndef ICOMMAND_PARSER_H
#define ICOMMAND_PARSER_H

#include "ICommand.h"

#include <vector>
#include <string>

class ICommandParser
{
public:
	virtual ICommand* parseCommand(const std::string&) = 0;
	virtual std::vector<std::string> parseParameters(const std::string&) = 0;
	virtual std::vector<std::string> split(const std::string& s, char delim) = 0;
};

#endif // !ICOMMAND_PARSER_H

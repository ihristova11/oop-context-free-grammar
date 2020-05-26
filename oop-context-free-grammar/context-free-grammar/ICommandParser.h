#ifndef ICOMMAND_PARSER_H
#define ICOMMAND_PARSER_H

#include "ICommand.h"

#include <vector>
#include <string>

/// <summary>
/// ICommandParser interface for different implementations of parser objects
/// </summary>
class ICommandParser
{
public:
	/// <summary>
	/// finds a command by parameters given
	/// </summary>
	/// <param name="fullCommand">string variable containing the command name and its parameters</param>
	/// <returns>ICommand* if a command is found, nullptr if not</returns>
	virtual ICommand* parseCommand(const std::string&) = 0;

	/// <summary>
	/// splits the command parameters
	/// </summary>
	/// <param name="fullCommand">string variable containing the command name and its parameters</param>
	/// <returns>std::vector<std::string> of split values</returns>
	virtual std::vector<std::string> parseParameters(const std::string&) = 0;

private:
	/// <summary>
	/// split string implementation
	/// </summary>
	/// <param name="s">string to split</param>
	/// <param name="delim">delimiter</param>
	/// <returns>std::vector<std::string> of split values</returns>
	virtual std::vector<std::string> split(const std::string& s, char delim) = 0;
};

#endif // !ICOMMAND_PARSER_H

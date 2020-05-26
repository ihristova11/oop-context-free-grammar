#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <string>
#include <vector>

#include "Constants.h"

/// <summary>
/// ICommand interface to be implemented by different command instances
/// </summary>
class ICommand
{
public:
	/// <summary>
	/// execute() contains command specific execution logic
	/// </summary>
	/// <param name="parameters">vector of string values</param>
	/// <returns>a string containing the execution message</returns>
	virtual std::string execute(const std::vector<std::string>&) = 0;

	/// <summary>
	/// toString() implementation on command class
	/// </summary>
	/// <returns>the command name</returns>
	virtual std::string toString() = 0;
};

#endif // !ICOMMAND_H

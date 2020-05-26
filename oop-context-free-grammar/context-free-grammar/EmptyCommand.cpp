#include "EmptyCommand.h"

std::string EmptyCommand::execute(const std::vector<std::string>&)
{
	return std::string();
}

std::string EmptyCommand::toString()
{
	return Constants::EmptyCommandName;
}

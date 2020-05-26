#include "HelpCommand.h"

std::string HelpCommand::execute(const std::vector<std::string>&)
{
	return std::string();
}

std::string HelpCommand::toString()
{
	return Constants::HelpCommandName;
}

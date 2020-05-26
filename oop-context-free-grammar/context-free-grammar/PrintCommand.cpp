#include "PrintCommand.h"

std::string PrintCommand::execute(const std::vector<std::string>&)
{
	return std::string();
}

std::string PrintCommand::toString()
{
	return Constants::PrintCommandName;
}

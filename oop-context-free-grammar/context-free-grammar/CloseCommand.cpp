#include "CloseCommand.h"

std::string CloseCommand::execute(const std::vector<std::string>&)
{
	return std::string();
}

std::string CloseCommand::toString()
{
	return Constants::CloseCommandName;
}

#include "OpenCommand.h"

std::string OpenCommand::execute(const std::vector<std::string>&)
{
	return std::string();
}

std::string OpenCommand::toString()
{
	return Constants::OpenCommandName;
}

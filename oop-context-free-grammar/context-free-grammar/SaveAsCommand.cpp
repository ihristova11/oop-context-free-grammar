#include "SaveAsCommand.h"

std::string SaveAsCommand::execute(const std::vector<std::string>&)
{
	return std::string();
}

std::string SaveAsCommand::toString()
{
	return Constants::SaveAsCommandName;
}

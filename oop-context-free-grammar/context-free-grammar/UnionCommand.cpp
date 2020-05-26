#include "UnionCommand.h"

std::string UnionCommand::execute(const std::vector<std::string>&)
{
	return std::string();
}

std::string UnionCommand::toString()
{
	return Constants::UnionCommandName;
}

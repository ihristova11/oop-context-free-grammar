#include "AddRuleCommand.h"

std::string AddRuleCommand::execute(const std::vector<std::string>&)
{
	return std::string();
}

std::string AddRuleCommand::toString()
{
	return Constants::AddRuleCommandName;
}

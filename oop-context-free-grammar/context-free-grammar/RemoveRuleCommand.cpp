#include "RemoveRuleCommand.h"

std::string RemoveRuleCommand::execute(const std::vector<std::string>&)
{
	return std::string();
}

std::string RemoveRuleCommand::toString()
{
	return Constants::RemoveRuleCommandName;
}

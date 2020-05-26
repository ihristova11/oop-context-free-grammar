#ifndef REMOVE_RULE_COMMAND_H
#define REMOVE_RULE_COMMAND_H

#include "ICommand.h"

/// <summary>
/// RemoveRuleCommand remove rules by given parameters
/// </summary>
class RemoveRuleCommand : public ICommand
{
public:
	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !REMOVE_RULE_COMMAND_H

#ifndef REMOVE_RULE_COMMAND_H
#define REMOVE_RULE_COMMAND_H

#include "ICommand.h"

class RemoveRuleCommand : public ICommand
{
public:
	virtual std::string execute() override;
};

#endif // !REMOVE_RULE_COMMAND_H

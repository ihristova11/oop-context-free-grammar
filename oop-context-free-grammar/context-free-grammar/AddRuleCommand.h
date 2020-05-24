#ifndef ADD_RULE_COMMAND_H
#define ADD_RULE_COMMAND_H

#include "ICommand.h"

class AddRuleCommand : public ICommand
{
public:
	virtual std::string execute() override;
};

#endif // !ADD_RULE_COMMAND_H

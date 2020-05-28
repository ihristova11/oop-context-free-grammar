#ifndef ADD_RULE_COMMAND_H
#define ADD_RULE_COMMAND_H

#include "ICommand.h"

/// <summary>
/// AddRuleCommand adds rules to grammar
/// </summary>
class AddRuleCommand : public ICommand
{
public:
	AddRuleCommand(Store*);

	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !ADD_RULE_COMMAND_H

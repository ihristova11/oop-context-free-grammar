#ifndef LIST_COMMAND_H
#define LIST_COMMAND_H

#include "ICommand.h"

/// <summary>
/// ListCommand displays information about grammars
/// </summary>
class ListCommand : public ICommand
{
public:
	ListCommand(Store*);

	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !LIST_COMMAND_H

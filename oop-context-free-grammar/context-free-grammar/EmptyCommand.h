#ifndef EMPTY_COMMAND_H
#define EMPTY_COMMAND_H

#include "ICommand.h"

/// <summary>
/// EmptyCommand checks if the language of the grammar is empty
/// </summary>
class EmptyCommand : public ICommand
{
public:
	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !EMPTY_COMMAND_H

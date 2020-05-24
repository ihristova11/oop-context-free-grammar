#ifndef HELP_COMMAND_H
#define HELP_COMMAND_H

#include "ICommand.h"

class HelpCommand : public ICommand
{
public:
	virtual std::string execute() override;
};

#endif // !HELP_COMMAND_H

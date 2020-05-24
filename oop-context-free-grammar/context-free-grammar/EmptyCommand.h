#ifndef EMPTY_COMMAND_H
#define EMPTY_COMMAND_H

#include "ICommand.h"

class EmptyCommand : public ICommand
{
public:
	virtual std::string execute() override;
};

#endif // !EMPTY_COMMAND_H

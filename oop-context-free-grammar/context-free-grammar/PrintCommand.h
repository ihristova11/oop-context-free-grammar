#ifndef PRINT_COMMAND_H
#define PRINT_COMMAND_H

#include "ICommand.h"
class PrintCommand : public ICommand
{
public:
	virtual std::string execute() override;
};

#endif // PRINT_COMMAND_H

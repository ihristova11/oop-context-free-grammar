#ifndef EXIT_COMMAND_H
#define EXIT_COMMAND_H

#include "ICommand.h"

class ExitCommand : public ICommand
{
public:
	virtual std::string execute() override;
};

#endif // !EXIT_COMMAND_H

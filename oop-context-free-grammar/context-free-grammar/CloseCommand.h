#ifndef CLOSE_COMMAND_H
#define CLOSE_COMMAND_H

#include "ICommand.h"

class CloseCommand : public ICommand
{
public:
	virtual std::string execute() override;
};

#endif // !CLOSE_COMMAND_H

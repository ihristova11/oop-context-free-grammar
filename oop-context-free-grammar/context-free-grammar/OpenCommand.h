#ifndef OPEN_COMMAND_H
#define OPEN_COMMAND_H

#include "ICommand.h"

class OpenCommand : public ICommand
{
public:
	virtual std::string execute() override;
};

#endif // !OPEN_COMMAND_H

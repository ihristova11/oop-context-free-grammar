#ifndef CHOMSKY_COMMAND_H
#define CHOMSKY_COMMAND_H

#include "ICommand.h"

class ChomskyCommand : public ICommand
{
public:
	virtual std::string execute() override;
};

#endif // !CHOMSKY_COMMAND_H

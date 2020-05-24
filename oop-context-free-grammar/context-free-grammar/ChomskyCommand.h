#ifndef CHOMSKY_COMMAND_H
#define CHOMSKY_COMMAND_H

#include "ICommand.h"

class ChomskyCommand : public ICommand
{
public:
	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !CHOMSKY_COMMAND_H

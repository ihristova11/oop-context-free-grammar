#ifndef EMPTY_COMMAND_H
#define EMPTY_COMMAND_H

#include "ICommand.h"

class EmptyCommand : public ICommand
{
public:
	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !EMPTY_COMMAND_H

#ifndef PRINT_COMMAND_H
#define PRINT_COMMAND_H

#include "ICommand.h"
class PrintCommand : public ICommand
{
public:
	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // PRINT_COMMAND_H

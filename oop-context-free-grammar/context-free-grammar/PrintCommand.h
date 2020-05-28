#ifndef PRINT_COMMAND_H
#define PRINT_COMMAND_H

#include "ICommand.h"

/// <summary>
/// PrintCommand displays a grammar in a proper way
/// </summary>
class PrintCommand : public ICommand
{
public:
	PrintCommand(Store*);

	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // PRINT_COMMAND_H

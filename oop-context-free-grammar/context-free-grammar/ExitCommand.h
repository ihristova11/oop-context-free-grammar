#ifndef EXIT_COMMAND_H
#define EXIT_COMMAND_H

#include "ICommand.h"

class ExitCommand : public ICommand
{
public:
	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !EXIT_COMMAND_H

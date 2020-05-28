#ifndef EXIT_COMMAND_H
#define EXIT_COMMAND_H

#include "ICommand.h"

/// <summary>
/// ExitCommand exits the program without saving changes to the file.
/// </summary>
class ExitCommand : public ICommand
{
public:
	ExitCommand(Store*);

	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !EXIT_COMMAND_H

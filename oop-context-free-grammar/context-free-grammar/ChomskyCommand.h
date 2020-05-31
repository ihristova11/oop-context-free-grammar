#ifndef CHOMSKY_COMMAND_H
#define CHOMSKY_COMMAND_H

#include "ICommand.h"

/// <summary>
/// ChomskyCommand checks if grammar is in Chomsky normal form
/// </summary>
class ChomskyCommand : public ICommand
{
public:
	ChomskyCommand(Store*);

	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !CHOMSKY_COMMAND_H

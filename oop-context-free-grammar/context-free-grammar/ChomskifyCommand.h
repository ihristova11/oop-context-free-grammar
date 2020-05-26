#ifndef CHOMSKIFY_COMMAND_H
#define CHOMSKIFY_COMMAND_H

#include "ICommand.h"

/// <summary>
/// ChomskifyCommand converts grammar into Chomsky normal form
/// </summary>
class ChomskifyCommand : public ICommand
{
public:
	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !CHOMSKIFY_COMMAND_H

#ifndef ITER_COMMAND_H
#define ITER_COMMAND_H

#include "ICommand.h"

/// <summary>
/// IterCommand constructs a new grammar using the Kleene star operation
/// </summary>
class IterCommand : public ICommand
{
public:
	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !ITER_COMMAND_H

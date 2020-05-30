#ifndef UNION_COMMAND_H
#define UNION_COMMAND_H

#include "ICommand.h"

/// <summary>
/// UnionCommand creates a new grammar out of the union of two other grammars
/// </summary>
class UnionCommand : public ICommand
{
public:
	UnionCommand(Store*);

	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !UNION_COMMAND_H

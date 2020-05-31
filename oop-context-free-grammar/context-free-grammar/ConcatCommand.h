#ifndef CONCAT_COMMAND_H
#define CONCAT_COMMAND_H

#include "ICommand.h"

/// <summary>
/// ConcatCommand concatenates two grammars by ids
/// </summary>
class ConcatCommand : public ICommand
{
public:
	ConcatCommand(Store*);

	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !CONCAT_COMMAND_H

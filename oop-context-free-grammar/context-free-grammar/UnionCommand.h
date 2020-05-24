#ifndef UNION_COMMAND_H
#define UNION_COMMAND_H

#include "ICommand.h"

class UnionCommand : public ICommand
{
public:
	virtual std::string execute() override;
};

#endif // !UNION_COMMAND_H

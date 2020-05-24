#ifndef UNION_COMMAND_H
#define UNION_COMMAND_H

#include "ICommand.h"

class UnionCommand : public ICommand
{
public:
	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !UNION_COMMAND_H

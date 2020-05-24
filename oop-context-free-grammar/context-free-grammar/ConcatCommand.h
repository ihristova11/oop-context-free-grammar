#ifndef CONCAT_COMMAND_H
#define CONCAT_COMMAND_H

#include "ICommand.h"

class ConcatCommand : public ICommand
{
public:
	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !CONCAT_COMMAND_H

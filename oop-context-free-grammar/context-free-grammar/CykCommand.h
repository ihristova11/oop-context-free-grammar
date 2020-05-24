#ifndef CYK_COMMAND_H
#define CYK_COMMAND_H

#include "ICommand.h"

class CykCommand : public ICommand
{
public:
	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !CYK_COMMAND_H

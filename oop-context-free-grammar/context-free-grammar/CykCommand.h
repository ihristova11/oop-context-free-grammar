#ifndef CYK_COMMAND_H
#define CYK_COMMAND_H

#include "ICommand.h"

class CykCommand : public ICommand
{
public:
	virtual std::string execute() override;
};

#endif // !CYK_COMMAND_H

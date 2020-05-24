#ifndef LIST_COMMAND_H
#define LIST_COMMAND_H

#include "ICommand.h"

class ListCommand : public ICommand
{
public:
	virtual std::string execute() override;
};

#endif // !LIST_COMMAND_H

#ifndef ITER_COMMAND_H
#define ITER_COMMAND_H

#include "ICommand.h"

class IterCommand : public ICommand
{
public:
	virtual std::string execute() override;
};

#endif // !ITER_COMMAND_H

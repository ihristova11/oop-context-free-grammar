#ifndef SAVE_COMMAND_H
#define SAVE_COMMAND_H

#include "ICommand.h"

class SaveCommand : public ICommand
{
public:
	virtual std::string execute() override;
};

#endif // !SAVE_COMMAND_H

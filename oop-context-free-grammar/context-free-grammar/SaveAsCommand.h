#ifndef SAVE_AS_COMMAND_H
#define SAVE_AS_COMMAND_H

#include "ICommand.h"

class SaveAsCommand : public ICommand
{
public:
	virtual std::string execute() override;
};

#endif // !SAVE_AS_COMMAND_H

#ifndef CHOMSKIFY_COMMAND_H
#define CHOMSKIFY_COMMAND_H

#include "ICommand.h"

class ChomskifyCommand : public ICommand
{
public:
	virtual std::string execute() override;
};

#endif // !CHOMSKIFY_COMMAND_H

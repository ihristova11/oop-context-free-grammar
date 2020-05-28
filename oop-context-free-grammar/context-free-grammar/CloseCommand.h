#ifndef CLOSE_COMMAND_H
#define CLOSE_COMMAND_H

#include "ICommand.h"

/// <summary>
/// CloseCommand class hold the logic of closing the last document opened.
/// </summary>
class CloseCommand : public ICommand
{
public:
	CloseCommand(Store*);

	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !CLOSE_COMMAND_H

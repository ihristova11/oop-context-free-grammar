#ifndef SAVE_AS_COMMAND_H
#define SAVE_AS_COMMAND_H

#include "ICommand.h"

/// <summary>
/// SaveAsCommand saves changes in a different file (should be .txt as well)
/// </summary>
class SaveAsCommand : public ICommand
{
public:
	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !SAVE_AS_COMMAND_H

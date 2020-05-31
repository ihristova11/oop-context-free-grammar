#ifndef CYK_COMMAND_H
#define CYK_COMMAND_H

#include "ICommand.h"

/// <summary>
/// CykCommand checks if a word is element of the language of the grammar
/// </summary>
class CykCommand : public ICommand
{
public:
	CykCommand(Store*);

	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;
};

#endif // !CYK_COMMAND_H

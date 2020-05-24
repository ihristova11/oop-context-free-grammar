#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <string>

class ICommand
{
public:
	virtual std::string execute() = 0;
};

#endif // !ICOMMAND_H

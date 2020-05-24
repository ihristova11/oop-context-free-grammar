#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <string>
#include <vector>

class ICommand
{
public:
	virtual std::string execute(const std::vector<std::string>&) = 0;
	virtual std::string toString() = 0;
};

#endif // !ICOMMAND_H

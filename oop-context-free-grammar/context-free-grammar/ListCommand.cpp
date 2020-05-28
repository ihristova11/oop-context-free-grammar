#include "ListCommand.h"

#include <iostream>

ListCommand::ListCommand(Store* store)
{
	ICommand::store = store;
}

std::string ListCommand::execute(const std::vector<std::string>&)
{
	// no parameters for this command, won't check them
	for (Grammar* g : this->store->getGrammars())
	{
		std::cout << g->getId() << std::endl;
	}

	return Constants::Success;
}

std::string ListCommand::toString()
{
	return Constants::ListCommandName;
}

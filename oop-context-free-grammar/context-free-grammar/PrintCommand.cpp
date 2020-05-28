#include "PrintCommand.h"
#include "Validator.h"

#include <iostream>

PrintCommand::PrintCommand(Store* store)
{
	ICommand::store = store;
}

std::string PrintCommand::execute(const std::vector<std::string>& params)
{
	// validator
	std::string id = params[1];
	if (Validator::isValidGrammarId(id, this->store->getGrammars()))
	{
		// find grammar
		Grammar* g = this->store->findGrammarById(id);
		std::cout << g->toString() << std::endl;
	}
	return std::string();
}

std::string PrintCommand::toString()
{
	return Constants::PrintCommandName;
}

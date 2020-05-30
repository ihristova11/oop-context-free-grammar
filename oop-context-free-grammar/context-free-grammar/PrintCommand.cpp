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
	int id = std::stoi(params[1]);
	if (Validator::isValidGrammarId(id, this->store->getGrammars()))
	{
		// find grammar
		Grammar* g = this->store->findGrammarById(id);
		std::cout << g->toString() << std::endl;
	}
	return Constants::Success;
}

std::string PrintCommand::toString()
{
	return Constants::PrintCommandName;
}

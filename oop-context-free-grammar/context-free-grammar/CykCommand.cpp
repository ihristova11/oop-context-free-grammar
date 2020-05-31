#include "CykCommand.h"
#include "Validator.h"
#include <map>

CykCommand::CykCommand(Store* store)
{
	ICommand::store = store;
}

std::string CykCommand::execute(const std::vector<std::string>& parameters)
{
	if (Validator::isValidParametersCount(3, parameters.size()))
	{
		int id = std::stoi(parameters[1]);
		std::string word = parameters[2];
		if (Validator::isValidGrammarId(id, this->store->getGrammars()))
		{
			Grammar* g = this->store->findGrammarById(id);
			if (!g->chomsky()) {
				return Constants::CykNotPossible;
			}
			
			return Constants::ToImplement;
		}
		else return Constants::NoGrammar;
	}
	else return Constants::InvalidParameters;
}

std::string CykCommand::toString()
{
	return Constants::CykCommandName;
}

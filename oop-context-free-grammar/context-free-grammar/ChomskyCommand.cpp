#include "ChomskyCommand.h"
#include "Validator.h"

ChomskyCommand::ChomskyCommand(Store* store)
{
	ICommand::store = store;
}

std::string ChomskyCommand::execute(const std::vector<std::string>& parameters)
{
	if (Validator::isValidParametersCount(2, parameters.size()))
	{
		int id = std::stoi(parameters[1]);

		// check for grammars with ids
		if (Validator::isValidGrammarId(id, this->store->getGrammars()))
		{
			return Constants::ToImplement;
			/*Grammar* g = this->store->findGrammarById(id);

			return g->chomsky() ? "Yes" : "No";*/
		}
		else return Constants::NoGrammar;
	}
	else return Constants::InvalidParameters;
}

std::string ChomskyCommand::toString()
{
	return Constants::ChomskyCommandName;
}

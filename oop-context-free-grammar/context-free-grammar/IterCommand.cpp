#include "IterCommand.h"
#include "Validator.h"

IterCommand::IterCommand(Store* store)
{
	ICommand::store = store;
}

std::string IterCommand::execute(const std::vector<std::string>& parameters)
{
	if (Validator::isValidParametersCount(2, parameters.size()))
	{
		int id = std::stoi(parameters[1]);
		if (Validator::isValidGrammarId(id, this->store->getGrammars()))
		{
			Grammar* g = this->store->findGrammarById(id);

			//returns almost the same grammar
			Grammar* iterGrammar = new Grammar(*g, true);
			// generateNonTerminal() for new starterVariable
			std::string generatedNT = store->generateNT('S');
			iterGrammar->setStartVariable(generatedNT);
			// create rules
			Rule r1 = { generatedNT, { "#" } };
			Rule r2 = { generatedNT, { g->getStartVariable(), generatedNT } };

			// add rules to grammar
			iterGrammar->addRule(r1);
			iterGrammar->addRule(r2);

			// add grammar to store
			this->store->addGrammar(*iterGrammar);

			return Constants::GrammarAdded + std::to_string(iterGrammar->getId()) + "!";
		}
		else return Constants::NoGrammar;
	}
	else return Constants::InvalidParameters;

	return Constants::Success;
}

std::string IterCommand::toString()
{
	return Constants::IterCommandName;
}

#include "UnionCommand.h"
#include "Validator.h"

UnionCommand::UnionCommand(Store* store)
{
	ICommand::store = store;
}

std::string UnionCommand::execute(const std::vector<std::string>& parameters)
{
	if (Validator::isValidParametersCount(3, parameters.size()))
	{
		int id1 = std::stoi(parameters[1]);
		int id2 = std::stoi(parameters[2]);

		// check for grammars with ids
		if (Validator::isValidGrammarId(id1, this->store->getGrammars()) 
			&& Validator::isValidGrammarId(id2, this->store->getGrammars()))
		{
			// find grammars
			Grammar* g1 = this->store->getGrammarById(id1);
			Grammar* g2 = this->store->getGrammarById(id2);

			// terminal check
			if (g1->getTerminals().size() != g2->getTerminals().size())
				return Constants::NoUnion;
			
			// terminals should be the same
			for (std::string terminal1 : g1->getTerminals())
			{
				if (g2->terminalExists(terminal1))
				{
					return Constants::NoUnion;
				}
			}

			// progress with union
			// the result will be almost the same, just new startVar and more rules
			Grammar* unionG = new Grammar(*g1, true); // generate new id

			// rename existing rules
			// add renamed to the new grammar
			// check the renaming algorithm 



		}
		else return Constants::NoGrammar;
	}
	else return Constants::InvalidParameters;

	return Constants::Success;
}

std::string UnionCommand::toString()
{
	return Constants::UnionCommandName;
}

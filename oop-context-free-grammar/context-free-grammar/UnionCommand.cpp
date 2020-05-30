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
			std::string generatedNT = store->generateNT("S"); // will be unique, no need to check for duplicates
			unionG->setStartVariable(generatedNT);

			// find variables with the same names
			// save them in vector
			std::vector<std::string> duplicates = this->findDuplicates(g1, g2);

			// add them to the grammar
			for (Rule* r : g1->getRules())
			{
				unionG->addRule(Rule(*r));
			}

			// rename them on the unionG

			// rename added
			for (std::string v : duplicates)
			{
				unionG->renameDuplicates(v,
					store->generateNT(v));
			}
			
			// no need to rename the second grammar rules, just add them
			for (Rule* r : g2->getRules())
			{
				unionG->addRule(Rule(*r));
			}

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

std::vector<std::string> UnionCommand::findDuplicates(Grammar* g1, Grammar* g2)
{
	std::vector<std::string> duplicates;

	if (g1->getStartVariable() == g2->getStartVariable()) duplicates.push_back(g1->getStartVariable());

	for (std::string s : g1->getVariables())
	{
		if (g2->variableExists(s))
		{
			duplicates.push_back(s);
		}
	}

	return duplicates;
}

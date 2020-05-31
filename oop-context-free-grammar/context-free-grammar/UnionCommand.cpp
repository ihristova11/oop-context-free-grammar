#include "UnionCommand.h"
#include "Validator.h"
#include <map>

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
			for (char terminal1 : g1->getTerminals())
			{
				if (!g2->terminalExists(terminal1))
				{
					return Constants::NoUnion;
				}
			}

			// progress with union
			// the result will be almost the same, just new startVar and more rules
			Grammar* unionG = new Grammar(*g1, true); // generate new id
			std::string generatedNT = store->generateNT("S"); // will be unique, no need to check for duplicates
			unionG->setStartTerminal(generatedNT);
			int id = unionG->getId();

			std::map<std::string, std::string> mapOldNew; //key: oldName, value: newName

			for (std::string s : g2->getNonTerminals())
			{
				if (!unionG->addNonTerminal(s))
				{
					std::string newN = store->generateNT(s.substr(0, 1));
					unionG->addNonTerminal(newN);
					mapOldNew.emplace(s, newN);
				}
			}

			for (Rule* r : g2->getRules())
			{
				Rule* temp = r;
				for (auto el : mapOldNew) 
				{
					if (temp->getNonTerminal() == el.first)
						temp->setNonTerminal(el.second);
					for (auto kt : temp->getProduct()) 
					{
						if (kt == el.first) {
							//kt.setProduct(el.second);
						}
					}
				}
				unionG->addRule(*temp);
			}

			std::string startingNonTerminal = store->generateNT("S");
			unionG->addNonTerminal(startingNonTerminal);
			unionG->setStartTerminal(startingNonTerminal);
			Rule temp1 = { startingNonTerminal, {g1->getStartNonTerminal()} };
			Rule temp2 = { startingNonTerminal, {g2->getStartNonTerminal()} };

			for (auto el : mapOldNew) {
				if (g2->getStartNonTerminal() == el.first)
				{
					//temp2.updateProductAt(0, el.second);
				}
			}

			unionG->addRule(temp1);
			unionG->addRule(temp2);

			this->store->addGrammar(*unionG);

			// delete unionG
			delete unionG;

			return Constants::GrammarAdded + std::to_string(id) + "!";
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

	if (g1->getStartNonTerminal() == g2->getStartNonTerminal()) duplicates.push_back(g1->getStartNonTerminal());

	for (std::string s : g1->getNonTerminals())
	{
		if (g2->nonTerminalExists(s))
		{
			duplicates.push_back(s);
		}
	}

	return duplicates;
}

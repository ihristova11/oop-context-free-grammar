#include "ConcatCommand.h"
#include "Validator.h"
#include <map>

ConcatCommand::ConcatCommand(Store* store)
{
	ICommand::store = store;
}

std::string ConcatCommand::execute(const std::vector<std::string>& parameters)
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

			Grammar* concatG = new Grammar(*g1, true); // auto generateId
			int id = concatG->getId();

			// renaming step
			std::map<std::string, std::string> mapOldNew;

			for (std::string s : g2->getNonTerminals())
			{
				if (!concatG->addNonTerminal(s))
				{
					std::string second = store->generateNT(s.substr(0, 1));
					concatG->addNonTerminal(second);
					mapOldNew.emplace(s, second);
				}
			}

			for (Rule* r : g2->getRules())
			{
				Rule* temp = r;
				for (auto el : mapOldNew) {
					if (temp->getNonTerminal() == el.first)
						temp->getNonTerminal() = el.second;
					for (auto kt : temp->getProduct()) {
						if (kt == el.first) {
							kt = el.second;
						}
					}
				}
				concatG->addRule(*temp);
			}

			std::string generatedNT = store->generateNT("S"); // will be unique, no need to check for duplicates
			concatG->setStartTerminal(generatedNT);
			concatG->addNonTerminal(generatedNT);

			Rule temp1 = { generatedNT, {g1->getStartNonTerminal(), g1->getStartNonTerminal()} };

			for (auto jt : mapOldNew) {
				if (g2->getStartNonTerminal() == jt.first) {
					//temp1.updateProductAt(1, jt.second);
				}
			}
			concatG->addRule(temp1);

			this->store->addGrammar(*concatG);

			// delete
			delete concatG;

			return Constants::GrammarAdded + std::to_string(id) + "!";
		}
		else return Constants::NoGrammar;
	}
	else return Constants::InvalidParameters;

	return Constants::Success;
}

std::string ConcatCommand::toString()
{
	return Constants::ConcatCommandName;
}

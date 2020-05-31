#include "EmptyCommand.h"
#include "Validator.h"

EmptyCommand::EmptyCommand(Store* store)
{
	ICommand::store = store;
}

std::string EmptyCommand::execute(const std::vector<std::string>& parameters)
{
	if (Validator::isValidParametersCount(2, parameters.size()))
	{
		int id = std::stoi(parameters[1]);
		if (Validator::isValidGrammarId(id, this->store->getGrammars()))
		{
			Grammar* g = this->store->findGrammarById(id);

			std::vector<std::string> marked;
			for (const char terminal : g->getTerminals()) {
				std::string temp;
				temp = terminal;
				marked.push_back(temp);
				marked.push_back("#");
			}
			bool added = false;
			do
			{
				added = false;
				for (auto& rule : g->getRules())
				{
					bool addToMarked = true;

					auto prods = rule->getProduct();
					for (size_t i = 0; addToMarked && i < prods.size(); i++)
					{
						addToMarked = this->store->existsInCollection(prods[i], marked);
					}

					if (addToMarked && !this->store->existsInCollection(rule->getNonTerminal(), marked))
					{
						marked.push_back(rule->getNonTerminal());
						added = true;
					}
				}
			} while (added); //repeat untill there are NTs to add to marked

			if (!this->store->existsInCollection(g->getStartVariable(), marked))
				return Constants::Empty;
			else return Constants::NotEmpty;

		}
		else return Constants::NoGrammar;
	}
	else return Constants::InvalidParameters;
}

std::string EmptyCommand::toString()
{
	return Constants::EmptyCommandName;
}

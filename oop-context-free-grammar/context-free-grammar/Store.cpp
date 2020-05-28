#include "Store.h"

Store::Store(const std::vector<Grammar*>& grammars) : grammars(grammars)
{ }

Grammar* Store::findGrammarById(const std::string& id)
{
	for (Grammar* g : this->grammars)
	{
		if (g->getId() == id)
			return g;
	}
	return nullptr;
}

std::vector<Grammar*> Store::getGrammars()
{
	return this->grammars;
}

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

void Store::addGrammar(const Grammar& grammar)
{
	Grammar* g = new Grammar(grammar);
	this->grammars.push_back(g);
}

Grammar* Store::getGrammarAtIndex(const int& index)
{
	if (index >= 0 && index < this->grammars.size())
		return this->grammars[index];

	return nullptr;
}

void Store::clearGrammars()
{
	this->grammars.clear();
}

std::vector<Grammar*> Store::getGrammars()
{
	return this->grammars;
}

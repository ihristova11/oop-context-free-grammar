#include "Store.h"

Store::Store() : grammars()
{ }

Store::Store(const std::vector<Grammar*>& grammars) : grammars(grammars)
{ }

Grammar* Store::findGrammarById(const int& id)
{
	for (Grammar* g : this->grammars)
	{
		if (g->getId() == id)
			return g;
	}
	return nullptr;
}

std::string Store::generateNT(char base)
{
	std::string newNT = "";
	newNT += base;

	// append digit
	newNT.append("_");
	for (size_t i = 0; i < 200; i++)
	{
		if (!this->ntExists(newNT.append(std::to_string(i))))
			return newNT.append(std::to_string(i));
	}

	return newNT;
}

bool Store::ntExists(const std::string& nt)
{
	for (Grammar* g : this->grammars)
	{
		if (g->getStartVariable() == nt) return true;
		for (std::string s: g->getVariables())
		{
			if (s == nt) return true;
		}
	}
	return false;
}

void Store::addGrammar(const Grammar& grammar)
{
	Grammar* g = new Grammar(grammar);
	this->grammars.push_back(g);
}

Grammar* Store::getGrammarById(const int& index)
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

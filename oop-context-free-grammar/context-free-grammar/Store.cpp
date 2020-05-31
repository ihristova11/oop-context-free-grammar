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

std::string Store::generateNT(const std::string& base)
{
	std::string newNT = "";
	newNT += base;

	// append digit
	newNT.append("_");
	for (size_t i = 0; i < 200; i++)
	{
		if (!this->ntExists(newNT + std::to_string(i)))
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

bool Store::existsInCollection(const std::string& str, std::vector<std::string>& collection)
{
	for (std::string s : collection)
	{
		if (s == str) return true;
	}
	return false;
}

std::vector<std::pair<std::string, std::string>> Store::crossJoin(const std::vector<std::string>& A, const std::vector<std::string>& B)
{
	std::vector<std::pair<std::string, std::string>> result;
	for (unsigned i = 0; i < A.size(); i++) 
	{
		for (unsigned j = 0; j < B.size(); j++) 
		{
			std::pair<std::string, std::string> temp = { A[i], B[j] };
			result.push_back(temp);
		}
	}
	return result;
}

void Store::addGrammar(const Grammar& grammar)
{
	Grammar* g = new Grammar(grammar);
	this->grammars.push_back(g);
}

Grammar* Store::getGrammarById(const int& id)
{
	for (Grammar * g : this->grammars)
	{
		if (g->getId() == id) return g;
	}

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

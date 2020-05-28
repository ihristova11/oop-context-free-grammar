#include "Grammar.h"

Grammar::Grammar()
{
	// implement
}

Grammar::Grammar(const std::vector<std::string>& e, const std::vector<std::string>& v, const std::string& s, const std::vector<Rule> r)
{
	// implement
}

std::string Grammar::getId()
{
	return this->id;
}

std::string Grammar::toString()
{
	// todo: implement -> should serialize the grammar
	std::string res = this->id + "\n" + startVariable + "\n";
	res += this->terminals.size() + "\n";
	for (std::string t : this->terminals)
	{
		res += t + " ";
	}
	res += "\n";
	res += this->variables.size() + "\n";
	for (std::string v : this->variables)
	{
		res += v + " ";
	}
	res += "\n";
	res += this->rules.size() + "\n";
	for (int i = 0; i < this->rules.size(); i++)
	{
		res += i + " ";
		res += this->rules[i]->toString() + "\n";
	}

	return std::string();
}
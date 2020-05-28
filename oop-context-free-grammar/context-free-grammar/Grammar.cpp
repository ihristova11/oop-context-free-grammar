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
	return std::string();
}
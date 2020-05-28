#include "Rule.h"

Rule::Rule(const std::string& nonTerminal, const std::vector<std::string>& product)
	: nonTerminal(nonTerminal), product(product)
{ }

std::string Rule::toString()
{
	std::string res = nonTerminal + "->";
	for (std::string s : product)
	{
		res.append(s + " ");
	}
	return res;
}

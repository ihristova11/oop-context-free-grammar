#include "Rule.h"

std::string Rule::toString()
{
	std::string res = nonTerminal + " -> ";
	for (std::string s : product)
	{
		res += s + " ";
	}
	return res;
}

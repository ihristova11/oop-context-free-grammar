#include "Validator.h"

bool Validator::isValidInputFile(std::string)
{
	return true;
}

bool Validator::isValidParametersCount(const int&, const int&)
{
	return true;
}

bool Validator::hasParameters(const int&)
{
	return true;
}

bool Validator::isMinParametersCount(const int&, const int&)
{
	return true;
}

bool Validator::isValidGrammarId(const std::string& id, const std::vector<Grammar*>& grammars)
{
	for (Grammar* g : grammars)
	{
		if (g->getId() == id)
			return true;
	}
	return false;
}

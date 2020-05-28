#include "Validator.h"

bool Validator::isValidInputFile(std::string file)
{
	int size = file.size();
	std::string res = "";
	for (size_t i = 1; i <= 4; i++)
	{
		res += file[size - i];
	}

	return res == "txt.";
}

bool Validator::isValidParametersCount(const int& expected, const int& actual)
{
	return expected == actual;
}

bool Validator::hasParameters(const int& size)
{
	return size > 1;
}

bool Validator::isMinParametersCount(const int& actual, const int& min)
{
	return min <= actual;
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

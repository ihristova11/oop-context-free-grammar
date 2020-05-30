#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <vector>

#include "Grammar.h"

/// <summary>
/// Validator is a static class containing different functions for checking parameters validity
/// </summary>
class Validator
{
public:
	/// <summary>
	/// validates input file
	/// </summary>
	/// <param name="date">a string representation of file path</param>
	/// <returns>bool</returns>
	static bool isValidInputFile(std::string);

	/// <summary>
	/// validates parameters count
	/// </summary>
	/// <param name="expected"></param>
	/// <param name="actual"></param>
	/// <returns>bool</returns>
	static bool isValidParametersCount(const int&, const int&);

	/// <summary>
	/// checks if parameters count is > 1
	/// </summary>
	/// <param name="size"></param>
	/// <returns>bool</returns>
	static bool hasParameters(const int&);

	/// <summary>
	/// checks if minimum parameters are provided
	/// </summary>
	/// <param name="actual"></param>
	/// <param name="min"></param>
	/// <returns>bool</returns>
	static bool isMinParametersCount(const int&, const int&);

	/// <summary>
	/// checks if there is grammar with this id in the collection
	/// </summary>
	/// <param name="id"></param>
	/// <param name="grammars"></param>
	/// <returns>bool</returns>
	static bool isValidGrammarId(const int&, const std::vector<Grammar*>&);
};

#endif // !VALIDATOR_H

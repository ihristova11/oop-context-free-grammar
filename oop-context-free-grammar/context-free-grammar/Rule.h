#ifndef RULE_H
#define RULE_H

#include <string>
#include <vector>

/// <summary>
/// Rule model containing nonTerminal and product values
/// </summary>
class Rule
{
public:
	Rule(const std::string&);
	Rule(const std::string&, const std::vector<std::string>&);

	/// <summary>
	/// toString() implementation
	/// </summary>
	/// <returns>std::string</returns>
	std::string toString();
private:
	std::string nonTerminal; // S ->
	std::vector<std::string> product; // aA

	std::string createNonTerminal(const std::string&);
	std::vector<std::string> createProduct(const std::string&);
};

#endif // !RULE_H

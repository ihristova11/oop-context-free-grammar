#ifndef RULE_H
#define RULE_H

#include <string>
#include <vector>

class Rule
{
public:
	Rule(const std::string&, const std::vector<std::string>&);
	std::string toString();
private:
	std::string nonTerminal; // S ->
	std::vector<std::string> product; // aA
};

#endif // !RULE_H

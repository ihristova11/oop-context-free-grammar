#ifndef RULE_H
#define RULE_H

#include <string>
#include <vector>

class Rule
{
private:
	std::string nonTerminal; // S ->
	std::vector<std::string> product; // aA
};

#endif // !RULE_H

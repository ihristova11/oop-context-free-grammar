#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <vector>
#include <string>

#include "Rule.h"

class Grammar
{
public:
	Grammar(); // generate with unique id
	Grammar(const std::vector<std::string>& e, const std::vector<std::string>& v,
		const std::string& s, const std::vector<Rule> r);

	std::string getId();
	std::string toString();
private:
	std::string id;
	std::vector<std::string> terminals; // E
	std::vector<std::string> variables; // chars? // V
	std::string startVariable; // S
	std::vector<Rule> rules; // R
};

#endif // !GRAMMAR_H

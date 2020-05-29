#include "Rule.h"

Rule::Rule(const std::string& rule)
{
	this->nonTerminal = this->createNonTerminal(rule);
	this->product = this->createProduct(rule);
}

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

std::string Rule::createNonTerminal(const std::string& fullRule)
{
	return fullRule.substr(0, 1);
}

std::vector<std::string> Rule::createProduct(const std::string& fullRule)
{
	std::vector<std::string> product;
	std::string pr = fullRule.substr(3);

	size_t pos = 0;
	std::string res;
	while ((pos = pr.find('|')) != std::string::npos) {
		res = pr.substr(0, pos);
		product.push_back(res);
		pr.erase(0, pos + 1);
	}
	product.push_back(pr);
	return product;
}

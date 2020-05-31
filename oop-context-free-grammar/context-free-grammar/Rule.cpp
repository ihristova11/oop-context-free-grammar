#include "Rule.h"

Rule::Rule(const std::string& rule)
{
	this->id = this->generateId();
	this->nonTerminal = this->createNonTerminal(rule);
	this->product = this->createProduct(rule);
}

Rule::Rule(const std::string& nonTerminal, const std::vector<std::string>& product)
	: nonTerminal(nonTerminal), product(product)
{
	this->id = this->generateId();
}

Rule::Rule(const Rule& other)
{
	this->id = other.id;
	this->nonTerminal = other.nonTerminal;
	this->product = other.product;
}

Rule& Rule::operator=(const Rule& other)
{
	if (this != &other)
	{
		this->id = other.id;
		this->nonTerminal = other.nonTerminal;
		this->product = other.product;
	}
	return *this;
}

Rule::~Rule()
{
	this->product.clear();
}

int Rule::generateId()
{
	static int idC = 0;
	return ++idC;
}

int Rule::getId()
{
	return id;
}

std::string Rule::getNonTerminal()
{
	return this->nonTerminal;
}

std::vector<std::string> Rule::getProduct()
{
	return this->product;
}

void Rule::setNonTerminal(const std::string& nt)
{
	this->nonTerminal = nt;
}

std::string Rule::toString()
{
	std::string res = nonTerminal + "->";
	for (size_t ind = 0; ind < this->product.size(); ind++)
	{
		res.append(this->product[ind]);
		if (ind != this->product.size() - 1) res.append("|");
	}
	return res;
}

std::string Rule::createNonTerminal(const std::string& fullRule)
{
	size_t found = fullRule.find("->");
	std::string nt;
	nt.assign(fullRule, 0, found);
	return nt;
}

std::vector<std::string> Rule::createProduct(const std::string& fullRule)
{
	std::vector<std::string> product;
	size_t found = fullRule.find("->");
	std::string pr = fullRule.substr(found + 2);

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

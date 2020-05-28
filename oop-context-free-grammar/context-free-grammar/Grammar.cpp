#include "Grammar.h"

Grammar::Grammar()
{
	// implement
}

Grammar::Grammar(const std::vector<std::string>& e, const std::vector<std::string>& v, const std::string& s, const std::vector<Rule> r)
{
	// implement
}

Grammar::~Grammar()
{
	this->rules.clear();
}

std::string Grammar::getId()
{
	return this->id;
}

std::vector<Rule*> Grammar::getRules()
{
	return this->rules;
}

void Grammar::addRule(const std::string& r)
{
	// split the string and create a rule by given parameters
	// destroy it in destructor

	//todo: implement this!!!
	std::string nonTerminal = "";
	std::vector<std::string> product;

	Rule* rule = new Rule(nonTerminal, product);

	this->rules.push_back(rule);
}

void Grammar::removeRule(const int& n)
{
	this->rules.erase(this->rules.begin() + n);
}

std::string Grammar::toString()
{
	// todo: implement -> should serialize the grammar
	std::string res = this->id + "\n" + startVariable + "\n";
	res += this->terminals.size() + "\n";
	for (std::string t : this->terminals)
	{
		res += t + " ";
	}
	res += "\n";
	res += this->variables.size() + "\n";
	for (std::string v : this->variables)
	{
		res += v + " ";
	}
	res += "\n";
	res += this->rules.size() + "\n";
	for (int i = 0; i < this->rules.size(); i++)
	{
		res += i + " ";
		res += this->rules[i]->toString() + "\n";
	}

	return std::string();
}
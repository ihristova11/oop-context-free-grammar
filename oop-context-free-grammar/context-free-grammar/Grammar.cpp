#include "Grammar.h"
#include "Engine.h"

Grammar::Grammar()
{
	// implement
	static int grammarId = 0;
	this->id = ++grammarId;
}

Grammar::Grammar(const std::vector<std::string>& e, const std::vector<std::string>& v,
	const std::string& s, const std::vector<Rule*>& r)
{
	// generate id for the grammar (may use static variable)
	static int grammarId = 0;
	this->id = ++grammarId;

	this->variables = v;
	this->terminals = e;
	this->startVariable = s;
	this->rules = r;
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
	std::string res = this->id + "\n";
	res.append(startVariable + "\n");
	res.append(std::to_string(this->terminals.size()) + "\n");
	for (std::string t : this->terminals)
	{
		res.append(t + " ");
	}
	res.append("\n");
	res.append(std::to_string(this->variables.size()) + "\n");
	for (std::string v : this->variables)
	{
		res.append(v + " ");
	}
	res.append("\n");
	res.append(std::to_string(this->rules.size()) + "\n");
	for (size_t i = 0; i < this->rules.size(); i++)
	{
		res.append(std::to_string(i) + "\n");
		res.append(this->rules[i]->toString() + "\n");
	}

	return res;
}
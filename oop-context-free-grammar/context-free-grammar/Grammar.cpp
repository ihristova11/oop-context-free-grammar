#include "Grammar.h"
#include "Engine.h"

Grammar::Grammar()
	:terminals(), variables(), startVariable(), rules()
{
	this->id = generateId();
}

Grammar::Grammar(const std::vector<std::string>& e, const std::vector<std::string>& v,
	const std::string& s, const std::vector<Rule*>& r)
{
	this->id = generateId();
	this->variables = v;
	this->terminals = e;
	this->startVariable = s;
	this->rules = r;
}

Grammar::Grammar(const int& id, const std::vector<std::string>& e, const std::vector<std::string>& v, const std::string& s, const std::vector<Rule*>& r)
{
	this->id = id;
	this->variables = v;
	this->terminals = e;
	this->startVariable = s;
	this->rules = r;
}

Grammar::Grammar(const Grammar& other)
{
	this->id = other.id;
	this->terminals = other.terminals;
	this->variables = other.variables;
	this->rules = other.rules;
	this->startVariable = other.startVariable;
}

Grammar::Grammar(const Grammar& other, bool autoGenerateId)
{
	if (autoGenerateId)	this->id = generateId();
	else this->id = other.id;

	this->terminals = other.terminals;
	this->variables = other.variables;
	this->rules = other.rules;
	this->startVariable = other.startVariable;
}

Grammar& Grammar::operator=(const Grammar& other)
{
	if (this != &other)
	{
		this->id = other.id;
		this->terminals = other.terminals;
		this->variables = other.variables;
		this->rules = other.rules;
		this->startVariable = other.startVariable;
	}
	return *this;
}

Grammar::~Grammar()
{
	this->rules.clear();
}

void Grammar::setId(const int& id)
{
	this->id = id;
}

void Grammar::setStartVariable(const std::string& sv)
{
	this->startVariable = sv;
}

void Grammar::replace(const std::string& found, const std::string& repl, std::string& str)
{
	std::string res;
	int index = 0;
	while (true) {
		index = str.find(found, index);
		if (index == std::string::npos) break;
		str.replace(index, found.size(), repl); // may break because of found.size() != repl.size()
		index += repl.size();
	}
}

int Grammar::getId()
{
	return id;
}

std::vector<Rule*> Grammar::getRules()
{
	return this->rules;
}

std::string Grammar::getStartVariable()
{
	return this->startVariable;
}

std::vector<std::string> Grammar::getVariables()
{
	return this->variables;
}

void Grammar::renameDuplicates(const std::string& varName, const std::string& newVarName)
{
	if (this->startVariable == varName)	this->startVariable = newVarName;

	for (Rule* r : this->rules)
	{
		if (r->getNonTerminal() == varName) r->setNonTerminal(newVarName);
		for (std::string v : r->getProduct())
		{
			// find and replace string
			this->replace(varName, newVarName, v);
		}
	}
}

bool Grammar::terminalExists(const std::string& t)
{
	for (std::string terminal : this->terminals)
	{
		if (terminal == t) return true;
	}
	return false;
}

bool Grammar::variableExists(const std::string& var)
{
	for (std::string s : this->variables)
	{
		if (s == var) return true;
	}
	return false;
}

std::vector<std::string> Grammar::getTerminals()
{
	return this->terminals;
}

void Grammar::addRule(const std::string& r)
{
	this->rules.push_back(new Rule(r));
}

void Grammar::addRule(const Rule& r)
{
	this->rules.push_back(new Rule(r));
}

void Grammar::removeRule(const int& n)
{
	this->rules.erase(this->rules.begin() + n - 1);
}

std::string Grammar::toString()
{
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
	for (Rule* r : this->rules)
	{
		res.append(std::to_string(r->getId()) + "\n");
		res.append(r->toString() + "\n");
	}

	return res;
}

int Grammar::generateId()
{
	static int grammarId = 0;
	return ++grammarId;
}

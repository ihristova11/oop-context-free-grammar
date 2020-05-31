#include "Grammar.h"
#include "Engine.h"

#include <sstream>

Grammar::Grammar()
	:terminals(), nonTerminals(), startVariable(), rules()
{
	this->id = generateId();
}

Grammar::Grammar(const std::vector<char>& e, const std::vector<std::string>& v,
	const std::string& s, const std::vector<Rule*>& r)
{
	this->id = generateId();
	this->nonTerminals = v;
	this->terminals = e;
	this->startVariable = s;
	this->rules = r;
}

Grammar::Grammar(const int& id, const std::vector<char>& e, const std::vector<std::string>& v, const std::string& s, const std::vector<Rule*>& r)
{
	this->id = id;
	this->nonTerminals = v;
	this->terminals = e;
	this->startVariable = s;
	this->rules = r;
}

Grammar::Grammar(const Grammar& other)
{
	this->id = other.id;
	this->terminals = other.terminals;
	this->nonTerminals = other.nonTerminals;
	this->rules = other.rules;
	this->startVariable = other.startVariable;
}

Grammar::Grammar(const Grammar& other, bool autoGenerateId)
{
	if (autoGenerateId)	this->id = generateId();
	else this->id = other.id;

	this->terminals = other.terminals;
	this->nonTerminals = other.nonTerminals;
	this->rules = other.rules;
	this->startVariable = other.startVariable;
}

Grammar& Grammar::operator=(const Grammar& other)
{
	if (this != &other)
	{
		this->id = other.id;
		this->terminals = other.terminals;
		this->nonTerminals = other.nonTerminals;
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
	return this->nonTerminals;
}

bool Grammar::ntExists(const std::string& nt)
{
	if (this->getStartVariable() == nt) return true;
	for (std::string s : this->getVariables())
	{
		if (s == nt) return true;
	}
	return false;
}

bool Grammar::isNonTerminal(const std::string& s) const
{
	if (s.length() == 1) return s[0] >= 'A' && s[0] <= 'Z';
	if (s.length() == 2 || s.length() == 3) return false;

	bool correctNumber = true;
	for (unsigned i = 2; correctNumber && i < s.length() - 1; i++)
	{
		if (i == 2)	correctNumber = s[i] >= '1' && s[i] <= '9';		//A_0_ is considered incorrect
		else correctNumber = s[i] >= '0' && s[i] <= '9';
	}
	return (s[0] >= 'A' && s[0] <= 'Z') && (s[1] == '_') && correctNumber && (s[s.length() - 1] == '_');
}

bool Grammar::isExistingNonTerminal(const std::string& nt) const
{
	for (auto n : this->nonTerminals)
	{
		if (n == nt) return true;
	}
	return false;
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

bool Grammar::terminalExists(const char& t)
{
	for (char terminal : this->terminals)
	{
		if (terminal == t) return true;
	}
	return false;
}

bool Grammar::variableExists(const std::string& var)
{
	for (std::string s : this->nonTerminals)
	{
		if (s == var) return true;
	}
	return false;
}

std::vector<char> Grammar::getTerminals()
{
	return this->terminals;
}

bool Grammar::addNonTerminal(const std::string& nt)
{
	if (isNonTerminal(nt) && !isExistingNonTerminal(nt)) {
		this->nonTerminals.push_back(nt);
		return true;
	}

	return false;
}

bool Grammar::addRule(const std::string& rule)
{
	if (rule.empty()) return false;
	size_t found = rule.find("->");
	// not found
	if (found == std::string::npos)	return false;

	// get nt, before ->
	std::string nt;
	nt.assign(rule, 0, found);
	// remove S->
	std::string product = rule.substr(found + 2); 
	// get product
	std::vector<std::string> pResult;
	std::istringstream iss(product);
	for (std::string s; iss >> s; )
		pResult.push_back(s);
	Rule* r = new Rule{ nt, pResult };

	this->rules.push_back(r);

	return true;
	// delete memory

}

void Grammar::addRule(const Rule& r)
{
	Rule* temp = new Rule(r); // delete
	this->rules.push_back(temp);
}

void Grammar::removeRule(const int& n)
{
	this->rules.erase(this->rules.begin() + n - 1);
}

std::string Grammar::toString()
{
	std::string res = ""; 
	res.append(startVariable + "\n");
	res.append(std::to_string(this->terminals.size()) + "\n");
	for (char t : this->terminals)
	{
		res += t;
		res.append(" ");
	}
	res.append("\n");
	res.append(std::to_string(this->nonTerminals.size()) + "\n");
	for (std::string v : this->nonTerminals)
	{
		res.append(v + " ");
	}
	res.append("\n");
	res.append(std::to_string(this->rules.size()) + "\n");
	for (Rule* r : this->rules)
	{
		res.append(r->toString() + "\n");
	}

	return res;
}

int Grammar::generateId()
{
	static int grammarId = 0;
	return ++grammarId;
}

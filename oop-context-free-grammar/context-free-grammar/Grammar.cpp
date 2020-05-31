#include "Grammar.h"
#include "Engine.h"

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

void Grammar::setStartTerminal(const std::string& sv)
{
	this->startVariable = sv;
}

int Grammar::getId()
{
	return id;
}

std::vector<Rule*> Grammar::getRules()
{
	return this->rules;
}

std::string Grammar::getStartNonTerminal()
{
	return this->startVariable;
}

std::vector<std::string> Grammar::getNonTerminals()
{
	return this->nonTerminals;
}

bool Grammar::isNonTerminal(const std::string& s) const
{
	if (s.length() == 1) return s[0] >= 'A' && s[0] <= 'Z';
	if (s.length() == 2 || s.length() == 3) return false;

	bool correctNumber = true;
	for (unsigned i = 2; correctNumber && i < s.length() - 1; i++)
	{
		if (i == 2)	correctNumber = s[i] >= '1' && s[i] <= '9';
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

bool Grammar::terminalExists(const char& t)
{
	for (char terminal : this->terminals)
	{
		if (terminal == t) return true;
	}
	return false;
}

bool Grammar::nonTerminalExists(const std::string& var)
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
	std::string nt;
	nt.assign(rule, 0, found);
	if (!isExistingNonTerminal(nt)) return false;

	Rule* r = new Rule(rule); // deleted in destr
	this->rules.push_back(r);
	return true;
}

void Grammar::addRule(const Rule& r)
{
	Rule* temp = new Rule(r); // deleted in destr
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

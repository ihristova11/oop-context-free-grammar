#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <vector>
#include <string>

#include "Rule.h"

/// <summary>
/// Grammar model representing a context-free grammar implementation
/// </summary>
class Grammar
{
public:
	Grammar();
	Grammar(const std::vector<char>& e, const std::vector<std::string>& v,
		const std::string& s, const std::vector<Rule*>& r);
	Grammar(const Grammar&);
	Grammar(const Grammar&, bool);
	Grammar& operator=(const Grammar&);
	~Grammar();

	/// <summary>
	/// sets start terminal value
	/// </summary>
	void setStartTerminal(const std::string&);

	/// <summary>
	///  <returns>id</returns>
	/// </summary>
	int getId();

	/// <summary>
	/// getter
	/// </summary>
	/// <returns>std::vector<Rule*></returns>
	std::vector<Rule*> getRules();

	/// <summary>
	/// <returns>startNonTerminal</returns>
	/// </summary>
	std::string getStartNonTerminal();

	/// <summary>
	/// <returns>nonTerminals value</returns>
	/// </summary>
	std::vector<std::string> getNonTerminals();

	/// <summary>
	/// <returns>bool values if terminal exists</returns>
	/// </summary>
	bool terminalExists(const char& t);

	/// <summary>
	/// <returns>bool if nonterminal exists</returns>
	/// </summary>
	bool nonTerminalExists(const std::string& var);

	/// <summary>
	/// <returns>terminals</returns>
	/// </summary>
	std::vector<char> getTerminals();

	/// <summary>
	/// adds new nonterminal
	/// </summary>
	/// <returns>bool if the operation is successful</returns>
	bool addNonTerminal(const std::string&);

	/// <summary>
	/// adds Rule* to the vector
	/// </summary>
	/// <param name="r">std::string param</param>
	bool addRule(const std::string&);

	/// <summary>
	/// adds Rule* to the vector
	/// </summary>
	/// <param name="r">Rule*</param>
	void addRule(const Rule& r);

	/// <summary>
	/// removes Rule*
	/// </summary>
	/// <param name="n">int index</param>
	void removeRule(const int&);

	/// <summary>
	/// toString() implementation
	/// </summary>
	/// <returns>std::string</returns>
	std::string toString();
private:
	int id; // int ?
	std::vector<char> terminals; // E
	std::vector<std::string> nonTerminals; // V
	std::string startVariable; // S
	std::vector<Rule*> rules; // R

	/// <summary>
	/// autogenerates id, not exposed for the user to update it
	/// </summary>
	/// <returns>int id</returns>
	int generateId();

	/// <summary>
	/// <returns>bool if string is nonterminal</returns>
	/// </summary>
	bool isNonTerminal(const std::string& s) const;

	/// <summary>
	/// <returns>bool if string is existing nonterminal</returns>
	/// </summary>
	bool isExistingNonTerminal(const std::string& nt) const;
};

#endif // !GRAMMAR_H

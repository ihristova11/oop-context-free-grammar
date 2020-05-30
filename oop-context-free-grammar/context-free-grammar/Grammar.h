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
	Grammar(const std::vector<std::string>& e, const std::vector<std::string>& v,
		const std::string& s, const std::vector<Rule*>& r);
	Grammar(const int&, const std::vector<std::string>& e, const std::vector<std::string>& v,
		const std::string& s, const std::vector<Rule*>& r);
	Grammar(const Grammar&);
	Grammar(const Grammar&, bool);
	Grammar& operator=(const Grammar&);
	~Grammar();

	void setId(const int&);

	void setStartVariable(const std::string&);

	/// <summary>
	/// getter
	/// </summary>
	/// <returns>id</returns>
	int getId();

	/// <summary>
	/// getter
	/// </summary>
	/// <returns>std::vector<Rule*></returns>
	std::vector<Rule*> getRules();

	std::string getStartVariable();

	std::vector<std::string> getVariables();

	bool terminalExists(const std::string& t);

	std::vector<std::string> getTerminals();

	/// <summary>
	/// adds Rule* to the vector
	/// </summary>
	/// <param name="r">std::string param</param>
	void addRule(const std::string&);

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
	std::vector<std::string> terminals; // E
	std::vector<std::string> variables; // chars? // V
	std::string startVariable; // S
	std::vector<Rule*> rules; // R

	int generateId();
};

#endif // !GRAMMAR_H

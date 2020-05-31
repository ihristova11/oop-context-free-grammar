#ifndef RULE_H
#define RULE_H

#include <string>
#include <vector>

/// <summary>
/// Rule model containing nonTerminal and product values
/// </summary>
class Rule
{
public:
	Rule(const std::string&);
	Rule(const std::string&, const std::vector<std::string>&);
	Rule(const Rule&);
	Rule& operator=(const Rule&);
	~Rule();

	/// <summary>
	/// autogenerates id, not exposed to the user
	/// </summary>
	/// <returns>int id</returns>
	int generateId();

	/// <summary>
	/// <returns>rule id</returns>
	/// </summary>
	int getId();
	
	/// <summary>
	/// <returns>nonTerminal string</returns>
	/// </summary>
	std::string getNonTerminal();

	/// <summary>
	/// <returns>product vector<string></returns>
	/// </summary>
	std::vector<std::string> getProduct();

	/// <summary>
	/// sets the nonterminal value
	/// </summary>
	void setNonTerminal(const std::string&);

	/// <summary>
	/// toString() implementation
	/// </summary>
	/// <returns>std::string</returns>
	std::string toString();
private:
	int id;
	std::string nonTerminal; // S ->
	std::vector<std::string> product; // aA

	/// <summary>
	/// creates nonterminal from full rule string
	/// </summary>
	std::string createNonTerminal(const std::string&);

	/// <summary>
	/// creates product from full rule string
	/// </summary>
	std::vector<std::string> createProduct(const std::string&);
};

#endif // !RULE_H

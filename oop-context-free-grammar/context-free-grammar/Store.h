#ifndef STORE_H
#define STORE_H

#include <vector>
#include "Grammar.h"

/// <summary>
/// Store class combining different grammar info as a single unit
/// </summary>
class Store
{
public:
	Store();
	Store(const std::vector<Grammar*>&);
	~Store();

	/// <summary>
	/// finds a Grammar by id
	/// </summary>
	/// <param name="id"></param>
	/// <returns>Grammar* or nullptr if not found</returns>
	Grammar* findGrammarById(const int&);

	/// <summary>
	/// generates nonterminal value
	/// </summary>
	/// <param name="base">base string used for generation</param>
	/// <returns>string</returns>
	std::string generateNT(const std::string& base);

	/// <summary>
	/// <returns>bool if nonterminal exists</returns>
	/// </summary>
	bool ntExists(const std::string&);

	/// <summary>
	/// <returns>bool if string exists in collection</returns>
	/// </summary>
	bool existsInCollection(const std::string&, std::vector<std::string>&);

	/// <summary>
	/// adds Grammar to Store</returns>
	/// </summary>
	void addGrammar(const Grammar&);

	/// <summary>
	/// <returns>Grammar*</returns>
	/// </summary>
	Grammar* getGrammarById(const int&);

	/// <summary>
	/// clears vector values
	/// </summary>
	void clearGrammars();

	/// <summary>
	/// getter
	/// </summary>
	/// <returns>std::vector<Grammar*></returns>
	std::vector<Grammar*> getGrammars();
private:
	std::vector<Grammar*> grammars;
};

#endif // !STORE_H

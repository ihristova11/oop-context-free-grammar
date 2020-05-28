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
	Store(const std::vector<Grammar*>&);

	/// <summary>
	/// finds a Grammar by id
	/// </summary>
	/// <param name="id"></param>
	/// <returns>Grammar* or nullptr if not found</returns>
	Grammar* findGrammarById(const std::string&);
	
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

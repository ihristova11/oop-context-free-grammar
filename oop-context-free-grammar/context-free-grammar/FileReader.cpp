#include "FileReader.h"

void FileReader::read(const std::string& file, Store* store)
{
	int grammarsCount = 0;
	int terminalsCount = 0;
	int variablesCount = 0;
	int rulesCount = 0;
	std::string id;
	std::string startVariable;
	std::string variable;
	std::vector<std::string> terminals;
	std::string terminal;
	std::string rule;
	std::vector<std::string> variables;
	std::vector<Rule*> rules;

	std::fstream ifs;
	ifs.open(file, std::ios::in);
	if (ifs)
	{
		ifs >> grammarsCount;
		for (size_t i = 0; i < grammarsCount; i++)
		{
			ifs.ignore();
			std::getline(ifs, id);
			std::getline(ifs, startVariable);

			ifs >> terminalsCount;
			for (size_t j = 0; j < terminalsCount; j++)
			{
				ifs >> terminal;
				terminals.push_back(terminal);
			}
			ifs >> variablesCount;
			for (size_t i = 0; i < variablesCount; i++)
			{
				ifs >> variable;
				variables.push_back(variable);
			}
			ifs.ignore();
			ifs >> rulesCount;
			ifs.ignore();
			for (size_t i = 0; i < rulesCount; i++)
			{
				ifs.ignore();
				ifs >> rule;
				rules.push_back(new Rule(rule));
			}

			store->addGrammar(Grammar(id, terminals, variables, startVariable, rules));
			variable.clear();
			terminals.clear();
			rules.clear();
		}
	}
	else
	{
		// create new file
		ifs.open(file, std::ios::out);
	}
	ifs.close();
}

#include "AddRuleCommand.h"
#include "Validator.h"

AddRuleCommand::AddRuleCommand(Store* store)
{
	ICommand::store = store;
}

std::string AddRuleCommand::execute(const std::vector<std::string>& params)
{
	std::string id = params[1];
	std::string rule = params[2]; // A->aA|Ab|AA todo: should be able to split this

	if (Validator::isValidParametersCount(3, params.size())
		&& Validator::isValidGrammarId(id, this->store->getGrammars()))
	{
		Grammar* g = this->store->findGrammarById(id);
		
	}

	return std::string();
}

std::string AddRuleCommand::toString()
{
	return Constants::AddRuleCommandName;
}

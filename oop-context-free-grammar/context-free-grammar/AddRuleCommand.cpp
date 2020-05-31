#include "AddRuleCommand.h"
#include "Validator.h"

AddRuleCommand::AddRuleCommand(Store* store)
{
	ICommand::store = store;
}

std::string AddRuleCommand::execute(const std::vector<std::string>& params)
{
	if (Validator::isValidParametersCount(3, params.size()))
	{
		int id = std::stoi(params[1]);
		std::string rule = params[2]; 

		if (Validator::isValidGrammarId(id, this->store->getGrammars()))
		{
			Grammar* g = this->store->findGrammarById(id);
			return g->addRule(rule) ? Constants::Success : Constants::InvalidParameters;
		}
		else return Constants::NoGrammar;
	}
	else return Constants::InvalidParameters;
}

std::string AddRuleCommand::toString()
{
	return Constants::AddRuleCommandName;
}

#include "RemoveRuleCommand.h"
#include "Validator.h"

RemoveRuleCommand::RemoveRuleCommand(Store* store)
{
	ICommand::store = store;
}

std::string RemoveRuleCommand::execute(const std::vector<std::string>& params)
{
	if (Validator::isValidParametersCount(3, params.size()))
	{
		int id = std::stoi(params[1]);
		int n = std::stoi(params[2]);

		if (Validator::isValidGrammarId(id, this->store->getGrammars()))
		{
			Grammar* g = this->store->findGrammarById(id);
			// check for index
			if (g->getRules().size() >= n)
				g->removeRule(n);
			else return Constants::NoRule;
		}
		else return Constants::NoGrammar;
	}
	else
	{
		return Constants::InvalidParameters;
	}
	return Constants::Success;
}

std::string RemoveRuleCommand::toString()
{
	return Constants::RemoveRuleCommandName;
}

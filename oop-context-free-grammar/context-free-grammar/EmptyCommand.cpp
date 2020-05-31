#include "EmptyCommand.h"
#include "Validator.h"

EmptyCommand::EmptyCommand(Store* store)
{
	ICommand::store = store;
}

std::string EmptyCommand::execute(const std::vector<std::string>& parameters)
{
	if (Validator::isValidParametersCount(2, parameters.size()))
	{
		int id = std::stoi(parameters[1]);
		if (Validator::isValidGrammarId(id, this->store->getGrammars()))
		{
			return Constants::ToImplement;
		}
		else return Constants::NoGrammar;
	}
	else return Constants::InvalidParameters;
}

std::string EmptyCommand::toString()
{
	return Constants::EmptyCommandName;
}

#include "ChomskifyCommand.h"
#include "Validator.h"
#include <map>

ChomskifyCommand::ChomskifyCommand(Store* store)
{
	ICommand::store = store;
}

std::string ChomskifyCommand::execute(const std::vector<std::string>& parameters)
{
	return Constants::ToImplement;
}

std::string ChomskifyCommand::toString()
{
	return Constants::ChomskifyCommandName;
}

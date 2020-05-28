#include "ExitCommand.h"

ExitCommand::ExitCommand(Store* store)
{
	ICommand::store = store;
}

std::string ExitCommand::execute(const std::vector<std::string>&)
{
	// no need for checking the parameters
	return Constants::ExitResponse;
}

std::string ExitCommand::toString()
{
	return Constants::ExitCommandName;
}

#include "CloseCommand.h"

CloseCommand::CloseCommand(Store* store)
{
	ICommand::store = store;
}

std::string CloseCommand::execute(const std::vector<std::string>&)
{
	// no parameters to validate
	this->store->clearGrammars();

	return Constants::CloseSuccess;
}

std::string CloseCommand::toString()
{
	return Constants::CloseCommandName;
}

#include "SaveCommand.h"

SaveCommand::SaveCommand(Store*, FileWriter*)
{
	ICommand::store = store;
	this->writer = writer;
}

std::string SaveCommand::execute(const std::vector<std::string>&)
{
	// not checking parameters
	this->writer->write(this->writer->lastFile, store);

	return Constants::Success;
}

std::string SaveCommand::toString()
{
	return Constants::SaveCommandName;
}

#include "OpenCommand.h"
#include "Validator.h"

OpenCommand::OpenCommand(Store* store, FileReader* reader, FileWriter* writer)
	: reader(reader), writer(writer)
{
	ICommand::store = store;
}

std::string OpenCommand::execute(const std::vector<std::string>& parameters)
{
	bool error = true;
	if (Validator::isValidParametersCount(2, parameters.size()))
	{
		std::string fileName = parameters[1];
		if (Validator::isValidInputFile(fileName)) //.txt files only
		{
			error = false;
			this->reader->read(fileName, this->store);
			return Constants::Success;
		}
	}

	if (error)
		return Constants::InvalidParameters;
}

std::string OpenCommand::toString()
{
	return Constants::OpenCommandName;
}

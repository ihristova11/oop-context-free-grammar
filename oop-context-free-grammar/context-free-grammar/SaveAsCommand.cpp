#include "SaveAsCommand.h"
#include "Validator.h"

SaveAsCommand::SaveAsCommand(Store*, FileWriter*)
{
	ICommand::store = store;
}

std::string SaveAsCommand::execute(const std::vector<std::string>& parameters)
{
	bool error = true;
	if (Validator::isValidParametersCount(2, parameters.size()))
	{
		std::string fileName = parameters[1];

		//validate filename
		if (Validator::isValidInputFile(fileName))
		{
			error = false;
			this->writer->write(this->writer->lastFile, this->store);
			return Constants::Success;
		}
		else { return Constants::InvalidFileName; }
	}

	if (error) { return Constants::InvalidParameters; }
}

std::string SaveAsCommand::toString()
{
	return Constants::SaveAsCommandName;
}

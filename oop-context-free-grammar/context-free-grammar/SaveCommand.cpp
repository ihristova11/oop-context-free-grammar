#include "SaveCommand.h"
#include "Validator.h"

SaveCommand::SaveCommand(Store*, FileWriter*)
{
	ICommand::store = store;
	this->writer = writer;
}

std::string SaveCommand::execute(const std::vector<std::string>& parameters)
{
	if (parameters.size() > 2) // has parameters 
	{
		std::string id = parameters[1];
		if (Validator::isValidGrammarId(id, this->store->getGrammars()))
		{
			std::string file = parameters[2];
			if (Validator::isValidInputFile(file))
			{
				Grammar* g = this->store->findGrammarById(id);
				this->writer->write(file, g);
			}
			else
			{
				return Constants::InvalidFileName;
			}
		}
		else
		{
			return Constants::NoGrammar;
		}
	}
	else
	{
		this->writer->write(this->writer->lastFile, store);
	}

	return Constants::Success;
}

std::string SaveCommand::toString()
{
	return Constants::SaveCommandName;
}

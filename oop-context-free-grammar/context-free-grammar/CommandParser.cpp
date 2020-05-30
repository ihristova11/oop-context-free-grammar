#include "CommandParser.h"

#include "AddRuleCommand.h"
#include "ChomskifyCommand.h"
#include "ChomskyCommand.h"
#include "ConcatCommand.h"
#include "CykCommand.h"
#include "EmptyCommand.h"
#include "IterCommand.h"
#include "ListCommand.h"
#include "PrintCommand.h"
#include "RemoveRuleCommand.h"
#include "UnionCommand.h"

#include "OpenCommand.h"
#include "ExitCommand.h"
#include "CloseCommand.h"
#include "SaveAsCommand.h"
#include "SaveCommand.h"
#include "HelpCommand.h"

CommandParser::CommandParser(Store* store, FileReader* reader, FileWriter* writer)
	: store(store), reader(reader), writer(writer)
{
	seedCommands();
}

CommandParser::~CommandParser()
{
	// delete commands

	this->commands.clear(); // calls destructor for all commands
	std::cout << "Command parser destructor called!" << std::endl;
}

ICommand* CommandParser::parseCommand(const std::string& fullCommand)
{
	std::string commandName = this->split(fullCommand, ' ')[0];
	ICommand* command = nullptr;
	for (size_t i = 0; i < commands.size(); i++)
	{
		if ((this->commands[i])->toString() == commandName) // check if it works this way
		{
			command = this->commands[i];
			break;
		}
	}
	return command;
}

std::vector<std::string> CommandParser::parseParameters(const std::string& fullCommand)
{
	return split(fullCommand, ' ');
}

void CommandParser::seedCommands()
{
	// register commands
	this->commands.push_back(new AddRuleCommand(this->store));
	this->commands.push_back(new ChomskifyCommand());
	this->commands.push_back(new ChomskyCommand());
	this->commands.push_back(new ConcatCommand());
	this->commands.push_back(new CykCommand());
	this->commands.push_back(new EmptyCommand());
	this->commands.push_back(new IterCommand(this->store));
	this->commands.push_back(new ListCommand(this->store));
	this->commands.push_back(new PrintCommand(this->store));
	this->commands.push_back(new RemoveRuleCommand(this->store));
	this->commands.push_back(new UnionCommand(this->store));

	this->commands.push_back(new OpenCommand(this->store, this->reader, this->writer));
	this->commands.push_back(new CloseCommand(this->store));
	this->commands.push_back(new ExitCommand(this->store));
	this->commands.push_back(new HelpCommand());
	this->commands.push_back(new SaveAsCommand(this->store, this->writer));
	this->commands.push_back(new SaveCommand(this->store, this->writer));
}

template <typename T>
void CommandParser::split(const std::string& s, char delim, T result) {
	std::istringstream iss(s);
	std::string item;
	while (std::getline(iss, item, delim)) {
		*result++ = item;
	}
}

std::vector<std::string> CommandParser::split(const std::string& s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

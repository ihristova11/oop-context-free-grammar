#include "Engine.h"
#include "Constants.h"
#include "CommandParser.h"

#include <iostream>

Engine::Engine()
{
	this->writer = new FileWriter();
	this->reader = new FileReader();
	this->parser = new CommandParser(this->reader, this->writer);
}

Engine& Engine::getInstance()
{
	static Engine instance;
	return instance;
}

Engine::~Engine()
{
	delete writer;
	delete reader;
	delete parser;
}

void Engine::start()
{
	while (true)
	{
		std::string commandString;
		// read the command here
		std::cout << Constants::EnterCommand;
		std::getline(std::cin, commandString);

		this->processCommand(commandString);
	}
}

void Engine::processCommand(std::string commandAsString)
{
	if (commandAsString.empty())
		throw "Command cannot be empty!"; // should have a test for this

	ICommand* command = (this->parser)->parseCommand(commandAsString);

	// todo: test it with values with spaces
	// parse parameters
	std::vector<std::string> parameters = (this->parser)->parseParameters(commandAsString);

	if (command != nullptr)
	{
		if (begin && command->toString() != Constants::OpenCommandName
			&& command->toString() != Constants::ExitCommandName)
		{
			std::cout << Constants::OpenCommandOnly << std::endl;
		}
		else
		{
			std::string executionResult = command->execute(parameters);
			std::cout << executionResult << std::endl;
			this->begin = command->toString() == Constants::CloseCommandName;
		}
	}
	else
	{
		std::cout << Constants::InvalidCommand << std::endl;
	}
}
#include "Engine.h"
#include "Constants.h"
#include "CommandParser.h"

#include <iostream>

Engine::Engine()
{
	this->store = new Store();
	this->writer = new FileWriter();
	this->reader = new FileReader();
	this->parser = new CommandParser(this->store, this->reader, this->writer);
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
	// seed(); // for testing purposes only

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
			std::cout << executionResult << std::endl << std::endl;
			this->begin = command->toString() == Constants::CloseCommandName;
		}
	}
	else
	{
		std::cout << Constants::InvalidCommand << std::endl;
	}
}

// for testing purposes only
void Engine::seed()
{
	std::vector<Grammar*> grammars =
	{
		new Grammar(std::vector<char>{'a', 'b'}, std::vector<std::string>(),
		"S", std::vector<Rule*>{new Rule("S", std::vector<std::string>{"aSbb|SS|#"})}),

		new Grammar(std::vector<char>{'a', 'b'}, std::vector<std::string>{"A"},
		"S", std::vector<Rule*>{new Rule("S", std::vector<std::string>{"aSba|SS|#"}), new Rule("A", std::vector<std::string> {"a"})}),

		new Grammar(std::vector<char>{'a', 'c'}, std::vector<std::string>(),
		"S", std::vector<Rule*>{new Rule("S", std::vector<std::string>{"aSccc|SS|#"})})
	};
	this->store = new Store(grammars);

	this->writer->write("D:/Git/oop-context-free-grammar/oop-context-free-grammar/context-free-grammar/grammars.txt", this->store);
}
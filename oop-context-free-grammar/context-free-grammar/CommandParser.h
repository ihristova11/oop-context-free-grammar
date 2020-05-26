#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include "ICommandParser.h"
#include "FileWriter.h"
#include "FileReader.h"

#include <iostream>
#include <sstream>

class CommandParser : public ICommandParser
{
public:
	CommandParser(FileReader*, FileWriter*);
	virtual ~CommandParser();
	virtual ICommand* parseCommand(const std::string&) override;
	virtual std::vector<std::string> parseParameters(const std::string&) override;
private:
	std::vector<ICommand*> commands;
	FileReader* reader;
	FileWriter* writer;

	void seedCommands();

	template <typename T>
	void split(const std::string& s, char delim, T result);
	std::vector<std::string> split(const std::string& s, char delim);
};

#endif // !COMMAND_PARSER_H

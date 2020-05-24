#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

namespace Constants
{
	const std::string OpenCommandName = "open";
	const std::string CloseCommandName = "close";
	const std::string SaveCommandName = "save";
	const std::string SaveAsCommandName = "saveas";
	const std::string HelpCommandName = "help";
	const std::string ExitCommandName = "exit";

	const std::string OpenCommandOnly = "You should open a file before entering other commands.";
	const std::string InvalidCommand = "Enter a valid command.";
	const std::string EnterCommand = "Enter a command: ";
}

#endif // !CONSTANTS_H


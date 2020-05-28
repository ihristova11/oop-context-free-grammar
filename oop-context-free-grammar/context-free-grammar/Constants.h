#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

/// <summary>
/// Stores constant std::strings
/// </summary>
namespace Constants
{
	const std::string OpenCommandName = "open";
	const std::string CloseCommandName = "close";
	const std::string SaveCommandName = "save";
	const std::string SaveAsCommandName = "saveas";
	const std::string HelpCommandName = "help";
	const std::string ExitCommandName = "exit";

	const std::string AddRuleCommandName = "addRule";
	const std::string ChomskifyCommandName = "chomskify";
	const std::string ChomskyCommandName = "chomsky";
	const std::string ConcatCommandName = "concat";
	const std::string CykCommandName = "cyk";
	const std::string EmptyCommandName = "empty";
	const std::string IterCommandName = "iter";
	const std::string ListCommandName = "list";
	const std::string PrintCommandName = "print";
	const std::string RemoveRuleCommandName = "removeRule";
	const std::string UnionCommandName = "union";


	const std::string OpenCommandOnly = "You should open a file before entering other commands.";
	const std::string InvalidCommand = "Enter a valid command.";
	const std::string EnterCommand = "Enter a command: ";
	const std::string Success = "Command completed successfully!";
}

#endif // !CONSTANTS_H


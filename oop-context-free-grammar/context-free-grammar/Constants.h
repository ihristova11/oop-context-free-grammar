#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

/// <summary>
/// Stores constant std::strings
/// </summary>
namespace Constants
{
	// file commands
	const std::string OpenCommandName = "open";
	const std::string CloseCommandName = "close";
	const std::string SaveCommandName = "save";
	const std::string SaveAsCommandName = "saveas";
	const std::string HelpCommandName = "help";
	const std::string ExitCommandName = "exit";

	// commands
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

	// error messages
	const std::string OpenCommandOnly = "You should open a file before entering other commands.";
	const std::string InvalidCommand = "Enter a valid command.";
	const std::string EnterCommand = "Enter a command: ";
	const std::string Success = "Command completed successfully!";
	const std::string InvalidParameters = "Please enter valid parameters!";
	const std::string NoGrammar = "No such grammar exists!";
	const std::string NoRule = "Invalid rule index!";
	const std::string InvalidFileName = "You can save only txt files.";

	const std::string ExitResponse = "Exiting the program...";
	const std::string CloseSuccess = "Successfully closed file!";

	const std::string HelpRensponse = "The following commands are supported:\n>open <file> - opens < file>\n>close - closes currently opened file\n>save - saves the currently open file\n>saveas <file> - saves the currently open file in <file>\n>help - prints this information\n>exit - exists the program\n>list - displays a list of grammar ids\n>print <id> - displays info for a grammar\n>save <id> <filename> - saves grammar in file\n>addRule <id> <rule> - adds rule\n>removeRule <id> <n> - removes rule\n>union <id1> <id2> - union on two grammars\n>concat <id1> <id2> - concatenation on two grammars\n>chomsky <id> - check if a grammar is in chomsky form\n>cyk <id> - checks for a word is member of L(G)\n>iter <id> - Kleene star on grammar\n>empty <id> - checks if L(G) is empty\n>chomskify <id> - converts grammar in chomsky form";

}

#endif // !CONSTANTS_H


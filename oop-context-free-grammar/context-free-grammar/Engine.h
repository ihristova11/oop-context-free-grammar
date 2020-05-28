#ifndef ENGINE_H
#define ENGINE_H

#include "FileReader.h"
#include "ICommandParser.h"
#include "FileWriter.h"
#include "Store.h"

#include <string>
#include <vector>

/// <summary>
/// Engine uses a Singleton implementation responsible for managing the program logic flow.
/// </summary>
class Engine
{
public:
	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;

	/// <summary>
	/// getInstance() function for exposing the static instance
	/// </summary>
	/// <returns>a static instance of type Engine</returns>
	static Engine& getInstance();

	/// <summary>
	/// Process management entry point
	/// </summary>
	virtual void start();
private:
	Engine();
	virtual ~Engine();

	Store* store;
	std::vector<ICommand*> commands;
	ICommandParser* parser;
	FileWriter* writer;
	FileReader* reader;
	bool begin = true;

	/// <summary>
	/// Executes the logic behind processing a command
	/// </summary>
	/// <param name="commandAsString">containing the command name with its parameters</param>
	void processCommand(std::string);
};

#endif // !ENGINE_H

#ifndef ENGINE_H
#define ENGINE_H

#include "FileReader.h"
#include "ICommandParser.h"
#include "FileWriter.h"

#include <string>
#include <vector>

class Engine
{
public:
	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;

	static Engine& getInstance();
	virtual void start();
private:
	Engine();
	virtual ~Engine();

	std::vector<ICommand*> commands;
	ICommandParser* parser;
	FileWriter* writer;
	FileReader* reader;
	bool begin = true;

	void processCommand(std::string);
};

#endif // !ENGINE_H

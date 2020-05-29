#ifndef OPEN_COMMAND_H
#define OPEN_COMMAND_H

#include "ICommand.h"
#include "FileWriter.h"
#include "FileReader.h"

/// <summary>
/// OpenCommand is used for opening an existing file or creating a new one if such does not exist
/// </summary>
class OpenCommand : public ICommand
{
public:
	OpenCommand(Store*, FileReader*, FileWriter* writer);

	virtual std::string execute(const std::vector<std::string>&) override;
	virtual std::string toString() override;

private:
	FileReader* reader;
	FileWriter* writer;
};

#endif // !OPEN_COMMAND_H

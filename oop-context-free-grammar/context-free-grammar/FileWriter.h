#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include <vector>
#include <string>
#include <fstream>

#include "Grammar.h"
#include "Store.h"

/// <summary>
/// FileWriter responsible for writing to .txt files only
/// </summary>
class FileWriter
{
public:
	/// <summary>
	/// stores the last file opened
	/// </summary>
	std::string lastFile;

	/// <summary>
	/// writes to .txt file
	/// </summary>
	/// <param name="file">file path</param>
	/// <param name="arr">vector that stores the information to be written</param>
	void write(const std::string& file, Store* store);

	/// <summary>
	/// writes to .txt file
	/// </summary>
	/// <param name="file">file path</param>
	/// <param name="grammar">Grammar* to write</param>
	void write(const std::string& file, Grammar* grammar);
};

#endif // !FILE_WRITER_H
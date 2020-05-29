#ifndef FILE_READER_H
#define FILE_READER_H

#include <fstream>
#include <string>

#include "Grammar.h"
#include "Store.h"

/// <summary>
/// FileReader responsible for reading from .txt files only
/// </summary>
class FileReader
{
public:
	/// <summary>
	/// reads from .txt file
	/// </summary>
	/// <param name="file">file path</param>
	/// <param name="arr">vector in which the information is stored</param>
	void read(const std::string&, Store*);
};
#endif // !FILE_READER_H

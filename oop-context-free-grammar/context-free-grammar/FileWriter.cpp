#include "FileWriter.h"

void FileWriter::write(const std::string& file, Store* store)
{
	std::ofstream ofs;
	ofs.open(file, std::ios::out);
	ofs.seekp(0);
	ofs << store->getGrammars().size() << std::endl;
	for (Grammar* g : store->getGrammars())
	{
		ofs << g->toString() << std::endl;
	}

	ofs.close();
}

void FileWriter::write(const std::string& file, Grammar* grammar)
{
	std::ofstream ofs;
	ofs.open(file, std::ios::out);
	ofs.seekp(0);
	ofs << grammar->toString() << std::endl;
	ofs.close();
}

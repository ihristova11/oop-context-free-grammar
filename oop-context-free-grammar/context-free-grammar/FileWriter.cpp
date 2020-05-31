#include "FileWriter.h"

void FileWriter::write(const std::string& file, Store* store)
{
	std::ofstream ofs;
	ofs.open(file, std::ios::out);
	if (ofs)
	{
		ofs.seekp(0);
		ofs << store->getGrammars().size() << std::endl;
		for (Grammar* g : store->getGrammars())
		{
			ofs << g->toString() << std::endl;
		}
	}

	ofs.close();
}

void FileWriter::write(const std::string& file, Grammar* grammar)
{
	std::ofstream ofs;
	ofs.open(file, std::ios::out);	
	if (ofs)
	{
		ofs.seekp(0);
		ofs << 1 << std::endl;
		ofs << grammar->toString() << std::endl;
	}
	ofs.close();
}

#pragma once
#include <string>

class File
{
public:

	File(std::string);
	File();
	~File();

	void writeBinary(std::string&);
private:
	

	std::string filename;
};

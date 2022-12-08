#pragma once
#include <string>
#include"HuffmanTree.h"

class EncodingDecoding
{
public:

	EncodingDecoding(std::string);
	~EncodingDecoding();
	void Encoding();
	void Decoding();
	
private:
	const std::map<char, std::uint64_t> createUniqueElements();
	void writeBinary(std::map<char, std::string> , std::string );
	void readFile();

	std::string filename;
	std::string data;
	HuffmanTree *tree;
};

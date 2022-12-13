#pragma once
#include <string>
#include<map>
#include<vector>
#include"HuffmanTree.h"

class EncodingDecoding
{
public:

	EncodingDecoding(std::string);
	~EncodingDecoding();
	void Encoding();
	std::string Decoding();
	
private:
	const std::map<char, std::uint64_t> createUniqueElements();
	void writeBinary(std::map<char, std::string> , std::string );
	std::string readBinary();
	void readFile();
	std::string DecodeElements(std::vector<unsigned char>&,std::map<std::string, char>&);

	std::string filename;
	std::string data;
	HuffmanTree *tree;
};

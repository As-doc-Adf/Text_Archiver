#include"EndoingDecoding.h"
#include"bitset.h"
#include<fstream>
#include<iostream>
#include <errno.h>
#include<map>
#include<set>
#include<vector>
#include <algorithm>
#if !defined(__PRETTY_FUNCTION__) && !defined(__GNUC__)
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

EncodingDecoding::EncodingDecoding(std::string fileName) :filename(fileName) { readFile(); createUniqueElements(); tree = new HuffmanTree(createUniqueElements()); }

EncodingDecoding::~EncodingDecoding(){}

void EncodingDecoding::Encoding()
{
	auto Table = tree->getTable();
	std::string message = "";
	for (auto i = data.begin(); i != data.end(); i++) {
		message += Table.find(*i)->second;
		std::cout << Table.find(*i)->second << ' ' << *i << std::endl ;
		std::cout << message << std::endl;
	}
	//std::cout << message << std::endl;
	writeBinary(Table, message);
}

std::string EncodingDecoding::Decoding()
{
	return readBinary();
}

std::string EncodingDecoding::readBinary() {
	std::ifstream ifs(filename+".huff", std::ios::binary);
	std::ifstream ifsT(filename + ".table");
	if (!ifs.is_open() || !ifsT.is_open()) {
		std::cerr << "Error in [" << __PRETTY_FUNCTION__ << "]:" << errno << std::endl;
		return __PRETTY_FUNCTION__;
	}

	ifs.seekg(0, std::ios::end);
	auto fileSize = ifs.tellg();

	std::vector<unsigned char> fileData(fileSize);
	std::map<std::string, char> table;
	char* data = reinterpret_cast<char*>(new int[fileSize]);

	ifs.read(data, fileSize);
	
	//std::cout << fileData.size() << std::endl;
	for (auto c = 0; c < fileSize; c++) {
		fileData[c] = data[c];
	}
	std::cout << 'x' << '\n';
	std::string buff;
	while (std::getline(ifsT, buff)) {
		unsigned char byte = buff[0];
		buff.erase(buff.begin());
		table.insert(std::make_pair(buff, byte));
	}

	ifsT.close();
	ifs.close();

	buff = DecodeElements(fileData, table);
	return buff;
}

void EncodingDecoding::writeBinary(std::map<char, std::string> table,std::string bitMessage)
{
   // std::cout << bitMessage.size() << std::endl;
	std::ofstream ofs(filename + ".huff", std::ios::binary);
	std::ofstream ofsT(filename + ".table");
	if (!ofs || !ofsT) {
		std::cerr << "Error in [" << __PRETTY_FUNCTION__ << "]:" << errno << std::endl;
		return;
	}

	for (auto i = table.begin(); i != table.end(); i++) {
		ofsT << i->first << i->second << '\n';
	}


	ofsT.close();

	Bitset _bitset(bitMessage);
	auto bits = _bitset.getBitset();
	auto size = bits.second;
	auto chr = bits.first;
	std::cout << ':' << bits.first << ':' << std::endl;

    ofs.write((const char*)&(chr), size);
    ofs.close();
}

void EncodingDecoding::readFile()
{
	std::ifstream ifs(filename);
	if (!ifs.is_open()) {
		std::cerr << "Error in [" << __PRETTY_FUNCTION__ << "]:" << errno << std::endl;
		return;
	}
	std::string buff;
	data = "";
	while (std::getline(ifs, buff)) {
		data += buff;
	}
	ifs.close();
	
}

std::string EncodingDecoding::DecodeElements(std::vector<unsigned char>& data, std::map<std::string, char>& table)
{

	std::string buff = {};
	std::string originStr = {};
	std::string str = {};
	for (const auto& chr:data) {
		for (auto i = 0; i <= 7; i++) {
			auto bit = (chr >> i) & 1;
			if (bit == 1) {
				str += '1';
			}
			else {
				str += '0';
			}
			
		}
		//std::cout << chr << 'N';
	}
	

	std::cout << str << ":LET" << std::endl;
	for (const auto& c : str) {
		//std::cout << c << std::endl;
		buff += c;
		if (table.count(buff) == 1) {
			auto itr = table.find(buff);
			//std::cout << itr->first << ' ' << itr->second << ' ' << buff << std::endl;
			originStr += itr->second;
			buff = {};
		}
	}
	return originStr;
}

const std::map<char, std::uint64_t> EncodingDecoding::createUniqueElements()
{

	std::set<char> letters(data.begin(),data.end());
	std::map<char, std::uint64_t> UniqueElements;
	for (auto itr = letters.begin(); itr != letters.end(); itr++) {
		UniqueElements.insert(std::make_pair(*itr, std::count(data.begin(), data.end(), *itr)));
	}

	return UniqueElements;
}

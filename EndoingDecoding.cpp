#include"EndoingDecoding.h"
#include"bitset.h"
#include<fstream>
#include<iostream>
#include <errno.h>
#include<map>
#include<set>
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
	}
	writeBinary(Table, message);
}


void EncodingDecoding::writeBinary(std::map<char, std::string> table,std::string bitMessage)
{
   // std::cout << bitMessage.size() << std::endl;
	std::ofstream ofs(filename + ".huff", std::ios::binary);
	std::ofstream ofsT(filename + ".table", std::ios::binary);
	if (!ofs || !ofsT) {
		std::cerr << "Error in [" << __PRETTY_FUNCTION__ << "]:" << errno << std::endl;
		return;
	}

	for (auto i = table.begin(); i != table.end(); i++) {
		ofsT.write((const char*)&(i->first), 1);
		ofsT.write((const char*)&(i->second), 1);
	}


	ofsT.close();

	Bitset _bitset(bitMessage);
	auto bits = _bitset.getBitset();
    ofs.write((const char*)&(bits.first), bits.second);
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

const std::map<char, std::uint64_t> EncodingDecoding::createUniqueElements()
{

	std::set<char> letters(data.begin(),data.end());
	std::map<char, std::uint64_t> UniqueElements;
	for (auto itr = letters.begin(); itr != letters.end(); itr++) {
		UniqueElements.insert(std::make_pair(*itr, std::count(data.begin(), data.end(), *itr)));
	}

	return UniqueElements;
}

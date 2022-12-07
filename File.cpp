#include"File.h"
#include"bitset.h"
#include<fstream>
#include<iostream>
#include <errno.h>
#include<map>
#include<boost/dynamic_bitset.hpp>
#if !defined(__PRETTY_FUNCTION__) && !defined(__GNUC__)
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif


File::File(){}

File::File(std::string _FileName):filename(_FileName) {}

File::~File(){}

void File::writeBinary(std::string& bitMessage)
{
    std::cout << bitMessage.size() << std::endl;
	std::string new_filename = filename + ".huff";
	std::ofstream ofs(filename, std::ios::binary);
	if (!ofs) {
		std::cerr << "Error in [" << __PRETTY_FUNCTION__ << "]:" << errno << std::endl;
		return;
	}
	Bitset _bitset(bitMessage);
	auto bits = _bitset.getBitset();

         ofs.write((const char*)&(bits.first), bits.second);

    ofs.close();
}

#pragma once
#include<utility>
#include<string>

class Bitset
{
public:
	Bitset(std::string);
	~Bitset();

	std::string getOriginal();
	std::pair<unsigned char*, size_t> getBitset();

private:
	void makeBitset();
	void setBit(unsigned char&, uint8_t, bool);
	std::string original;
	unsigned char* mybitset;
	size_t bitset_size;
};
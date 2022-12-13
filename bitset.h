#pragma once
#include<utility>
#include<string>

class Bitset
{
public:
	Bitset(std::string);
	Bitset();
	~Bitset();

	const std::string getOriginal();
	const std::string getOriginal(std::string);
	const std::pair<unsigned char*, size_t> getBitset();

private:
	void makeBitset();
	bool getBit(const unsigned char&, uint8_t);
	void setBit(unsigned char&, uint8_t, bool);
	std::string original;
	unsigned char* mybitset;
	size_t bitset_size;
};
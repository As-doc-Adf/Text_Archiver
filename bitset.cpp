#include"bitset.h"
const std::pair<unsigned char*, size_t> Bitset::getBitset()
{
	return std::make_pair(mybitset,bitset_size);
}

void Bitset::makeBitset()
{
	size_t k = 0;
	size_t counter = 8 - (original.size() % 8);
	for (size_t i = counter; i < original.size()+ counter; i++) {

		if (original[i- counter] == '1') {
			setBit(mybitset[k], i % 8, 1);
		}
		else if (original[i- counter] == '0') {
			setBit(mybitset[k], i % 8, 0);
		}
		else {
			setBit(mybitset[k], i % 8, 0);
		}
		
		if (i!= 0 && i % 8 == 0) { k++;}
	}
}

void Bitset::setBit(unsigned char &byte, uint8_t numberOfbit , bool state)
{
	if (numberOfbit >= 1 && numberOfbit <= 8) {
		auto bit = (byte >> numberOfbit) & 1;
		if (bit != state) {
			byte ^= 1 << numberOfbit;
		}
	}

	for (int i = 0; i < 8; i++) {
		auto bit = (byte >> i) & 1;
	}
}


Bitset::Bitset(std::string str):original(str)
{
	bitset_size = static_cast<size_t>(static_cast<double>(str.size()) / 8 + 1);
	mybitset = new unsigned char[bitset_size];
	for (auto i = 0; i < bitset_size; i++) {
		mybitset[i] = 0;
	}
	makeBitset();
}

Bitset::~Bitset(){}

const std::string Bitset::getOriginal()
{
	return original;
}

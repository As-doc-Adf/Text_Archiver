#include"bitset.h"
#include<iostream>
const std::pair<unsigned char*, size_t> Bitset::getBitset()
{
	std::cout << mybitset << std::endl;
	return std::make_pair(mybitset,bitset_size);
}

void Bitset::makeBitset()
{
	size_t k = 0;
	size_t counter = 8 - (original.size() % 8);
	for (size_t i = counter; i < original.size()+ counter; i++) {

		if (original[i- counter] == '1') {
			//std::cout << 1;
			setBit(mybitset[k], i % 8, 1);
		}
		else if (original[i- counter] == '0') {
			//std::cout << 0;
			setBit(mybitset[k], i % 8, 0);
		}
		else {
			//std::cout << 0;
			setBit(mybitset[k], i % 8, 0);
		}
		
		if (i != 0 && i % 8 == 0) { std::cout << mybitset[k] << std::endl;  k++; }
	}
}

void Bitset::setBit(unsigned char &byte, uint8_t numberOfbit , bool state)
{
	if (state == 1) {
		byte |= 1 << numberOfbit;
	}
	else {
		byte &= ~(1 << numberOfbit);
	}
}

bool Bitset::getBit(const unsigned char &byte, uint8_t numberOfbit) {
	if (numberOfbit >= 0 && numberOfbit <= 7) {
		auto bit = (byte >> numberOfbit) & 1;
		return bit;
	}
	return false;
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

Bitset::Bitset():original("") {
	bitset_size = static_cast<size_t>(static_cast<double>(original.size()) / 8 + 1);
	mybitset = new unsigned char[bitset_size];
	for (auto i = 0; i < bitset_size; i++) {
		mybitset[i] = 0;
	}
}

Bitset::~Bitset(){}

const std::string Bitset::getOriginal()
{
	return original;
}

const std::string Bitset::getOriginal(std::string str) {
	std::string origin = {};
	for (const unsigned char& chr : str) {
		for (uint8_t i = 1; i <= 8; i++) {
			auto bit = getBit(chr, i);
			if (bit == 1) {
				origin += '1';
			}
			else {
				origin += '0';
			}
		}
	}
	original = origin;
	return origin;
}

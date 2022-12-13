#include"EndoingDecoding.h"
#include<iostream>

int main() {
	EncodingDecoding compression("file.txt");
	compression.Encoding();
	
	EncodingDecoding decompression("file.txt");
	std::cout << std::endl << decompression.Decoding() << std::endl << "Decoding successfully!";
	return 0;
}
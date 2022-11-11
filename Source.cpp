#include"HuffmanTree.h"

int main() {

	std::map<char, std::uint64_t> elm;
	elm.insert(std::pair<char, std::uint64_t>('A', 2));
	elm.insert(std::pair<char, std::uint64_t>('E', 2));
	elm.insert(std::pair<char, std::uint64_t>('I', 3));
	elm.insert(std::pair<char, std::uint64_t>('S', 6));
	elm.insert(std::pair<char, std::uint64_t>('T', 1));
	elm.insert(std::pair<char, std::uint64_t>('U', 1));
	elm.insert(std::pair<char, std::uint64_t>('Y', 2));
	elm.insert(std::pair<char, std::uint64_t>(' ', 4));
	elm.insert(std::pair<char, std::uint64_t>('\n', 1));

	HuffmanTree tree(elm);

	return 0;
}
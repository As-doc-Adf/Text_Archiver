#pragma once
#include"BinaryTree.h"
#include<map>
#include<string>
class HuffmanTree
{
public:
	HuffmanTree(const std::map<char, std::uint64_t>&);
	~HuffmanTree();
	std::map<char, std::string> getTable();
	

private:
	BinaryTree GetHuffmanTree();
	BinaryTree huffmanTree;
	const std::map<char, std::uint64_t> Elements;
};
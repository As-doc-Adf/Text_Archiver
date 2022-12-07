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
	
	void createTable(std::shared_ptr<Node>,std::string);
	BinaryTree GetHuffmanTree();
	BinaryTree huffmanTree;
	std::map<char, std::string> Table;
	const std::map<char, std::uint64_t> Elements;
};
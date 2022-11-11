#include"HuffmanTree.h"
#include"PriorityQueue.h"
#include<iostream>
HuffmanTree::HuffmanTree(const std::map<char, std::uint64_t>& elements):Elements(elements)
{
	if (Elements.empty()) {
		std::cout << "HuffmanTree[Warning]:Map is empty, possible error !" << std::endl;
	}
	huffmanTree = GetHuffmanTree();
}

BinaryTree HuffmanTree::GetHuffmanTree()
{
	PriorityQueue pq;

	for (const auto& [key,value] : Elements) {
		auto newNode = std::make_shared<Node>(value, key );
		BinaryTree tree(newNode);
		pq.insert(tree);
	}

	while (pq.size() != 0)
	{
		BinaryTree tree1 = pq.remove();
		if (pq.size() == 0) {
			std::cout << std::endl << tree1.getFrequance() << std::endl;
			return tree1;
		}

			BinaryTree tree2 = pq.remove();
			auto newNode = std::make_shared<Node>();
			newNode.get()->addChild(tree1.getRoot());
			newNode.get()->addChild(tree2.getRoot());

			BinaryTree mainTree(newNode);
			pq.insert(mainTree);	
	}

	return BinaryTree();
}

std::map<char, std::string> HuffmanTree::getTable()
{
	return std::map<char, std::string>();

}

HuffmanTree::~HuffmanTree()
{
}
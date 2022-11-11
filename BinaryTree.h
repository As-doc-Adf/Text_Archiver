#pragma once
#include<memory>
#include"Node.h"

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	BinaryTree(std::shared_ptr<Node>);

	 std::uint64_t getFrequance();
	 std::shared_ptr<Node> getRoot();

private:

	std::shared_ptr<Node> root;

};
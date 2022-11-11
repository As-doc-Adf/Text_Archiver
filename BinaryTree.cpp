#include"BinaryTree.h"

BinaryTree::BinaryTree()
{
	root = std::shared_ptr<Node>(new Node);
}

BinaryTree::~BinaryTree()
{

}

BinaryTree::BinaryTree(std::shared_ptr<Node> _root) :root(_root) {}

std::uint64_t BinaryTree::getFrequance()
{
	return root.get()->getFrequance();
}

std::shared_ptr<Node> BinaryTree::getRoot()
{
	return root;
}
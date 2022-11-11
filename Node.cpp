#include"Node.h"

void Node::addChild(std::shared_ptr<Node> newNode) {
	if (leftNode.get() == nullptr) {
		leftNode = newNode;
	}
	else {
		if (leftNode.get()->getFrequance() <= newNode.get()->getFrequance()) {
			rightNode = newNode;
		}
		else {
			rightNode = leftNode;
			leftNode = newNode;
		}
	}
	this->frequance += newNode.get()->getFrequance();
}

inline std::shared_ptr<Node> Node::getLeftNode() {
	return this->leftNode;
}

inline std::shared_ptr<Node> Node::getRightNode()
{
	return this->rightNode;
}

inline std::uint64_t Node::getFrequance() {
	return this->frequance;
}

char Node::getSymbol()
{
	return this->symbol;
}

inline bool Node::isLeaf()
{
	return leftNode && rightNode;
}
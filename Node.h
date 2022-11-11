#pragma once
#include <cstdint>
#include<memory>

class Node
{
private:
	std::uint64_t frequance;
	std::shared_ptr<Node> leftNode;
	std::shared_ptr<Node> rightNode;
	char symbol;

public:
	Node():frequance(0),symbol(0) {}
	Node(std::uint64_t _frequance, char _symbol) :frequance(_frequance), symbol(_symbol) {}

	inline std::shared_ptr<Node> getLeftNode();
	inline std::shared_ptr<Node> getRightNode();
	inline std::uint64_t getFrequance();
	 char getSymbol();
	 bool isLeaf();

	void addChild(std::shared_ptr<Node> newNode);


};
#pragma once
#include"BinaryTree.h"
#include<vector>

class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();

	void insert(BinaryTree& newTree);
	BinaryTree remove();
	size_t size();

private:
	std::vector<BinaryTree> data;
};
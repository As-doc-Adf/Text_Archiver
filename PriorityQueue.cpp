#include"PriorityQueue.h"
PriorityQueue::PriorityQueue()
{
}

PriorityQueue::~PriorityQueue()
{
}

void PriorityQueue::insert(BinaryTree& newTree)
{
	if (data.size() == 0) {
		data.push_back(newTree);
	}
	else {
		for (size_t i = 0; i < data.size(); i++) {
			if (data[i].getFrequance() >= newTree.getFrequance()) {
				data.insert((data.begin() + i), newTree);
				break;
			}
			if (i == data.size() - 1) {
				data.push_back(newTree);
				break;
			}
		}
	}
}

size_t PriorityQueue::size() {
	return data.size();
}

BinaryTree PriorityQueue::remove()
{
	auto tmp = *data.begin();
	data.erase(data.begin());
	return tmp;
}
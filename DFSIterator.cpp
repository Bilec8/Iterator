#include "DFSIterator.h"

/*
	DFSIterator is identical with BDS only queue is replaced with stack.
	(So we are taking elements from top not front.)
*/

DFSIterator::DFSIterator(Graph* g) {
	this->currentStack = new stack<int>;
	this->graph = g;
}

void DFSIterator::reset() {

	this->currentStack->push(this->graph->getMin());

	for (auto vertex : this->graph->verticies) {
		if (vertex->id == this->graph->getMin()) {
			vertex->state = 1;
			break;
		}
	}
}

void DFSIterator::next() {

	if (!this->currentStack->empty()) {
		int current = this->currentStack->top();
		this->currentStack->pop();
		for (auto vertex : this->graph->verticies) {
			if (vertex->id == current) {
				vertex->state = 2;
				for (int i = 0; i < vertex->neighbours.size(); i++) {
					if (vertex->neighbours[i]->state == 0) {
						this->currentStack->push(vertex->neighbours[i]->id);
						vertex->neighbours[i]->state = 1;
						break;
					}
				}

			}
		}
	}

	if (this->currentStack->empty()) {
		for (auto vertex : this->graph->verticies) {
			if (vertex->state == 2) {
				for (auto neigbours : vertex->neighbours) {
					if (neigbours->state == 0) {
						this->currentStack->push(neigbours->id);
						neigbours->state = 1;
						break;
					}
				}
			}
		}
	}

	if (this->currentStack->empty()) {
		for (auto vertex : this->graph->verticies) {
			if (vertex->state == 0) {
				this->currentStack->push(vertex->id);
				vertex->state = 0;
				break;
			}
		}
	}

}

bool DFSIterator::isEnd() {
	if (this->currentStack->empty()) {
		for (int i = 0; i < this->graph->verticies.size(); i++) {
			if (this->graph->verticies[i]->state == 2) {
				return true;
			}
		}
	}
	return false;
}

int DFSIterator::currentKey() {
	if (!this->currentStack->empty()) {
		return this->currentStack->top();
	}
	return -1;
}
#include "BFSIterator.h"

BFSIterator::BFSIterator(Graph* graph) {
	this->currentQueue = new queue<int>;
	this->graph = graph;
}

/*
	Function pushes lowest vertex into queue then changes his state to 1.
*/

void BFSIterator::reset() {

	this->currentQueue->push(this->graph->getMin());

	for (auto vertex : this->graph->verticies) {
		if (vertex->id == this->graph->getMin())
			vertex->state = 1;
		break;
	}
}

/*
	If queue is empty function saves id from element on the top of queue. Then removes him from queue.
	Then function find all neighbours of vertex and pushes them in queue and changes their state to 1.
*/

void BFSIterator::next() {

	if (!this->currentQueue->empty()) {
		int current = this->currentQueue->front();
		this->currentQueue->pop();
		for (auto vertex : this->graph->verticies) {
			if (vertex->id == current) {
				vertex->state = 2;
				for (int i = 0; i < vertex->neighbours.size(); i++) {
					if (vertex->neighbours[i]->state == 0) {
						this->currentQueue->push(vertex->neighbours[i]->id);
						vertex->neighbours[i]->state = 1;
					}
				}
				break;
			}
		}
	}

	/*
		If queue is not empty we check if all vertexies for our graph are discovered. If not we push them to queue.
	*/
	if (this->currentQueue->empty()) {
		for (auto vertex : this->graph->verticies) {
			if (vertex->state == 2) {
				for (auto neigbours : vertex->neighbours) {
					if (neigbours->state == 0) {
						this->currentQueue->push(neigbours->id);
						neigbours->state = 1;
						break;
					}
				}
			}
		}
	}

	/*
		If our first graph is discovered we check if there are some others vertexes that arent discovered.
	*/


	if (this->currentQueue->empty()) {
		for (auto vertex : this->graph->verticies) {
			if (vertex->state == 0) {
				this->currentQueue->push(vertex->id);
				vertex->state = 1;
				break;
			}
		}
	}
}

/*
	Function search all verticies. If all vertecies are discovered return true, else false.
*/


bool BFSIterator::isEnd() {
	if (this->currentQueue->empty()) {
		for (int i = 0; i < this->graph->verticies.size(); i++) {
			if (this->graph->verticies[i]->state == 2) {
				return true;
			}
		}
	}
	return false;
}

/*
	Function is returning current vertex in front of the queue. Else return -1 (Error state)
*/

int BFSIterator::currentKey() {
	if (!this->currentQueue->empty()) {
		return this->currentQueue->front();
	}
	return -1;
}
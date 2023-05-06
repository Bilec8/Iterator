#pragma once
#include "graph.h"
#include <queue>

/*
	All mehods are same from https://www.cs.vsb.cz/dvorsky/Download/AlgoritmyI/ZadaniProjektuPrez.pdf on page 5
*/

class BFSIterator {
private:
	Graph* graph;
	queue<int>* currentQueue;
public:
	BFSIterator(Graph* graph);
	void next();
	void reset();
	bool isEnd();
	int currentKey();
};
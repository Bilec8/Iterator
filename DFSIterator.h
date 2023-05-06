#pragma once
#include "graph.h"
#include <stack>

/*
	All mehods are same from https://www.cs.vsb.cz/dvorsky/Download/AlgoritmyI/ZadaniProjektuPrez.pdf on page 6
*/

class DFSIterator {
private:
	stack<int>* currentStack;
	Graph* graph;
public:
	DFSIterator(Graph* g);
	void reset();
	void next();
	bool isEnd();
	int currentKey();
};
#include "graph.h"
#include "DFSIterator.h"
#include "BFSIterator.h"

int main() {


	/*
		User choose one of 3 text files.
	*/

	int type;
	string filename;

	cout << "Choose the graph you want to select: [from 1 to 3]" << endl;
	cin >> type;

	switch (type) {
	case 1:
		filename = "Graf1.txt";
		break;
	case 2:
		filename = "Graf2.txt";
		break;
	case 3:
		filename = "Graf3.txt";
		break;
	default: filename = "Graf1.txt";
	}

	Graph graph(filename);

	// If files are not in same folfer program will end.

	if (graph.getError() == true) { printf("No files to test.\n"); return 0; }


	DFSIterator Iter(&graph);
	BFSIterator Iter2(&graph);

	// Loop from task on page 5 that passes all verticies and print them to console.

	cout << "Iterator DFS: " << endl;

	for (Iter.reset(); !Iter.isEnd(); Iter.next()) {
		cout << "Current node: " << Iter.currentKey() << endl;
	}

	cout << endl << "Iterator BFS: " << endl;

	// Reseting all states to 0.

	graph.reset();

	for (Iter2.reset(); !Iter2.isEnd(); Iter2.next()) {
		cout << "Current node: " << Iter2.currentKey() << endl;
	}
	cout << endl;

	//graph.coutVertex(); -- I created this to check if graph is correct

	return 0;
}
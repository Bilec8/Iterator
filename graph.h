#pragma once
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


class Vertex {
public:
	int id;								// Every Vertex has own id that repesents value 
	vector <Vertex*> neighbours;		// Vector of neighbours
	int state = 0;						// 0 == undiscovered / 1 == In queue / stack / 2 == discovered

	Vertex(int id) {
		this->id = id;					// Constructor
	}
};

class Graph {
private:
	int min;								// Min is id of "smallest" vertex
	bool isError;
public:
	vector <Vertex*>verticies;				// Vector of all Vertexes;

	Graph(string filename);					// Constructor

	bool loadFromFile(string filename);
	void createEdge(int from, int to);
	void createVertex(int id);
	void findMin();

	int getMin();
	Vertex* findById(int id);
	void reset();							// Reset all states to 0
	bool getError();
	void coutVertex();						// Printing all verticies and neighbours
};										    // (Only for constructiong purpouses)
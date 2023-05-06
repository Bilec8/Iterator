#include "graph.h"

Graph::Graph(string filename) {

	this->min = 0;
	loadFromFile(filename);

}

/*
	Function first search file and create all verticies, then creates neighbours.
	On the end is function which finds vertex with lowest id.
*/

bool Graph::loadFromFile(string filename) {
	ifstream file;
	string text;

	file.open(filename);

	if (file.fail() == 1) {
		this->isError = true;
		file.close();
		return false;
	}
	else {

		while (getline(file, text)) {
			string firstVertex = text.substr(0, text.find(" "));
			string secondVertex = text.substr(text.find(" "));

			this->createVertex(stoi(firstVertex));
			this->createVertex(stoi(secondVertex));
		}

		file.close();
	}

	file.open(filename);

	if (file.fail() == 1) {
		this->isError = true;
		file.close();
		return false;
	}
	else {

		while (getline(file, text)) {
			string firstVertex = text.substr(0, text.find(" "));
			string secondVertex = text.substr(text.find(" "));

			this->createEdge(stoi(firstVertex), stoi(secondVertex));
			this->createEdge(stoi(secondVertex), stoi(firstVertex));
		}

		findMin();

		file.close();
		return true;
	}
}

/*
 Function create new vertex and push him to vector
*/

void Graph::createVertex(int id) {

	if (findById(id) == nullptr) {
		this->verticies.push_back(new Vertex(id));
	}
}

void Graph::createEdge(int from, int to) {
	Vertex* fromVertex = findById(from);
	Vertex* toVertex = findById(to);

	if (fromVertex != nullptr && toVertex != nullptr) {
		fromVertex->neighbours.push_back(toVertex);
	}

}

/*
	Function finds vertex by id. If vertex is found we return him. If not we return nullptr.
*/

Vertex* Graph::findById(int id) {

	for (auto vertex : this->verticies) {
		if (vertex->id == id) {
			return vertex;
		}
	}
	return nullptr;
}

/*
	Function that finds lowest id.
*/

void Graph::findMin() {
	for (int i = 0; i < verticies.size(); i++) {
		if (findById(i) != nullptr) {
			this->min = i;
			break;
		}
	}
}

int Graph::getMin() {
	return this->min;
}

/*
	Function resets all states to 0.
*/

void Graph::reset() {
	for (int i = 0; i < this->verticies.size(); i++) {
		this->verticies[i]->state = 0;
	}
}

bool Graph::getError() {
	return this->isError;
}

/*
	Function that prints all verticies and his neigbours.
*/

void Graph::coutVertex() {

	for (auto verticies : this->verticies) {
		cout << verticies->id << endl;
	}

	cout << endl << endl;

	for (auto vertex : this->verticies) {
		cout << "root: " << vertex->id << endl;
		for (auto neighbours : vertex->neighbours) {
			cout << "\t neighbours: " << neighbours->id << endl;
		}
	}
}
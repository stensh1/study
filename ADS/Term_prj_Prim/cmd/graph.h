// Orshak Ivan, 1321, 10.09.2023
#pragma once

#include <vector>

using namespace std;

class Graph
{
private:
	vector < vector <int> > matrix;
	int num_of_vertexes;
	void setMatrix();
public:
	Graph();
	~Graph();
	void resetGraph(int);
	void generate();
	void setGraph();
	bool isValidEdge(int, int, vector <bool>);
	void mst();
	void print();
};
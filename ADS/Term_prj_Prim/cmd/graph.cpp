// Orshak Ivan, 1321, 10.09.2023
#include <iostream>
#include "graph.h"

Graph::Graph()
{
	num_of_vertexes = (rand() * time(NULL)) % 10;
	setMatrix();
}

void Graph::resetGraph(int num)
{
	num_of_vertexes = num;
	setMatrix();
}

Graph::~Graph()
{
	for (int i = 0; i < num_of_vertexes; i++) matrix[i].clear();

	matrix.clear();
}

void Graph::setMatrix()
{
	vector <int> tmp;

	for (int i = 0; i < num_of_vertexes; i++)
	{
		matrix.push_back(tmp);

		for (int j = 0; j < num_of_vertexes; j++)
			matrix[i].push_back(0);
	}
}

void Graph::generate()
{
	for (int i = 0; i < num_of_vertexes; i++)
		for (int j = 0; j < num_of_vertexes; j++)
			if (j > i)
			{
				matrix[i][j] = (unsigned int)(rand() * time(NULL)) % 10;
				matrix[j][i] = matrix[i][j];
			}
}
void Graph::setGraph()
{
	for (int i = 0; i < num_of_vertexes; i++)
		for (int j = 0; j < num_of_vertexes; j++)
			if (j > i)
			{
				cout << "Edge (" << j << ", " << i << "): ";
				cin >> matrix[i][j];

				if (matrix[i][j] == -1) matrix[i][j] = INT_MAX;
				matrix[j][i] = matrix[i][j];
			}
}

void Graph::mst()
{
	vector<bool> tmp(num_of_vertexes, false);

	tmp[0] = true;
	int edge_count = 0, mincost = 0;

	while (edge_count < num_of_vertexes - 1)
	{
		int min = INT_MAX, a = -1, b = -1;

		for (int i = 0; i < num_of_vertexes; i++)
		{
			for (int j = 0; j < num_of_vertexes; j++)
			{
				if (matrix[i][j] < min) 
				{
					if (isValidEdge(i, j, tmp))
					{
						min = matrix[i][j];
						a = i;
						b = j;
					}
				}
			}
		}

		if (a != -1 && b != -1)
		{
			cout << "Edge " << edge_count++ << ": (" << a << "," << b << ") cost: " << min << endl;
			mincost = mincost + min;
			tmp[b] = tmp[a] = true;
		}
	}

	cout << "MST cost: " << mincost << endl;
}

bool Graph::isValidEdge(int u, int v, vector<bool> inMST)
{
	if (u == v) return false;

	if (inMST[u] == false && inMST[v] == false) return false;
	else if (inMST[u] == true && inMST[v] == true) return false;

	return true;
}

void Graph::print()
{
	for (int i = 0; i < num_of_vertexes; i++)
	{
		for (int j = 0; j < num_of_vertexes; j++) cout << matrix[i][j] << " ";
		cout << endl;
	}
}
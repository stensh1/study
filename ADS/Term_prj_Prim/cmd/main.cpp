// Orshak Ivan, 1321, 10.09.2023
#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
	Graph G;
	int flag = -1, num_of_vertexes = 0;

	cout << "1. Manual input\n2. Generate graph\n";
	cin >> flag;

	switch (flag)
	{
	case 1:
		cout << "Enter number of vertexes: ";
		cin >> num_of_vertexes;
		if (num_of_vertexes > 2) G.resetGraph(num_of_vertexes);
		else { cout << "Wrong value!\n"; return 0; }
		G.setGraph();

		break;
	case 2:
		G.generate();

		break;
	default:
		cout << "Unknown command!\n";

		return 0;
	}

	G.print();
	G.mst();

	return 0;
}
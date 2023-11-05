//Orshak Ivan, 7362, lab 4, 10.12.2018

#include<iostream>
#include <conio.h>
#include "Source.h"

using namespace std;


int main()
{
	avl_tree tree;

	for (int i = 1; i < 9; i++)
		tree.put(i, i);

	tree.draw_tree(1);
	system("pause");

	tree.put(10, 5);
	tree.draw_tree(1);
	system("pause");

	tree.remove(4);
	tree.draw_tree(1);
	system("pause");

	tree.findVal(2);
	system("pause");

	return 0;
}


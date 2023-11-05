// Orshak Ivan, 10.09.2023, 1321
#include <iostream>
#include <algorithm>
#include "tree.h"

static const int WIDTH = 80;
static const int MAXPOWER = 26;

using namespace std;

void Tree::tree_gen(Node* parent_ptr, char depth)
{
	static char data_inc = 'a';

	if (max_depth < depth) max_depth = depth;

	if (parent_ptr == NULL)
	{
		parent_ptr = new Node(data_inc, NULL, depth);
		data_inc++;
		root = parent_ptr;
		depth++;
		num_of_nodes++;
	}

	if (depth < (rand() * time(NULL)) % 5)
	{
		parent_ptr->left_c = new Node(data_inc, parent_ptr, depth);
		data_inc++;
		num_of_nodes++;
		tree_gen(parent_ptr->left_c, depth + 1);
	}

	if (depth < (rand() * time(NULL)) % 5)
	{
		parent_ptr->middle_c = new Node(data_inc, parent_ptr, depth);
		data_inc++;
		num_of_nodes++;
		tree_gen(parent_ptr->middle_c, depth + 1);
	}

	if (depth < (rand() * time(NULL)) % 5)
	{
		parent_ptr->right_c = new Node(data_inc, parent_ptr, depth);
		data_inc++;
		num_of_nodes++;
		tree_gen(parent_ptr->right_c, depth + 1);
	}
}

void Tree::print()
{
	char cnt = 0;

	set_screen(root, 1, 40);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 80; j++)
			cout << screen[i][j];
		//printf("%c", screen[i][j]);
		cout << endl;
	}

	cout << "Path: ";

	for (int i = 0; i < q.size(); i++) cout << q[i] << " ";

	cout << endl;
	cout << "Num of not last nodes: " << num_of_nodes << endl;
}

void Tree::set_screen(Node* ptr, int level, int offset)
{
	if (ptr != NULL)
	{
		if (ptr->dp == max_depth - 1) num_of_nodes--; 

		q.push_back(ptr->get_data());
		set_screen(ptr->left_c, level + 1, offset - (40 >> level) + 1);
		screen[level - 1][offset - 1] = ptr->get_data();
		set_screen(ptr->middle_c, level + 1, offset);
		set_screen(ptr->right_c, level + 1, offset + (40 >> level));
	}
}

Tree::Tree()
{
	num_of_nodes = 0;
	max_depth = -1;
	root = NULL;

	for (char i = 0; i < 8; i++) memset(screen[i], '.', 80);

	q.clear();
}

Tree::~Tree()
{
	q.clear();
}

Node::Node(char data_inc, Node* parent_ptr, char dep)
{
	dp = dep;
	data = data_inc;
	parent = parent_ptr;
	left_c = NULL;
	middle_c = NULL;
	right_c = NULL;
}

char Node::get_data()
{
	return data;
}
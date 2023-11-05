// Orshak Ivan, 10.09.2023, 1321
#include <vector>

using namespace std;

class Node
{
private:
	char data;
public:
	Node* parent, * right_c, * middle_c, * left_c;
	char dp;
	Node(char, Node*, char);
	char get_data();
};

class Tree
{
	friend class Node;
private:
	char screen[8][80];
	vector <char> q;
	int num_of_nodes;
	char max_depth;
public:
	Node* root;
	Tree();
	~Tree();
	void print();
	void set_screen(Node*, int, int);
	void tree_gen(Node*, char);
};
//Orshak Ivan, 7362, lab 4, 10.12.2018

#pragma once
#include<iostream>


using namespace std;
class avl_tree 
{
public:
	struct Node
	{
		int key;
		Node *left;
		Node *right;
		int value;
		int height;
	};

	avl_tree() 
	{
		root = nullptr;
	};

	void findVal(int value)
	{
		cout << "Founded " << find(root, value)->value << endl;
	}

	void put(int key, int value) 
	{
		root = insert(root, key, value);
	};

	void remove(int key) 
	{
		root = deleteNode(root, key);
	};

	int getOrDefault(int key, int defaultValue) 
	{
		Node*temp = root;
		Node*main = find(temp, key);
		return main != nullptr ? main->value : defaultValue;
	};


	void draw_tree(int pos)
	{
		print_tree(root, pos);
	};

private:
	Node *root;

	int height(Node *N) 
	{
		if (N == nullptr)
			return -1;

		return N->height;
	};

	int max(int a, int b) 
	{
		return (a > b) ? a : b;
	};

	Node *rightRotate(Node *y) 
	{
		Node *x = y->left;
		Node *T2 = x->right;

		x->right = y;
		y->left = T2;
		y->height = max(height(y->left), height(y->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;

		return x;
	};

	Node *leftRotate(Node *x) 
	{
		Node *y = x->right;
		Node *T2 = y->left;

		y->left = x;
		x->right = T2;
		x->height = max(height(x->left), height(x->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;

		return y;
	};

	int getBalance(Node *N) 
	{
		if (N == nullptr)
			return 0;

		return height(N->left) - height(N->right);
	};

	Node* newNode(int key, int value) 
	{
		Node* node = new Node;

		node->key = key;
		node->left = nullptr;
		node->right = nullptr;
		node->height = 0;
		node->value = value;

		return node;
	};

	Node * minValueNode(Node* node) 
	{
		Node* current = node;

		while (current->left != nullptr)
			current = current->left;

		return current;
	};


	Node * maxValueNode(Node* node) 
	{
		Node* current = node;

		while (current->right != nullptr)
			current = current->right;

		return current;
	};

	Node * insert(Node * node, int key, int value) 
	{
		if (node == nullptr) 
		{
			root = newNode(key, value);
			return root;
		}

		if (key < node->key)
			node->left = insert(node->left, key, value);
		else if (key > node->key)
			node->right = insert(node->right, key, value);
		else 
		{
			node->value = value;

			return node;
		}

		node->height = 1 + max(height(node->left), height(node->right));

		int balance = getBalance(node);

		if (balance > 1 && key < node->left->key)
			return rightRotate(node);

		if (balance < -1 && key > node->right->key)
			return leftRotate(node);

		if (balance > 1 && key > node->left->key) 
		{
			node->left = leftRotate(node->left);

			return rightRotate(node);
		}

		if (balance < -1 && key < node->right->key)
		{
			node->right = rightRotate(node->right);

			return leftRotate(node);
		}

		return node;
	};

	void print_tree(Node*temp, int pos)
	{
		Node*root = temp;

		if (root == nullptr)
			return;

		cout << root->key << " / " << root->value << endl;
		print_tree(root->right, pos + 1);
		print_tree(root->left, pos + 1);
	};

	Node* deleteNode(Node* root, int key)
	{
		if (root == nullptr)
			return root;

		if (key < root->key)
			root->left = deleteNode(root->left, key);
		else if (key > root->key)
			root->right = deleteNode(root->right, key);
		else
		{
			if ((root->left == nullptr) || (root->right == nullptr))
			{
				Node *temp = root->left ? root->left : root->right;

				if (temp == nullptr)
				{
					temp = root;
					root = nullptr;
				}
				else 
					*root = *temp;

				free(temp);
			}
			else
			{
				Node* temp = maxValueNode(root->left);

				root->key = temp->key;
				root->value = temp->value;
				root->left = deleteNode(root->left, temp->key); 
			}
		}

		if (root == nullptr)
			return root;

		root->height = 1 + max(height(root->left), height(root->right));

		int balance = getBalance(root);

		if (balance > 1 && getBalance(root->left) >= 0)
			return rightRotate(root);

		if (balance > 1 && getBalance(root->left) < 0)
		{
			root->left = leftRotate(root->left);

			return rightRotate(root);
		}

		if (balance < -1 && getBalance(root->right) <= 0)
			return leftRotate(root);

		if (balance < -1 && getBalance(root->right) > 0)
		{
			root->right = rightRotate(root->right);

			return leftRotate(root);
		}

		return root;
	}

	Node* find(Node *r, int d) 
	{
		if (r == nullptr)
			return nullptr;

		if (r->key == d)
			return r;

		if (d <= r->key) 
		{
			if (r->left != nullptr)
				return find(r->left, d);
			else
				return nullptr;
		}
		else 
		{
			if (r->right)
				return find(r->right, d);
			else
				return nullptr;
		}
	}
};

#pragma once

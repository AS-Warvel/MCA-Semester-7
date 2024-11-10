#pragma once

struct Node
{
	int data;
	Node* left;
	Node* right;
};

class AVLTree
{
	Node* root;
public:
	AVLTree()
	{
		root = nullptr;
	}

	~AVLTree()
	{
	}

private:
	int balanceFactor()
	{

	}

	void insert(int val)
	{

	}
};

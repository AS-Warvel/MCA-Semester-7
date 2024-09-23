#pragma once
#include <iostream>
using namespace std;

template <typename T> struct Node {
	T data;
	Node<T>* left;
	Node<T>* right;
};

template <typename T> class BSTree
{
	Node<T>* root;
public:
	BSTree()
	{
		root = nullptr;
	}

	~BSTree()
	{

	}

	void insert(T val)
	{
		Node<T>* newNode = new Node<T>;
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->data = val;

		if (!root)
		{
			root = newNode;
			return;
		}

		Node<T>* curr;
		curr = root;

		while (curr != nullptr)
		{
			if (curr->data == val)
			{
				cout << "Duplicate value found in Tree";
				delete newNode;
				break;
			}
			if (curr->data > val)
			{
				if (curr->right == nullptr)
				{
					curr->right = newNode;
					break;
				}
				else
					curr = curr->right;
			}
			else
				if (curr->left == nullptr)
				{
					curr->left = newNode;
					break;
				}
				else
					curr = curr->left;
		}

	}

	void print(const char* c) {
		if (c == "pre")
		{
			cout << "PreOrder: ";
			dispPreOrder(root);
		}
		else if (c == "in")
		{
			cout << "InOrder: ";
			dispInOrder(root);
		}
			
		else if(c == "post")
		{
			cout << "PostOrder: ";
			dispPostOrder(root);
		}
		cout << endl;
	}

	void dispPreOrder(Node<T>* node)
	{
		if (node)
		{
			cout << node->data << "\t";
			dispPreOrder(node->left);
			dispPreOrder(node->right);
		}
	}
	void dispInOrder(Node<T>* node)
	{
		if (node)
		{
			dispInOrder(node->left);
			cout << node->data << "\t";
			dispInOrder(node->right);
		}
	}
	void dispPostOrder(Node<T>* node)
	{
		if (node)
		{
			dispPostOrder(node->left);
			dispPostOrder(node->right);
			cout << node->data << "\t";
		}
	}

	T search(T val)
	{

	}

	T removeNode(T val)
	{

	}

	int getHeight()
	{

	}
};

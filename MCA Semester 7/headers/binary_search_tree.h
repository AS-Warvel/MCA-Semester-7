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

	bool searchTraversal(Node<T>* node, T element)
	{
		if (node == nullptr)
			return false;
		else if (node->data == element)
			return true;
		else if (element < node->data)
			return searchTraversal(node->left, element);
		else
			return searchTraversal(node->right, element);
	}

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
			if (curr->data < val)
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

		else if (c == "post")
		{
			cout << "PostOrder: ";
			dispPostOrder(root);
		}
		cout << endl;
	}

	int getHeight(Node<T>* node)
	{
		int treeHeight;
		if (!node)
			treeHeight = 0;
		else if (node->left == nullptr && node->right == nullptr)
			treeHeight = 1;
		else
		{
			int leftSubtreeHeight = getHeight(node->left);
			int rightSubtreeHeight = getHeight(node->right);

			treeHeight = (leftSubtreeHeight > rightSubtreeHeight) ? leftSubtreeHeight : rightSubtreeHeight;
			treeHeight++;
		}
		return treeHeight;
	}

	void removeNode(T val)
	{
		// code to find the node
		
		Node<T>* parnt;
		Node<T>* trav;
		parnt = root;
		trav = root;
		while (trav != nullptr)
		{
			if (trav->data == val)
				break;
			
			parnt = trav;
			if (val > trav->data)
				trav = trav->right;
			else
				trav = trav->left;
		}
		
		// code to delete node
		
		// leaf Node case
		if (trav->left == nullptr && trav->right == nullptr)
		{
			if (trav == root)
				root = nullptr;
			else if (trav->data > parnt->data)
				parnt->right = nullptr;
			else
				parnt->left = nullptr;
			delete trav;
		}
		// single children case
		else if (trav->left != nullptr && trav->right == nullptr)
		{
			if (trav == root)
				root = trav->left;
			else if (trav->data > parnt->data)
				parnt->right = trav->left;
			else
				parnt->left = trav->left;
			delete trav;
		}
		else if (trav->left == nullptr && trav->right != nullptr)
		{
			if (trav == root)
				root = trav->right;
			if (trav->data > parnt->data)
				parnt->right = trav->right;
			else
				parnt->left = trav->right;
			delete trav;
		}
		// two children case
		else
		{
			Node<T>* minNode;
			Node<T>* minParnt;
			
			minNode = trav->right;
			while (minNode != nullptr)
			{
				minParnt = minNode;
				minNode = minNode->left;
			}
			
			minParnt = minNode->right;
			trav->data = minNode->data;
			delete minNode;
		}
	}
	
	void search(T val)
	{
		if (searchTraversal(root, val))
			cout << "Element Found";
		else
			cout << "Element not Found";
		cout << endl;
	}

	void searchUsingLoop(T val)
	{
		Node<T>* currNode = root;
		while (currNode != nullptr)
		{
			if (currNode->data == val)
			{
				cout << "Element Found" << endl;
				return;
			}
			else if (val > currNode->data)
				currNode = currNode->right;
			else
				currNode = currNode->left;
		}
		cout << "Element not Found" << endl;
	}

	T getMax()
	{
		if (!root)
			return NULL;
		
		Node<T>* curr = root;
		while (curr->right)
			curr = curr->right;
		
		return curr->data;
	}

	T getMin()
	{
		if (!root)
			return NULL;
		
		Node<T>* curr = root;
		while (curr->left)
			curr = curr->left;
		
		return curr->data;
	}

	int getTreeHeight()
	{
		return getHeight(root);
	}
};

#include "headers/binary_search_tree.h"

void binarySearchTreeImpl()
{
	BSTree<int> tree;

	tree.insert(5);
	tree.insert(8);
	tree.insert(0);
	tree.insert(85);
	tree.insert(44);
	tree.insert(-2);
	tree.insert(50);
	tree.insert(2);
	tree.print("pre");
	tree.print("in");
	tree.print("post");
	system("pause");
}
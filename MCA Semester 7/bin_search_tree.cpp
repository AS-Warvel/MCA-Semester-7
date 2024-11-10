#include "headers/binary_search_tree.h"

void binarySearchTreeImpl()
{
	BSTree<int> tree;
	
	int selection;
	int ele;
	while (true)
	{
		system("cls");
		cout << "      ***** Binary Search Tree *****\n\n";

		cout << "Select an option:-\n";
		cout << "1) Insert Element\n";
		cout << "2) Remove Element\n";
		cout << "3) Display\n";
		cout << "4) Get Max\n";
		cout << "5) Get Min\n";
		cout << "6) Search Element(recursion method)\n";
		cout << "7) Search Element(while loop method)\n";
		cout << "8) Get Height of Tree\n";
		cout << "9) End Program\n";

		cout << "Enter: ";
		cin >> selection;

		if (selection == 1)
		{
			cout << "Enter Element: ";
			cin >> ele;
			tree.insert(ele);
			cout << endl;
			system("pause");
		}
		else if (selection == 2)
		{
			cout << "Enter Element: ";
			cin >> ele;
			tree.removeNode(ele);
			cout << "\nRemoved Successfully" << endl;
			system("pause");
		}
		else if (selection == 3)
		{
			tree.print("in");
			tree.print("pre");
			tree.print("post");
			system("pause");
		}
		else if (selection == 4)
		{
			cout << "Max : " << tree.getMax() << endl;
			system("pause");
		}
		else if (selection == 5)
		{
			cout << "Min : " << tree.getMin() << endl;
			system("pause");
		}
		else if (selection == 6)
		{
			int ele;
			cout << "Enter Element to Search: ";
			cin >> ele;
			tree.search(ele);
			system("pause");
		}
		else if (selection == 7)
		{
			int ele;
			cout << "Enter Element to Search: ";
			cin >> ele;
			tree.searchUsingLoop(ele);
			system("pause");
		}
		else if (selection == 8)
		{
			cout << "Height : " << tree.getTreeHeight() << endl;
			system("pause");
		}
		else if (selection == 9)
			return;
	}
	system("pause");
}
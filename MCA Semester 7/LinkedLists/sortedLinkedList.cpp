#include <iostream>
#include "../headers/linkedLists/sortedLinkedList.h"
using namespace std;

void sortedLinkedListImpl()
{
	SortedLinkedList<int> l;
	int selection;
	int ele;
	while (true)
	{
		system("cls");
		cout << "      ***** Assignment 7 - Linked Lists *****\n\n";

		cout << "Elements: ";
		l.print();
		cout << endl;

		cout << "Select an option:-\n";
		cout << "1) Insert as Element\n";
		cout << "2) Remove Element at Beginning\n";
		cout << "3) Remove Element from End\n";
		cout << "4) Remove at Position\n";
		cout << "5) Remove at nth location from end\n";
		cout << "6) Search Element\n";
		cout << "7) End Program\n";

		cout << "Enter: ";
		cin >> selection;

		if (selection == 1)
		{
			cout << "Enter Element: ";
			cin >> ele;
			l.insert(ele);
			cout << endl;
			system("pause");
		}
		if (selection == 2)
		{
			cout << "\nPopped Element: " << l.removeAtFirst() << endl;
			system("pause");
		}
		else if (selection == 3)
		{
			cout << "\nPopped Element: " << l.removeAtLast() << endl;
			system("pause");
		}
		else if (selection == 4)
		{
			int pos;
			cout << "Enter Position: ";
			cin >> pos;
			l.removeAtPos(pos);
			system("pause");
		}
		else if (selection == 5)
		{
			int pos;
			cout << "Enter location: ";
			cin >> pos;
			l.removeAtPosFromEnd(pos);
			system("pause");
		}
		else if (selection == 6)
		{
			int ele;
			cout << "Enter Element to Search: ";
			cin >> ele;
			l.searchEle(ele);
			system("pause");
		}
		else if (selection == 7)
			return;
	}
}
#include <iostream>
#include "../headers/linkedLists/linkedList.h"
using namespace std;

void LinkedListImpl()
{
	LinkedList<int> l;
	int selection;
	int ele;
	while (true)
	{
		system("cls");
		cout << "      ***** Assignment 6 - Linked Lists *****\n\n";

		cout << "Elements: ";
		l.print();
		cout << endl;

		cout << "Select an option:-\n";
		cout << "1) Add Element at Beginning\n";
		cout << "2) Add Element at End\n";
		cout << "3) Add at Position\n";
		cout << "4) Add at nth location from end\n";
		cout << "5) Add at after x\n";
		cout << "6) Remove Element at Beginning\n";
		cout << "7) Remove Element from End\n";
		cout << "8) Remove at Position\n";
		cout << "9) Remove at nth location from end\n";
		cout << "10) Remove after x\n";
		cout << "11) Search Element\n";
		cout << "12) Reverse List\n";
		cout << "13) End Program\n";

		cout << "Enter: ";
		cin >> selection;

		if (selection == 1)
		{
			cout << "Enter Element: ";
			cin >> ele;
			l.AddAtFirst(ele);
			cout << endl;
			system("pause");
		}
		else if (selection == 2)
		{
			cout << "Enter Element: ";
			cin >> ele;
			l.AddATLast(ele);
			cout << endl;
			system("pause");
		}
		else if (selection == 3)
		{
			int pos, ele;
			cout << "Enter Position: ";
			cin >> pos;
			cout << "Enter Element: ";
			cin >> ele;
			l.AddAtpos(pos, ele);
			system("pause");
		}
		else if (selection == 4)
		{
			int pos, ele;
			cout << "Enter location: ";
			cin >> pos;
			cout << "Enter Element: ";
			cin >> ele;
			l.addAtPosFromEnd(pos, ele);
			system("pause");
		}
		else if (selection == 5)
		{
			int x, ele;
			cout << "Enter Element to search: ";
			cin >> x;
			cout << "Enter Element: ";
			cin >> ele;
			l.addEleAfterX(x, ele);
			system("pause");
		}
		else if (selection == 6)
		{
			cout << "\nPopped Element: " << l.removeAtFirst() << endl;
			system("pause");
		}
		else if (selection == 7)
		{
			cout << "\nPopped Element: " << l.removeAtLast() << endl;
			system("pause");
		}
		else if (selection == 8)
		{
			int pos;
			cout << "Enter Position: ";
			cin >> pos;
			l.removeAtPos(pos);
			system("pause");
		}
		else if (selection == 9)
		{
			int pos;
			cout << "Enter location: ";
			cin >> pos;
			l.removeAtPosFromEnd(pos);
			system("pause");
		}
		else if (selection == 10)
		{
			int x;
			cout << "Enter Element to search: ";
			cin >> x;
			l.removeEleAfterX(x);
			system("pause");
		}
		else if (selection == 11)
		{
			int ele;
			cout << "Enter Element to Search: ";
			cin >> ele;
			l.searchEle(ele);
			system("pause");
		}
		else if (selection == 12)
			l.reverseList();
		else if (selection == 13)
			return;
	}
}
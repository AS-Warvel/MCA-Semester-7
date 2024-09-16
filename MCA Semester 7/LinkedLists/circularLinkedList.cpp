#include <iostream>
#include "../headers/linkedLists/circularLinkedList.h"
using namespace std;

void circularLinkedListImpl()
{
	CircularLinkedList<int> l;
	int selection;
	int ele;
	while (true)
	{
		system("cls");
		cout << "      ***** Circular Linked Lists *****\n\n";

		cout << "Elements: ";
		l.print();
		cout << endl;

		cout << "Select an option:-\n";
		cout << "1) Add Element at Beginning\n";
		cout << "2) Remove Element at Beginning\n";
		cout << "3) Add Element at End\n";
		cout << "4) Remove Element from End\n";
		cout << "5) Add at Position\n";
		cout << "6) Remove at Position\n";
		cout << "7) Search Element\n";
		cout << "8) End Program\n";

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
			cout << "\nPopped Element: " << l.removeAtFirst() << endl;
			system("pause");
		}
		else if (selection == 3)
		{
			cout << "Enter Element: ";
			cin >> ele;
			l.AddATLast(ele);
			cout << endl;
			system("pause");
		}
		else if (selection == 4)
		{
			cout << "\nPopped Element: " << l.removeAtLast() << endl;
			system("pause");
		}
		else if (selection == 5)
		{
			int pos, ele;
			cout << "Enter Position: ";
			cin >> pos;
			cout << "Enter Element: ";
			cin >> ele;
			l.AddAtpos(pos, ele);
			system("pause");
		}
		else if (selection == 6)
		{
			int pos;
			cout << "Enter Position: ";
			cin >> pos;
			l.removeAtPos(pos);
			system("pause");
		}
		else if (selection == 7)
		{
			int ele;
			cout << "Enter Element to Search: ";
			cin >> ele;
			l.searchEle(ele);
			system("pause");
		}
		else if (selection == 8)
			return;
	}
}
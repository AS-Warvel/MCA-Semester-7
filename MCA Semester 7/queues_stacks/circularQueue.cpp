#include "../headers/stack&queses/circularQueue.h"
#include <iostream>
using namespace std;

void circularQueueImpl()
{
	CircularQueue<int> q;
	int selection;
	int ele;
	while (true)
	{
		system("cls");
		cout << "      ***** Circular Queue *****\n\n";
		
		q.display();
		
		cout << "Select an option:-\n";
		cout << "1) Add an Element\n";
		cout << "2) Remove an Element\n";
		cout << "3) End Program\n";

		cout << "Enter: ";
		cin >> selection;

		if (selection == 1)
		{
			cout << "Enter Element: ";
			cin >> ele;
			q.insert(ele);
			cout << endl;
			system("pause");
		}
		else if (selection == 2)
		{
			cout << "\nPopped Element: " << q.remove() << endl;
			system("pause");
		}
		else if (selection == 3)
			return;
	}
}
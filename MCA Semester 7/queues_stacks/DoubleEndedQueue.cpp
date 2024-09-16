#include "../headers/stack&queses/DEQueue.h"

void DEQueueImpl()
{
	DEQueue<int> q;
	int selection;
	int ele;
	while (true)
	{
		system("cls");
		cout << "      ***** Double Ended Queue *****\n\n";

		q.display();

		cout << "Select an option:-\n";
		cout << "1) Add an Element at Rear\n";
		cout << "2) Add an Element at Front\n";
		cout << "3) Remove an Element from Rear\n";
		cout << "4) Remove an Element from Front\n";
		cout << "5) End Program\n";

		cout << "Enter: ";
		cin >> selection;

		if (selection == 1)
		{
			cout << "Enter Element: ";
			cin >> ele;
			q.insertAtRear(ele);
			cout << endl;
			system("pause");
		}
		else if (selection == 2)
		{
			cout << "Enter Element: ";
			cin >> ele;
			q.insertAtFront(ele);
			cout << endl;
			system("pause");
		}
		else if (selection == 3)
		{
			cout << "\nPopped Element: " << q.removeFromRear() << endl;
			system("pause");
		}
		else if (selection == 4)
		{
			cout << "\nPopped Element: " << q.removeFromFront() << endl;
			system("pause");
		}
		else if (selection == 5)
			return;
	}
}
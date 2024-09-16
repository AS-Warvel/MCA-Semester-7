#include "../headers/stack&queses/L_Queue.h"

void l_queueImpl()
{
	L_Queue<int> q;
	int selection;
	int ele;
	while (true)
	{
		system("cls");
		cout << "      ***** Normal Queue *****\n\n";

		q.print();

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

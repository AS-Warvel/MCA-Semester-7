#include <iostream>
#include "../headers/stack&queses/stack.h"
using namespace std;

void stackImpl() {
	Stack<int> stk;
	int selection;
	int ele;
	while (true)
	{
		system("cls");
		cout << "      ***** Assignment 3 - Stacks *****\n\n";
		cout << "Stack Elements: ";
		
		stk.display();
		
		cout << "Select an option:-\n";
		cout << "1) Push an Element\n";
		cout << "2) Pop an Element\n";
		cout << "3) Check top Element\n";
		cout << "4) End Program\n";

		cout << "Enter: ";
		cin >> selection;

		if (selection == 1)
		{
			cout << "Enter Element: ";
			cin >> ele;
			stk.push(ele);
			cout << endl;
			system("pause");
		}
		else if (selection == 2)
		{
			cout << "\nPopped Element: " << stk.pop() << endl;
			system("pause");
		}
		else if (selection == 3)
		{
			cout << "\nElement at Top: " << stk.peep() << endl;
			system("pause");
		}
		else if (selection == 4)
			return;
	}
}
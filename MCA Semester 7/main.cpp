#include <iostream>
#include "headers/assignImplFxns.h"

using namespace std;
int main()
{
	while (true)
	{
		system("cls");
		int selection;
		cout << "Select the Program to run:-\n\n";
		cout << "1) Assignment 1\n";
		cout << "2) Assignment 2\n";
		cout << "3) Assignment 3\n";
		cout << "4) Assignment 4\n";
		cout << "5) Assignment 5\n";
		cout << "6) End the Program\n";
		cout << "\nEnter: ";
		cin >> selection;
		if (selection == 1)
			assign1Impl();
		else if (selection == 2)
			assign2Impl();
		else if (selection == 3)
			assign3Impl();
		else if (selection == 4)
			assign4Impl();
		else if (selection == 5)
			assign5Impl();
		else if (selection == 6)
			break;
	}
	return 0;
}
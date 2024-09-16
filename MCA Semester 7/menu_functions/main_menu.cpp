#include "../headers/assignImplFxns.h"
#include <iostream>
using namespace std;

void assignmentsMenu()
{
	while (true)
	{
		system("cls");
		int selection;
		cout << "Select the Program to run:-\n\n";
		cout << "1) Array Insertion/Deletion\n";
		cout << "2) Polynomial\n";
		cout << "3) Stack\n";
		cout << "4) Infix to Prefix\n";
		cout << "5) Queues\n";
		cout << "6) LinkedLists\n";
		cout << "7) End the Program\n";
		cout << "\nEnter: ";
		cin >> selection;
		if (selection == 1)
			arrayInsDelImpl();
		else if (selection == 2)
			polynomialimpl();
		else if (selection == 3)
			stackImpl();
		else if (selection == 4)
			infixToPrefixImpl();
		else if (selection == 5)
			circularQueueImpl();
		else if (selection == 6)
			LinkedListImpl();
		else if (selection == 7)
			break;
	}
}

void allProgramsMenu()
{
	while (true)
	{
		system("cls");
		int selection;
		cout << "Select the Program to run:-\n\n";
		cout << "1) Array Insertion/Deletion\n";
		cout << "2) Polynomial\n";
		cout << "3) Stack\n";
		cout << "4) Stack\n";
		cout << "5) Infix to Prefix\n";
		cout << "6) Queues\n";
		cout << "7) Linked Lists\n";
		cout << "8) Palindrome Check\n";
		cout << "9) Parenthesis Matching\n";
		cout << "10) End the Program\n";
		cout << "\nEnter: ";
		cin >> selection;
		if (selection == 1)
			arrayInsDelImpl();
		else if (selection == 2)
			polynomialimpl();
		else if (selection == 3)
			stackImpl();
		else if (selection == 4)
			l_stackImpl();
		else if (selection == 5)
			infixToPrefixImpl();
		else if (selection == 6)
			QueuesPrograms();
		else if (selection == 7)
			LinkedListPrograms();
		else if (selection == 8)
			palindromeCheck();
		else if (selection == 9)
			parenthesisMatching();
		else if (selection == 10)
			break;
	}
}

void QueuesPrograms() {
	while (true)
	{
		system("cls");
		int selection;
		cout << "Select the Program to run:-\n\n";
		cout << "1) Normal Queue\n";
		cout << "2) Circular Queue\n";
		cout << "3) Double Ended Queue\n";
		cout << "4) Queue (Linked List)\n";
		cout << "5) Double Ended Queue (Linked List)\n";
		cout << "6) End the Program\n";
		cout << "\nEnter: ";
		cin >> selection;
		if (selection == 1)
			normalQueueImpl();
		else if (selection == 2)
			circularQueueImpl();
		else if (selection == 3)
			DEQueueImpl();
		else if (selection == 4)
			l_queueImpl();
		else if (selection == 5)
			l_dequeueImpl();
		else if (selection == 6)
			break;
	}
}

void LinkedListPrograms()
{
	while (true)
	{
		system("cls");
		int selection;
		cout << "Select the Program to run:-\n\n";
		cout << "1) Linked List\n";
		cout << "2) Circular Linked List\n";
		cout << "3) Doubly Linked List\n";
		cout << "4) Circular Doubly Linked List\n";
		cout << "5) End the Program\n";
		cout << "\nEnter: ";
		cin >> selection;
		if (selection == 1)
			LinkedListImpl();
		else if (selection == 2)
			circularLinkedListImpl();
		else if (selection == 3)
			doublyLinkedListImpl();
		else if (selection == 4)
			CircularDoublyLinkedListImpl();
		else if (selection == 5)
			break;
	}
}
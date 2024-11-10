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
		cout << "5) Queue using Stacks\n";
		cout << "6) Linked List\n";
		cout << "7) Sorted Linked Lists\n";
		cout << "8) Circular Linked List\n";
		cout << "9) Doubly Linked List\n";
		cout << "10) Loop Detection\n";
		cout << "11) Heap Sort\n";
		cout << "12) Graph\n";
		cout << "13) Sorting Programs\n";
		cout << "14) Hashing\n";
		cout << "15) Edit Distance Calculation\n";
		cout << "16) End the Program\n";
		cout << "\nEnter: ";
		cin >> selection;
		if (selection == 1)
			arrayInsDelImpl();
		else if (selection == 2)
			polynomial2impl();
		else if (selection == 3)
			stackImpl();
		else if (selection == 4)
			infixToPrefixImpl();
		else if (selection == 5)
			queueUsingStacksImpl();
		else if (selection == 6)
			LinkedListImpl();
		else if (selection == 7)
			sortedLinkedListImpl();
		else if (selection == 8)
			circularLinkedListImpl();
		else if (selection == 9)
			doublyLinkedListImpl();
		else if (selection == 10)
			loopDetectionImpl();
		else if (selection == 11)
			heapSortImpl();
		else if (selection == 12)
			graphImpl();
		else if (selection == 13)
			sortingPrograms();
		else if (selection == 14)
			hashingImpl();
		else if (selection == 15)
			editDistanceImpl();
		else if (selection == 16)
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
		cout << "4) Stack (Linked List)\n";
		cout << "5) Infix to Prefix\n";
		cout << "6) Queues\n";
		cout << "7) Linked Lists\n";
		cout << "8) Palindrome Check\n";
		cout << "9) Parenthesis Matching\n";
		cout << "10) Polynomial using Linked Lists\n";
		cout << "11) Binary Search Tree\n";
		cout << "12) Heap Sort\n";
		cout << "13) End the Program\n";
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
			polynomial_LL_impl();
		else if (selection == 11)
			binarySearchTreeImpl();
		else if (selection == 12)
			heapSortImpl();
		else if (selection == 13)
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

void sortingPrograms() {
	while (true)
	{
		system("cls");
		int selection;
		cout << "Select the Program to run:-\n\n";
		cout << "1) Selection Sort\n";
		cout << "2) Insertion Sort\n";
		cout << "3) Bubble Sort\n";
		cout << "4) Merge Sort\n";
		cout << "5) Quick Sort\n";
		cout << "6) End the Program\n";
		cout << "\nEnter: ";
		cin >> selection;
		if (selection == 1)
			selectionSortImpl();
		else if (selection == 2)
			insertionSortImpl();
		else if (selection == 3)
			bubbleSortImpl();
		else if (selection == 4)
			mergeSortImpl();
		else if (selection == 5)
			quickSortImpl();
		else if (selection == 6)
			break;
	}
}
#pragma once
#include <iostream>
#define MAXQUEUE 10
using namespace std;

template <typename T> class Queue
{
private:
	int front;
	int rear;
	T items[MAXQUEUE];
public:
	Queue()
	{
		front = -1;
		rear = -1;
	}
	void insert(T val)
	{
		if (rear == MAXQUEUE - 1)
		{
			cout << "Queue Overflow!!" << endl;
			return;
		}
		else
		{
			items[++rear] = val;
			if (front == -1)
				front++;
		}
	}
	T remove()
	{
		if (front == -1 || (front > rear))
		{
			cout << "Queue Underflow";
			return NULL;
		}
		else
			return items[front++];
	}

	void display()
	{
		cout << "Elements: ";
		for (int i = 0; i < MAXQUEUE; i++)
			cout << items[i] << "\t";
		cout << "\nIndex:    ";
		for (int i = 0; i < MAXQUEUE; i++)
			cout << i << "\t";
		cout << endl;
	}
};
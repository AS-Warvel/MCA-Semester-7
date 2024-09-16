#pragma once
#include <iostream>
#define MAXQUEUE 7
using namespace std;

template <typename T> class CircularQueue
{
private:
	int front;
	int rear;
	T items[MAXQUEUE];
public:
	CircularQueue()
	{
		front = -1;
		rear = -1;
	}

	void insert(T val)
	{
		if (rear == -1 && front == -1)
		{
			rear = 0;
			front = 0;
			items[0] = val;
		}
		else if ((rear + 1) % MAXQUEUE == front)
			cout << "Queue Overflow!!" << endl;
		else
		{
			rear = (rear + 1) % MAXQUEUE;
			items[rear] = val;
		}
	}
	T remove()
	{
		T c;
		if (front == -1 && rear == -1)
		{
			cout << "Queue Underflow!!" << endl;
			return NULL;
		}
		else if (front == rear)
		{
			c = items[front];
			front = -1;
			rear = -1;
		}
		else
		{
			c = items[front];
			front = (front + 1) % MAXQUEUE;
		}
		return c;
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
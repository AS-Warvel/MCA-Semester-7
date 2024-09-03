#pragma once

#include <iostream>
#define MAXQUEUE 10
using namespace std;

template <typename T> class DEQueue
{
private:
	int front;
	int rear;
	T items[MAXQUEUE];
public:
	DEQueue()
	{
		front = -1;
		rear = -1;
	}

	void insertAtFront(T val)
	{
		if (front == -1 && rear == -1)
		{
			front = 0;
			rear = 0;
		}
		else if ((rear + 1) % MAXQUEUE == front)
		{
			cout << "Queue Overflow" << endl;
			return;
		}
		else if (front == 0)
		{
			front = MAXQUEUE - 1;
		}
		else
		{
			front--;
		}
		items[front] = val;
	}

	void insertAtRear(T val)
	{
		if (rear == -1 && front == -1)
		{
			rear = 0;
			front = 0;
		}
		else if ((rear + 1) % MAXQUEUE == front)
		{
			cout << "Queue Overflow!!" << endl;
			return;
		}
		else
		{
			rear = (rear + 1) % MAXQUEUE;
		}
		items[rear] = val;
	}

	T removeFromFront()
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

	T removeFromRear()
	{
		T c;
		if (front == -1 && rear == -1)
		{
			cout << "Queue Underflow!!" << endl;
			return NULL;
		}
		else if (front == rear)
		{
			c = items[rear];
			front = -1;
			rear = -1;
		}
		else
		{
			c = items[rear];
			if (rear == 0)
				front = MAXQUEUE - 1;
			else
				rear--;
		}
		return c;
	}
};
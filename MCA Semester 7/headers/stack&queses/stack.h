#pragma once
#include <iostream>
using namespace std;

template <typename T> class Stack
{
private:
	int top = -1;
	const int max = 10;
	T stack[100];

public:
	bool isEmpty() {
		return top == -1;
	}

	bool isFull() {
		return top == max;
	}

	void clear()
	{
		top = -1;
	}

	void push(T value) {
		if (!isFull())
		{
			stack[++top] = value;
		}
		else {
			cout << "\nStack Overflow";
		}
	}

	T pop() {
		if (!isEmpty()) {
			return stack[top--];
		}
		cout << "\nStack Underflow";
		return NULL;
	}

	T peep() {
		if (!isEmpty()) {
			return stack[top];
		}
		cout << "\nStack Underflow";
		return NULL;
	}

	void display()
	{
		for (int i = 0; i <= top; i++)
		{
			cout << stack[i] << "\t";
		}
		cout << endl;
	}
};
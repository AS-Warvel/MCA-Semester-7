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
		if (top == -1)
		{
			return true;
		}
		return false;
	}

	bool isFull() {
		if (top >= max) {
			return true;
		}
		return false;
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
};
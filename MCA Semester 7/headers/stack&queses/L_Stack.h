#pragma once
#include "../linkedLists/linkedList.h"
template <typename T> class L_Stack
{
	LinkedList<T> items;

public:
	L_Stack()
	{
	}

	~L_Stack()
	{
	}

	bool isEmpty()
	{

	}

	void push(T val)
	{
		items.AddATLast(val);
	}

	T peak()
	{
		return NULL;
	}

	T pop()
	{
		return items.removeAtLast();
	}

	void print()
	{
		items.print();
	}
};

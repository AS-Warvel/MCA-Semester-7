#pragma once
#include "../linkedLists/linkedList.h"
template <typename T> class L_DEQueue
{
	LinkedList<T> items;

public:
	L_DEQueue()
	{
	}

	~L_DEQueue()
	{
	}

	void insertAtFront(T val)
	{
		items.AddAtFirst(val);
	}

	void insertAtRear(T val)
	{
		items.AddATLast(val);
	}

	T removeFromFront()
	{
		return items.removeAtFirst();
	}

	T removeFromRear()
	{
		return items.removeAtLast();
	}

	void print()
	{
		items.print();
	}
};

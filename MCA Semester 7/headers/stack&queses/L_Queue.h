#pragma once

#include "../linkedLists/linkedList.h"
template <typename T> class L_Queue
{
	LinkedList<T> items;

public:
	L_Queue()
	{
	}

	~L_Queue()
	{
		items.destroy();
	}

	void insert(T val)
	{
		items.AddAtFirst(val);
	}

	T remove()
	{
		return items.removeAtLast();
	}

	void print()
	{
		items.print();
	}
};

#pragma once
#include <iostream>
using namespace std;

template <typename T> struct Node
{
	T data;
	Node* next;
};

template <typename T> class SortedLinkedList
{
private:
	Node<T>* head;
public:
	SortedLinkedList()
	{
		head = nullptr;
	}
	~SortedLinkedList()
	{
		destroy();
	}

	void insert(T val)
	{
		Node<T>* temp = new Node<T>;
		temp->data = val;
		if (head == nullptr)
		{
			temp->next = nullptr;
			head = temp;
		}
		else if(head->data > val)
		{
			temp->next = head;
			head = temp;
		}
		else
		{
			Node<T>* curr;
			curr = head;
			while (curr->next != nullptr)
			{
				if (curr->next->data > val)
				{
					temp->next = curr->next;
					curr->next = temp;
					return;
				}
				curr = curr->next;
			}
			curr->next = temp;
			temp->next = nullptr;
		}
	}

	T removeAtFirst()
	{
		if (head == nullptr)
			return NULL;
		Node<T>* temp;
		temp = head;
		head = head->next;
		T val = temp->data;
		delete temp;
		return val;
	}

	T removeAtLast()
	{
		if (head == nullptr)
			return NULL;
		else if (head->next == nullptr)
		{
			T val = head->data;
			delete head;
			head = nullptr;
			return val;
		}
		else
		{
			Node<T>* curr;
			Node<T>* prev;
			curr = head;
			prev = curr;
			while (curr->next != nullptr)
			{
				prev = curr;
				curr = curr->next;
			}
			prev->next = nullptr;
			T val = curr->data;
			delete curr;
			return val;
		}
	}

	T removeAtPos(int pos)
	{
		if (head == nullptr)
		{
			cout << "List Underflow!!\n";
			return NULL;
		}
		if (pos <= 0)
		{
			cout << "position out of range!!\n";
			return NULL;
		}
		if (pos == 1)
			return removeAtFirst();
		Node<T>* curr;
		Node<T>* prev;
		curr = head;
		prev = curr;
		for (int i = 0; i < pos - 1; i++)
		{
			prev = curr;
			curr = curr->next;
			if (curr == nullptr)
			{
				cout << "Position out of Range!!\n";
				return NULL;
			}
		}
		prev->next = curr->next;
		T val = curr->data;
		delete curr;
		return val;
	}

	T removeAtPosFromEnd(int n)
	{
		Node<T>* curr = head;
		int total_length = 0;
		while (curr != nullptr)
		{
			total_length++;
			curr = curr->next;
		}
		return removeAtPos(total_length + 1 - n);
	}

	void print()
	{
		Node<T>* curr;
		curr = head;
		while (curr != nullptr)
		{
			cout << curr->data << "\t";
			curr = curr->next;
		}
	}

	void searchEle(T val)
	{
		Node<T>* curr;
		int i = 0;
		curr = head;
		while (curr != nullptr)
		{
			i++;
			if (curr->data == val)
				cout << "value found at " << i << endl;
		}
		if (curr == nullptr)
			cout << "value not found\n";
	}

	void destroy()
	{
		Node<T>* curr;
		Node<T>* temp;
		curr = head;

		while (curr != nullptr)
		{
			temp = curr;
			curr = curr->next;
			delete temp;
		}
	}
	friend class Polynomial_LL;
};
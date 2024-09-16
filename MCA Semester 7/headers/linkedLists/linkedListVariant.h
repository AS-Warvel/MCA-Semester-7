#pragma once

#include <iostream>
using namespace std;

template <typename T> struct Node {
	Node<T>* next;
	T data;
};

template <typename T> class LinkedListVariant
{
	Node<T>* head;
	int size;
public:
	LinkedListVariant()
	{
		head = nullptr;
		size = 0;
	}

	~LinkedListVariant()
	{
		destroy();
	}

	void AddAtFirst(T val)
	{
		Node<T>* temp = new Node<T>;
		temp->data = val;
		temp->next = head;
		head = temp;
		size++;
	}

	void AddATLast(T val)
	{
		if (head == nullptr)
			AddAtFirst(val);
		else
		{
			Node<T>* temp = new Node<T>;
			temp->data = val;

			Node<T>* curr = head;
			while (curr->next != nullptr)
				curr = curr->next;

			curr->next = temp;
			temp->next = nullptr;
			size++;
		}
	}

	void AddAtpos(int pos, T val)
	{
		if (pos == 1 || head == nullptr)
			AddAtFirst(val);
		else if(pos > 0 && pos <= size + 1)
		{
			Node<T>* temp = new Node<T>;
			Node<T>* curr;

			temp->data = val;

			curr = head;
			for (int i = 0; i < pos - 2; i++)
				curr = curr->next;

			temp->next = curr->next;
			curr->next = temp;
			size++;
		}
	}

	T removeAtFirst()
	{
		Node<T>* temp;
		temp = head;
		head = head->next;
		T val = temp->data;
		delete temp;
		size--;
		return val;
	}

	T removeAtLast()
	{
		if (head->next == nullptr)
		{
			T val = head->data;
			delete head;
			head = nullptr;
			size--;
			return val;
		}
		else
		{
			Node<T>* curr;
			
			curr = head;
			while (curr->next->next != nullptr)
				curr = curr->next;
			
			T val = curr->next->data;
			delete curr->next;
			curr->next = nullptr;
			size--;
			return val;
		}
	}

	T removeAtPos(int pos)
	{
		if (head == nullptr)
		{
			cout << "List is Underflow!!\n";
			return NULL;
		}
		else if (pos == 1)
			return removeAtFirst();
		else if (pos > 0 && pos <= size)
		{
			Node<T>* curr;
			Node<T>* temp;
			
			curr = head;
			for (int i = 0; i < pos - 2; i++)
				curr = curr->next;
			
			temp = curr->next;
			curr->next = curr->next->next;
			
			T val = temp->data;
			delete temp;
			size--;
			return val;
		}
		else
			cout << "Position out of Range!\n";
	}

	void reverseList()
	{
		Node<T>* prev;
		Node<T>* curr;
		Node<T>* next;

		prev = nullptr;
		curr = head;
		while (curr != nullptr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
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

		do
		{
			temp = curr;
			curr = curr->next;
			delete temp;
		} while (curr != nullptr);
	}
};
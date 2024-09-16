#pragma once
#pragma once

#include <iostream>
using namespace std;
template <typename T> struct Node
{
	T data;
	Node* next;
};

template <typename T> class CLList_variant
{
private:
	Node<T>* head;
	int size;
public:
	CLList_variant()
	{
		head = nullptr;
		size = 0;
	}
	~CLList_varaint()
	{
		destroy();
	}

	void AddAtFirst(T val)
	{
		Node<T>* temp = new Node<T>;
		if (head == nullptr)
		{
			temp->data = val;
			
			head = temp;
			temp->next = head;
		}
		else
		{
			T tempData = head->data;
			head->data = val;
			temp->data = tempData;
			
			temp->next = head->next;
			head->next = temp;
		}
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
			while (curr->next != head)
				curr = curr->next;

			curr->next = temp;
			temp->next = head;
			size++;
		}
	}

	void AddAtpos(int pos, T val)
	{
		if (pos == 1)
			AddAtFirst(val);
		else if (pos > 0 && pos <= size + 1)
		{
			Node<T>* curr;
			Node<T>* temp = new Node<T>;
			temp->data = val;

			curr = head;
			for (int i = 0; i < pos - 2; i++)
			{
				curr = curr->next;
			}

			temp->next = curr->next
			curr->next = temp;
			size++;
		}
		else
			cout << "Position out of range\n";
	}

	T removeAtFirst()
	{
		if (head == nullptr)
		{
			cout << "List Underflow!!\n";
			return NULL;
		}
		else if (head->next == head)
		{
			T tempData = head->data;
			delete head;
			head = nullptr;
			size--;
			return tempData;
		}
		else
		{
			Node<T>* temp;
			Node<T>* curr;

			curr = head;
			while (curr->next != head)
				curr = curr->next;

			curr->next = head->next;
			temp = head;
			head = head->next;

			T val = temp->data;
			delete temp;
			size--;
			return val;
		}
	}

	T removeAtLast()
	{
		T tempData = NULL;
		if (head == nullptr)
		{
			cout << "List is Underflow!!\n";
			return tempData;
		}
		if (head->next == head)
		{
			tempData = head->data;
			delete head;
			head = nullptr;
			size--;
			return tempData;
		}
		else
		{
			Node<T>* curr;
			Node<T>* temp;

			curr = head;
			while (curr->next->next != head)
				curr = curr->next;

			temp = curr->next;
			curr->next = head;
			tempData = curr->data;
			delete temp;
			size--;
			return tempData;
		}
	}

	T removeAtPos(int pos)
	{
		if (head == nullptr)
		{
			cout << "List Underflow!!\n";
			return NULL;
		}
		else if (pos == 1)
			return removeAtFirst();
		else if(pos > 0 && pos <= size)
		{
			Node<T>* curr;
			Node<T>* temp;

			curr = head;
			for (int i = 0; i < pos - 2; i++)
				curr = curr->next;
				
			temp = curr->next
			curr->next = curr->next->next;
			T val = temp->data;
			delete temp;
			size--;
			return val;
		}
	}


	void print()
	{
		if (head != nullptr)
		{
			Node<T>* curr;
			curr = head;
			cout << curr->data << "\t";
			while (curr->next != head)
			{
				curr = curr->next;
				cout << curr->data << "\t";
			}
		}
	}

	void searchEle(T val)
	{
		Node<T>* curr;
		int i = 0;
		curr = head;
		while (curr->next != head)
		{
			i++;
			if (curr->data == val)
				cout << "value found at " << i << endl;
			curr = curr->next;
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
		} while (curr != head);
	}
};
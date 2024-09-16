#pragma once
#include <iostream>
using namespace std;
template <typename T> struct Node
{
	T data;
	Node* next;
};

template <typename T> class LinkedList
{
private:
	Node<T>* head;
public:
	LinkedList()
	{
		head = nullptr;
	}
	~LinkedList()
	{
		destroy();
	}

	void AddAtFirst(T val)
	{
		Node<T>* temp = new Node<T>;
		temp->data = val;
		temp->next = head;
		head = temp;
	}

	void AddATLast(T val)
	{
		if (head == nullptr)
			AddAtFirst(val);
		else
		{
			Node<T>* temp = new Node<T>;
			temp->data = val;
			temp->next = nullptr;
			Node<T>* curr = head;
			while (curr->next != nullptr)
				curr = curr->next;
			curr->next = temp;
		}
	}

	void AddAtpos(int pos, T val)
	{
		if (pos == 1 || head == nullptr)
			AddAtFirst(val);
		else
		{
			Node<T>* temp = new Node<T>;
			Node<T>* curr;
			Node<T>* prev;
			
			temp->data = val;

			curr = head;
			prev = curr;
			for (int i = 1; i < pos; i++)
			{
				prev = curr;
				curr = curr->next;
			}
			temp->next = curr;
			prev->next = temp;
		}
	}

	T removeAtFirst()
	{
		Node<T>* temp;
		temp = head;
		head = head->next;
		T val = temp->data;
		delete temp;
		return val;
	}

	T removeAtLast()
	{
		if (head->next == nullptr)
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
		Node<T>* curr;
		Node<T>* prev;
		curr = head;
		prev = curr;
		for (int i = 0; i < pos; i++)
		{
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
		T val = curr->data;
		delete curr;
		return val;
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
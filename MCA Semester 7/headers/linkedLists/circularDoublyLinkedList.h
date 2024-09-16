#pragma once
#include <iostream>
using namespace std;

template <typename T> struct Node
{
	T data;
	Node* next;
	Node* prev;
};

template <typename T> class CircularDoublyLinkedList
{
private:
	Node<T>* head;
public:
	CircularDoublyLinkedList()
	{
		head = nullptr;
	}
	~CircularDoublyLinkedList()
	{
		destroy();
	}

	void AddAtFirst(T val)
	{
		Node<T>* temp = new Node<T>;
		temp->data = val;
		if (head == nullptr)
		{
			head = temp;
			temp->next = head;
			temp->prev = head;
		}
		else
		{
			temp->prev = head->prev;
			temp->next = head;
			head->prev->next = temp;
			head->prev = temp;
			head = temp;
		}
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

			temp->next = head;
			temp->prev = curr;
			curr->next = temp;
			head->prev = temp;
		}
	}

	void AddAtpos(int pos, T val)
	{
		if (pos == 1)
			AddAtFirst(val);
		else
		{
			if (head == nullptr || pos <= 0)
			{
				cout << "Invalid Position!!\n";
				return;
			}

			Node<T>* curr;
			curr = head;
			for (int i = 0; i < pos - 2; i++)
			{
				curr = curr->next;
				if (curr == head)
				{
					cout << "Position out of Range";
					return;
				}
			}

			Node<T>* temp = new Node<T>;
			temp->data = val;

			if (curr->next == head)
			{
				temp->next = head;
				temp->prev = curr;
				curr->next = temp;
				head->prev = temp;
			}
			else
			{
				temp->next = curr->next;
				temp->prev = curr;
				curr->next->prev = temp;
				curr->next = temp;
			}

		}
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
			T val = head->data;
			delete head;
			head = nullptr;
			return val;
		}
		else
		{
			Node<T>* temp;
			temp = head;
			head = head->next;
			head->prev = temp->prev;
			temp->prev->next = head;

			T val = temp->data;
			delete temp;
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
		if (head->next == nullptr)
		{
			tempData = head->data;
			delete head;
			head = nullptr;
			return tempData;
		}
		else
		{
			Node<T>* curr;
			Node<T>* prev;

			curr = head;
			while (curr->next->next != head)
			{
				curr = curr->next;
			}

			tempData = curr->data;
			delete curr->next;
			curr->next = nullptr;
			curr->next = head;
			head->prev = curr;

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
		if (pos <= 0)
		{
			cout << "Invalid Position\n";
			return NULL;
		}
		else if (pos == 1)
			return removeAtFirst();
		else
		{
			Node<T>* curr;

			curr = head;
			for (int i = 0; i < pos - 1; i++)
			{
				curr = curr->next;
				if (curr == nullptr)
				{
					cout << "Position out of Range\n";
					return NULL;
				}
			}
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			T val = curr->data;
			delete curr;
			return val;
		}
	}

	void reverseList() {}

	void print()
	{
		if (head != nullptr)
		{
			Node<T>* curr;
			curr = head;
			while (curr->next != head)
			{
				cout << curr->data << "\t";
				curr = curr->next;
			}
			cout << curr->data << "\t";
		}
	}

	void searchEle(T val)
	{
		Node<T>* curr;
		int i = 0;
		curr = head;
		while (!(curr == head && i != 0))
		{
			i++;
			if (curr->data == val)
				cout << "value found at " << i << endl;
			curr = curr->next;
		}
		if (curr == head)
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
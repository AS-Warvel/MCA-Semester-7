#pragma once
#include <iostream>
using namespace std;

template <typename T> struct Node
{
	T data;
	Node* next;
	Node* prev;
};

template <typename T> class DoublyLinkedList
{
private:
	Node<T>* head;
	int size;
public:
	DoublyLinkedList()
	{
		head = nullptr;
		size = 0;
	}
	~DoublyLinkedList()
	{
		destroy();
	}

	void AddAtFirst(T val)
	{
		Node<T>* temp = new Node<T>;
		temp->data = val;
		if (head == nullptr)
		{
			temp->next = nullptr;
			temp->prev = nullptr;
			head = temp;
		}
		else
		{
			temp->prev = nullptr;
			temp->next = head;
			head->prev = temp;
			head = temp;
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
			while (curr->next != nullptr)
				curr = curr->next;

			curr->next = temp;
			temp->prev = curr;
			temp->next = nullptr;
			size++;
		}
	}

	void AddAtpos(int pos, T val)
	{
		if (pos > 0 && pos <= size + 1)
		{
			if (pos == 1)
			{
				AddAtFirst(val);
				return;
			}
			Node<T>* curr;
			curr = head;
			for (int i = 0; i < pos - 2; i++)
				curr = curr->next;

			Node<T>* temp = new Node<T>;
			temp->data = val;

			if (curr->next == nullptr)
			{
				temp->next = nullptr;
				temp->prev = curr;
				curr->next = temp;
			}
			else
			{
				temp->next = curr->next;
				temp->prev = curr;
				curr->next->prev = temp;
				curr->next = temp;
			}
			size++;
		}
		else
			cout << "Postion out of Range\n";
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
			size--;
			return val;
		}
		else
		{
			Node<T>* temp;
			temp = head;
			head = head->next;
			head->prev = nullptr;

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
		if (head->next == nullptr)
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

			curr = head;
			while (curr->next->next != nullptr)
				curr = curr->next;

			tempData = curr->next->data;
			delete curr->next;
			curr->next = nullptr;
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
		else if(pos > 0 && pos <= size)
		{
			if (pos == 1)
				return removeAtFirst();
			Node<T>* curr;

			curr = head;
			for (int i = 0; i < pos - 1; i++)
				curr = curr->next;
				
			if (curr->next == nullptr)
			{
				curr->prev->next = nullptr;
				T val = curr->data;
				delete curr;
				size--;
				return val;
			}
			else
			{
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				T val = curr->data;
				delete curr;
				size--;
				return val;
			}
		}
	}

	void print()
	{
		if (head != nullptr)
		{
			Node<T>* curr;
			curr = head;
			while (curr != nullptr)
			{
				cout << curr->data << "\t";
				curr = curr->next;
			}
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
		} while (curr != nullptr);
	}

};
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

	void create(T val)
	{
		Node<T>* temp = new Node<T>;
		temp->data = val;
		temp->next = nullptr;
		head = temp;
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
		if (pos == 1)
			AddAtFirst(val);
		else if (pos <= 0 || head == nullptr)
			cout << "Position out of range!\n";
		else
		{
			Node<T>* temp = new Node<T>;
			Node<T>* curr;
			Node<T>* prev;
			
			temp->data = val;

			curr = head;
			prev = curr;
			for (int i = 0; i < pos - 1; i++)
			{
				if (curr == nullptr)
				{
					cout << "Position out of Range!!\n";
					return;
				}
				prev = curr;
				curr = curr->next;
			}
			temp->next = curr;
			prev->next = temp;
		}
	}

	void addAtPosFromEnd(int n, T val)
	{
		Node<T>* curr = head;
		int total_length = 0;
		while (curr != nullptr)
		{
			total_length++;
			curr = curr->next;
		}
		AddAtpos(total_length + 1 - n, val);
	}

	void addEleAfterX(T x, T val)
	{
		Node<T>* curr = head;
		while (curr != nullptr)
		{
			if (curr->data == x)
				break;
			curr = curr->next;
		}
		if (curr != nullptr)
		{
			Node<T>* temp = new Node<T>;
			temp->data = val;
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "Element not found!";
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

	T removeEleAfterX(T x)
	{
		Node<T>* curr = head;
		while (curr != nullptr)
		{
			if (curr->data == x)
				break;
			curr = curr->next;
		}
		if (curr == nullptr)
			cout << "Element not found!\n";
		else if (curr->next != nullptr)
		{
			Node<T>* temp = curr->next;
			curr->next = curr->next->next;
			T val = temp->data;
			delete temp;
			return val;
		}
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
			{
				cout << "value found at " << i << endl;
				break;
			}
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
		while (curr != nullptr)
		{
			temp = curr;
			curr = curr->next;
			delete temp;
		}
		head = nullptr;
	}
};
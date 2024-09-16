#pragma once
#include <iostream>
using namespace std;
template <typename T> struct Node
{
	T data;
	Node* next;
};

template <typename T> class CircularLinkedList
{
private:
	Node<T>* head;
public:
	CircularLinkedList()
	{
		head = nullptr;
	}
	~CircularLinkedList()
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
		}
		else
		{

			Node<T>* curr = head;
			while (curr->next != head)
				curr = curr->next;

			curr->next = temp;
			temp->next = head;
			head = temp;
			/*T tempData = head->data; // this is for variant
			head->data = val;
			temp->data = tempData;
			temp->next = head->next;
			head->next = temp;*/
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

			curr->next = temp;
			temp->next = head;
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

			Node<T>* prev;
			Node<T>* curr;

			curr = head;
			prev = curr;
			for (int i = 0; i < pos - 1; i++)
			{
				prev = curr;
				curr = curr->next;
				if (prev == head && i !=0)
				{
					cout << "Position out of Range";
					return;
				}
			}
			Node<T>* temp = new Node<T>;
			temp->data = val;

			prev->next = temp;
			temp->next = curr;
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
			T tempData = head->data;
			delete head;
			head = nullptr;
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
			return tempData;
		}
		else
		{
			Node<T>* curr;
			Node<T>* prev;

			curr = head;
			prev = curr;
			while (curr->next != head)
			{
				prev = curr;
				curr = curr->next;
			}

			prev->next = head;
			tempData = curr->data;
			delete curr;
			return tempData;
		}
	}

	T removeAtPos(int pos)
	{
		if (pos <= 0)
		{
			cout << "Invalid Position\n";
			return NULL;
		}
		if (head == nullptr)
		{
			cout << "List Underflow!!\n";
			return NULL;
		}
		else if (pos == 1)
			return removeAtFirst();
		else
		{
			Node<T>* curr;
			Node<T>* prev;

			curr = head;
			prev = curr;
			for (int i = 0; i < pos - 1; i++)
			{
				prev = curr;
				curr = curr->next;
				if (curr == head)
				{
					cout << "Position out of Range\n";
					return NULL;
				}
			}

			prev->next = curr->next;
			T val = curr->data;
			delete curr;
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
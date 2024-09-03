//#pragma once
//#include <iostream>
//using namespace std;
//template <typename T> struct Node
//{
//	T data;
//	Node* next;
//	Node()
//	{
//		data = NULL;
//		next = nullptr;
//	}
//};
//
//template <typename T> class LinkedList
//{
//private:
//	Node<T>* head;
//public:
//	LinkedList()
//	{
//		head = nullptr;
//	}
//	~LinkedList()
//	{
//
//	}
//
//	void AddAtFirst(T val)
//	{
//		Node<T>* temp = new Node;
//		temp->data = val;
//		temp->next = head;
//		head = temp;
//	}
//
//	void AddATLast(T val)
//	{
//		if (head == nullptr)
//			AddAtFirst(val);
//		else
//		{
//			Node<T>* temp = new Node;
//			temp->data = val;
//			temp->next = nullptr;
//			Node<T>* curr = head;
//			while (curr->next != nullptr)
//				curr = curr->next;
//			curr->next = temp;
//		}
//	}
//
//	void AddAtpos(int pos, T val)
//	{
//		if (pos == 1 || head == nullptr)
//			AddAtFirst(val);
//		else
//		{
//			Node<T>* temp = new Node;
//			temp->data = val;
//			temp->next = nullptr;
//
//			Node<T>* prev;
//			Node<T>* curr = head;
//			for (int i = 0; i < pos; i++)
//			{
//				prev = curr;
//				curr = curr->next;
//			}
//			temp->next = curr;
//			prev->next = temp;
//		}
//	}
//
//	T removeAtFirst()
//	{
//		Node<T>* temp;
//		temp = head;
//		head = head->next;
//		T val = temp->data;
//		delete temp;
//		return val;
//	}
//
//	T removeAtLast()
//	{
//		Node<T>* curr;
//		Node<T>* prev;
//		curr = head;
//		while (curr->next != nullptr)
//		{
//			prev = curr;
//			curr = curr->next;
//		}
//		prev->next = nullptr;
//		T val = curr->data;
//		delete curr;
//		return val;
//	}
//
//	T removeAtPos(int pos)
//	{
//		Node<T>* curr;
//		Node<T>* prev;
//		curr = head;
//		for (int i = 0; i < pos; i++)
//		{
//			prev = curr;
//			curr = curr->next;
//		}
//		prev->next = curr->next;
//		T val = curr->data;
//		delete curr;
//		return val;
//	}
//
//	void searchEle(T val)
//	{
//		Node<T>* curr;
//		int i = 0;
//		curr = head;
//		while (curr != nullptr)
//		{
//			i++;
//			if (curr->data == val)
//				cout << "value found at " << i << endl;
//		}
//		if (curr == nullptr)
//			cout << "value not found\n";
//	}
//};
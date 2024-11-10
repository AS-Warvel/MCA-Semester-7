#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

class LinkedList
{
	node* head;
public:
	LinkedList()
	{
		head = nullptr;
	}
	~LinkedList() { }

	void createList()
	{
		node* temp;
		node* temp2;
		head = new node;
		head->data = 1;
		temp = head;
		for (int i = 1; i < 10; i++)
		{
			temp2 = new node;
			temp2->data = i + 1;
			temp->next = temp2;
			temp = temp2;
		}
		temp2->next = nullptr;
	}

	void modifyList()
	{
		node* temp = head;
		node* last_node = head;
		
		while (last_node->next != nullptr)
			last_node = last_node->next;
		
		for (int i = 1; i < 4; i++)
			temp = temp->next;

		last_node->next = temp;
	}

	void loop_detection()
	{
		node* slow = head;
		node* fast = head;
		bool detected = false;
		while (slow != nullptr && fast != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				detected = true;
				break;
			}
		}
		if (detected)
		{
			slow = head;
			while (slow->next != fast->next)
			{
				slow = slow->next;
				fast = fast->next;
			}
			fast->next = nullptr;
		}
		else
			cout << "no loop detected!\n";
	}

	void display()
	{
		node* temp = head;
		for (int i = 0; i < 20; i++)
		{
			cout << temp->data << "\t";
			temp = temp->next;
			if (temp == nullptr)
				break;
		}
		cout << endl;
	}
};

void loopDetectionImpl()
{
	LinkedList l;
	
	l.createList();
	l.display();
	l.loop_detection();

	l.modifyList();
	l.display();
	
	l.loop_detection();
	
	l.display();
	l.loop_detection();

	system("pause");
}
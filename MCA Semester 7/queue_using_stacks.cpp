#include "headers/stack&queses/stack.h";

template <typename T> class QueueUsingStack
{
	Stack<T> stk1;
	Stack<T> stk2;
public:
	QueueUsingStack()
	{
	}

	~QueueUsingStack()
	{
	}

	void enqueue(T val)
	{
		if (stk1.isFull())
			cout << "Queue Overflow\n";
		else
			stk1.push(val);
	}

	T dequeue()
	{
		T val = NULL;
		
		if (stk1.isEmpty() && stk2.isEmpty())
		{
			cout << "Queue Underflow\n";
			return NULL;
		}
		else if (stk2.isEmpty())
		{
			while (!stk1.isEmpty())
				stk2.push(stk1.pop());
		}

		val = stk2.pop();
		return val;
	}

};

void queueUsingStacksImpl()
{
	QueueUsingStack<int> q;
	int selection;
	int ele;
	while (true)
	{
		system("cls");
		cout << "      ***** Queue Using Stack *****\n\n";


		cout << "Select an option:-\n";
		cout << "1) Add an Element\n";
		cout << "2) Remove an Element\n";
		cout << "3) End Program\n";

		cout << "Enter: ";
		cin >> selection;

		if (selection == 1)
		{
			cout << "Enter Element: ";
			cin >> ele;
			q.enqueue(ele);
			cout << endl;
			system("pause");
		}
		else if (selection == 2)
		{
			cout << "\nPopped Element: " << q.dequeue() << endl;
			system("pause");
		}
		else if (selection == 3)
			return;
	}
}
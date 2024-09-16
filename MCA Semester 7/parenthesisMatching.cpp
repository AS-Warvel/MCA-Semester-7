#include "headers/stack&queses/stack.h"
#include <iostream>
using namespace std;

void parenthesisMatching()
{
	system("cls");
	cout << "      ***** Parenthesis Matching *****\n\n";
	Stack<char> stk;
	char str[100];
	cout << "Enter Expression: ";
	cin.getline(str, 100) >> str;

	for (int i = 0; i < strlen(str); i++)
	{
		char c = str[i];
		if (c == '(' || c == '[' || c == '{')
			stk.push(c);
		if (c == ')' || c == ']' || c == '}')
		{
			if (stk.isEmpty())
			{
				cout << "Expected Opening Bracket at position " << i + 1 << endl;
				system("pause");
				return;
			}
			else if ((stk.peep() == '(' && c == ')') || (stk.peep() == '[' && c == ']') || (stk.peep() == '{' && c == '}'))
				stk.pop();
			else
			{
				cout << "Parenthesis mismatch at position " << i + 1 << endl;
				system("pause");
				return;
			}
		}
	}
	if (stk.isEmpty())
		cout << "Parenthesis matches Sucessfully\n";
	else
		cout << "Closing braces missing!\n";
	system("pause");
}
#include "headers/stack.h"
#include <iostream>
using namespace std;

void palindromeCheck()
{
	system("cls");
	cout << "      ***** Palindrome Check *****\n\n";
	Stack<char> stk;
	char str[100];
	cout << "Enter String: ";
	cin.getline(str, 100) >> str;

	for (int i = 0; i < strlen(str); i++)
		stk.push(str[i]);
	
	int i = 0;
	while (!stk.isEmpty())
	{
		if (stk.pop() != str[i])
		{
			cout << "String is not Palindrome\n";
			break;
		}
	}
	if (stk.isEmpty())
		cout << "String is Palindrome\n";
}
#include <iostream>
#include "headers/stack.h"
using namespace std;

int precNo(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

int CharToDigit(char str)
{
	switch (str)
	{
	case('0'):
		return 0;
	case('1'):
		return 1;
	case('2'):
		return 2;
	case('3'):
		return 3;
	case('4'):
		return 4;
	case('5'):
		return 5;
	case('6'):
		return 6;
	case('7'):
		return 7;
	case('8'):
		return 8;
	case('9'):
		return 9;
	default:
		cout << "Error Converting String to Integer" << endl;
		return NULL;
		break;
	}
}

void inFixToPostFix(char inFix[], char postFix[]) {
	Stack<char> s;
	int lastIdx = -1;
	for (int i = 0; i < strlen(inFix); i++)
	{
		if (inFix[i] == '/' || inFix[i] == '*' || inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '^' || inFix[i] == '(')
		{
			if (inFix[i] != '(')
				postFix[++lastIdx] = ' ';
			if (s.isEmpty())
				s.push(inFix[i]);
			else if (precNo(inFix[i]) > precNo(s.peep()))
				s.push(inFix[i]);
			else if (precNo(inFix[i]) < precNo(s.peep()))
			{
				while (!s.isEmpty())
				{
					if (precNo(inFix[i]) > precNo(s.peep()))
						break;
					postFix[++lastIdx] = s.pop();
					postFix[++lastIdx] = ' ';

				}
				s.push(inFix[i]);
			}
			else if (precNo(inFix[i]) == precNo(s.peep()))
			{
				postFix[++lastIdx] = s.pop();
				postFix[++lastIdx] = ' ';
				s.push(inFix[i]);
			}
		}
		else if (inFix[i] == ')')
		{
			while (s.peep() != '(') {
				postFix[++lastIdx] = ' ';
				postFix[++lastIdx] = s.pop();
			}
			s.pop();
		}
		else
			postFix[++lastIdx] = inFix[i];
	}
	while (!s.isEmpty()) {
		postFix[++lastIdx] = ' ';
		postFix[++lastIdx] = s.pop();

	}
	postFix[++lastIdx] = '\0';
}

int postFixEval(char postFix[])
{
	Stack<float> s;
	float oprand1;
	float oprand2;
	int num = 0;
	for (int i = 0; i < strlen(postFix); i++)
	{
		if (postFix[i] == ' ')
		{
			if (postFix[i - 1] >= '0' && postFix[i - 1] <= '9')
			{
				s.push(num);
				num = 0;
			}
			continue;
		}
		else if (postFix[i] == '*')
		{
			oprand1 = s.pop();
			oprand2 = s.pop();
			s.push(oprand2 * oprand1);
		}
		else if (postFix[i] == '/')
		{
			oprand1 = s.pop();
			oprand2 = s.pop();
			s.push(oprand2 / oprand1);
		}
		else if (postFix[i] == '+')
		{
			oprand1 = s.pop();
			oprand2 = s.pop();
			s.push(oprand2 + oprand1);
		}
		else if (postFix[i] == '-')
		{
			oprand1 = s.pop();
			oprand2 = s.pop();
			s.push(oprand2 - oprand1);
		}
		else if (postFix[i] == '^')
		{
			oprand1 = s.pop();
			oprand2 = s.pop();
			s.push(pow(oprand2, oprand1));
		}
		else
		{
			int d = CharToDigit(postFix[i]);
			num = num * 10 + d;
		}
	}
	return s.pop();
}

void assign4Impl() {
	cout << "      ***** Assignment 4 - Infix to Postfix *****\n\n";
	char postFixExpr[100];
	char inFixExpr[100];
	cout << "Enter Infix Expression: ";
	cin.getline(inFixExpr, 100) >> inFixExpr;
	inFixToPostFix(inFixExpr, postFixExpr);
	cout << postFixExpr << endl;
	cout << postFixEval(postFixExpr) << endl;
	system("pause");
}
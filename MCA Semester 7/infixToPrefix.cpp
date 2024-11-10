#include <iostream>
#include "headers/stack&queses/stack.h"
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
			if(inFix[i] != '(')
				postFix[++lastIdx] = ' ';
			if (s.isEmpty() || inFix[i] == '(')
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

void inFixToPreFix(char inFix[], char preFix[]) {
	Stack<char> s;
	int lastIdx = -1;
	for (int i = strlen(inFix) - 1; i >= 0; i--)
	{
		if (inFix[i] == '/' || inFix[i] == '*' || inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '^' || inFix[i] == ')')
		{
			if (inFix[i] != ')')
				preFix[++lastIdx] = ' ';
			if (s.isEmpty() || inFix[i] == ')')
				s.push(inFix[i]);
			else if (precNo(inFix[i]) > precNo(s.peep()))
				s.push(inFix[i]);
			else if (precNo(inFix[i]) < precNo(s.peep()))
			{
				while (!s.isEmpty())
				{
					if (precNo(inFix[i]) > precNo(s.peep()))
						break;
					preFix[++lastIdx] = s.pop();
					preFix[++lastIdx] = ' ';
				}
				s.push(inFix[i]);
			}
			else if (precNo(inFix[i]) == precNo(s.peep()))
			{
				preFix[++lastIdx] = s.pop();
				preFix[++lastIdx] = ' ';
				s.push(inFix[i]);
			}
		}
		else if (inFix[i] == '(')
		{
			while (s.peep() != ')') {
				preFix[++lastIdx] = ' ';
				preFix[++lastIdx] = s.pop();
			}
			s.pop();
		}
		else
			preFix[++lastIdx] = inFix[i];
	}
	while (!s.isEmpty()) {
		preFix[++lastIdx] = ' ';
		preFix[++lastIdx] = s.pop();
	}
	preFix[++lastIdx] = '\0';

	// reversing the string
	char c;
	int length = strlen(preFix);
	for (int i = 0; i < length / 2; i++)
	{
		c = preFix[i];
		preFix[i] = preFix[length - 1 - i];
		preFix[length - 1 - i] = c;
	}
}

float postFixEval(char postFix[])
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

void infixToPrefixImpl() {
	system("cls");

	cout << "      ***** Assignment 4 - Infix to Postfix *****\n\n";
	
	char inFixExpr[100];
	char postFixExpr[100];
	char preFixExpr[100];
	cout << "Enter Infix Expression: ";
	cin.getline(inFixExpr, 100) >> inFixExpr;
	inFixToPostFix(inFixExpr, postFixExpr);
	inFixToPreFix(inFixExpr, preFixExpr);
	cout << "Postfix Form - " << postFixExpr << endl;
	cout << "Prefix Form - " << preFixExpr << endl;
	cout << "Evaluation: " << postFixEval(postFixExpr) << endl;
	system("pause");
}
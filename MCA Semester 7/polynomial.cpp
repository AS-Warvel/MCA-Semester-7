// MCA Semester 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define MAX_TERMS 50

using namespace std;

struct Term {
	int coeff;
	int expo;
};

class Polynomial {
private:
	Term terms[MAX_TERMS];
public:
	int no_of_terms;
	
	Polynomial()
	{
		no_of_terms = 0;
	}

	void clear()
	{
		no_of_terms = 0;
	}

	void addTerm(int coeff, int expo) {
		int i;
		for (i = 0; i < no_of_terms; i++)
		{
			if (terms[i].expo == expo)
			{
				terms[i].coeff += coeff;
				break;
			}
		}
		if (i >= no_of_terms)
		{
			terms[no_of_terms].coeff = coeff;
			terms[no_of_terms].expo = expo;
			no_of_terms++;
		}
	}
	void print() {
		for (int i = 0; i < no_of_terms; i++) {
			if (terms[i].coeff < 0)
				cout << '(' << terms[i].coeff << ')';
			else
				cout << terms[i].coeff;
			if (terms[i].expo != 0)
			{
				if (terms[i].expo > 0)
					cout << 'x' << '^' << terms[i].expo;
				else
					cout << 'x' << '^' << '(' << terms[i].expo << ')';
			}
			if (i != (no_of_terms - 1)) {
				cout << " + ";
			}
		}
	}
	Polynomial operator+(Polynomial& other)
	{
		Polynomial p;

		for (int i = 0; i < no_of_terms; i++)
			p.addTerm(terms[i].coeff, terms[i].expo);

		int j;
		for (int i = 0; i < other.no_of_terms; i++)
		{
			j = 0;
			for (j; j < no_of_terms; j++)
			{
				if (other.terms[i].expo == p.terms[j].expo)
				{
					p.terms[j].coeff += other.terms[i].coeff;
					break;
				}
			}
			if (j == no_of_terms)
				p.addTerm(other.terms[i].coeff, other.terms[i].expo);
		}
		return p;
	}

	Polynomial operator-(Polynomial& other)
	{
		Polynomial p;

		for (int i = 0; i < no_of_terms; i++)
			p.addTerm(terms[i].coeff, terms[i].expo);

		int j;
		for (int i = 0; i < other.no_of_terms; i++)
		{
			j = 0;
			for (j; j < no_of_terms; j++)
			{
				if (other.terms[i].expo == p.terms[j].expo)
				{
					p.terms[j].coeff -= other.terms[i].coeff;
					break;
				}
			}
			if (j == no_of_terms)
				p.addTerm(other.terms[i].coeff * (-1), other.terms[i].expo);
		}
		return p;
	}
	int Evaluation(int val)
	{
		int result = 0;
		for (int i = 0; i < no_of_terms; i++)
		{
			result += terms[i].coeff * (pow(val, terms[i].expo));
		}
		return result;
	}
};

void polynomialimpl()
{
	Polynomial p1;
	Polynomial p2;
	Polynomial p3;


	int tempCoeff;
	int tempExpo;
	char selection;

	while (true) {

		p1.clear();
		p2.clear();
		p3.clear();

		system("cls");
		cout << "      ***** Assignment 2 - Polynomials *****\n\n";
		cout << "Enter First Polynomial:- \n";
		int i = 1;
		while (true) {
			cout << "Term " << i << ":- \n";
			cout << "Coefficient: ";
			cin >> tempCoeff;
			cout << "Exponent: ";
			cin >> tempExpo;
			p1.addTerm(tempCoeff, tempExpo);
			while (true)
			{
				cout << "Add More Terms[Y/N]: ";
				cin >> selection;
				if (selection == 'Y' || selection == 'y')
				{
					i++;
					break;
				}
				if (selection == 'N' || selection == 'n')
					break;
			}
			if (selection == 'N' || selection == 'n')
				break;
		}
		system("cls");
		cout << "First Polynomial: ";
		p1.print();
		cout << '\n';
		system("pause");
		system("cls");
		cout << "Enter Second Polynomial:- \n";

		i = 1;
		while (true) {

			cout << "Term " << i << ":- \n";
			cout << "Coefficient: ";
			cin >> tempCoeff;
			cout << "Exponent: ";
			cin >> tempExpo;
			p2.addTerm(tempCoeff, tempExpo);
			while (true)
			{
				cout << "Add More Terms[Y/N]: ";
				cin >> selection;
				if (selection == 'Y' || selection == 'y')
				{
					i++;
					break;
				}
				if (selection == 'N' || selection == 'n')
					break;
			}
			if (selection == 'N' || selection == 'n')
				break;
		}
		while (true) {
			system("cls");
			cout << "First Polynomial: ";
			p1.print();
			cout << '\n';

			cout << "Second Polynomial: ";
			p2.print();
			cout << '\n';

			cout << "\nA) Add the two polynomials\n";
			cout << "B) Subtract polynimials\n";
			cout << "C) Evaluate\n";
			cout << "D) Restart the Program\n";
			cout << "E). End the Program\n\n";
			cin >> selection;
			if (selection == 'A' || selection == 'a') {
				cout << "\n";
				p1.print();
				cout << " + ";
				p2.print();
				p3 = p1 + p2;
				cout << " = ";
				p3.print();
				cout << '\n';

				char c;
				int x;
				cout << "Evaluate the Result? (Y/N): ";
				cin >> c;

				if (c == 'y' || c == 'Y')
				{
					cout << "Enter value for variable: ";
					cin >> x;
					cout << endl <<  "Result: " << p3.Evaluation(x) << endl;
					system("pause");
				}
			}
			else if (selection == 'B' || selection == 'b') {
				cout << "\n";
				p1.print();
				cout << " - (";
				p2.print();
				p3 = p1 - p2;
				cout << ") = ";
				p3.print();
				cout << '\n';

				char c;
				int x;
				cout << "Evaluate the Result? (Y/N): ";
				cin >> c;

				if (c == 'y' || c == 'Y')
				{
					cout << "Enter value for variable: ";
					cin >> x;
					cout << endl << "Result: " << p3.Evaluation(x) << endl;
					system("pause");
				}
			}
			else if (selection == 'C' || selection == 'c') {
				int x;
				cout << "Which variable to Evaluate (1/2) : ";
				cin >> x;
				if (x == 1)
				{
					cout << "Enter value for variable: ";
					cin >> x;
					cout << "Evaluation: " << p1.Evaluation(x) << endl;
				}
				else if (x == 2)
				{
					cout << "Enter value for variable: ";
					cin >> x;
					cout << "Evaluation: " << p2.Evaluation(x) << endl;
				}
				system("pause");
			}
			else if (selection == 'D' || selection == 'd' || selection == 'e' || selection == 'E') {
				system("cls");
				break;
			}
		}
		if (selection == 'e' || selection == 'E') {
			break;
		}

	}
}
#include <iostream>
#define MAX_TERMS 50

using namespace std;

struct Term {
	int coeff;
	int expo;
};

class Polynomial2 {
private:
	Term terms[MAX_TERMS];
public:
	int no_of_terms;

	void read() {
		no_of_terms;
		cout << "Enter no of terms for the Polynomial: ";
		cin >> no_of_terms;
		int i;

		for (i = 0; i < no_of_terms; i++)
		{
			cout << "Enter Coefficient and Exponent: ";
			cin >> terms[i].coeff >> terms[i].expo;
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
	Polynomial2 operator+(Polynomial2& other)
	{
		Polynomial2 p;

		for (int i = 0; i < no_of_terms; i++)
		{
			p.terms[i].coeff = terms[i].coeff;
			p.terms[i].expo = terms[i].expo;
		}
		p.no_of_terms = no_of_terms;
		int j;
		for (int i = 0; i < other.no_of_terms; i++)
		{
			for (j = 0; j < no_of_terms; j++)
			{
				if (other.terms[i].expo == p.terms[j].expo)
				{
					p.terms[j].coeff += other.terms[i].coeff;
					break;
				}
			}
			if (j == no_of_terms)
			{
				p.terms[p.no_of_terms].coeff = other.terms[i].coeff;
				p.terms[p.no_of_terms].expo = other.terms[i].expo;
				p.no_of_terms++;
			}
		}
		return p;
	}

	Polynomial2 operator-(Polynomial2& other)
	{
		Polynomial2 p;

		for (int i = 0; i < no_of_terms; i++)
		{
			p.terms[i].coeff = terms[i].coeff;
			p.terms[i].expo = terms[i].expo;
		}
		p.no_of_terms = no_of_terms;
		int j;
		for (int i = 0; i < other.no_of_terms; i++)
		{
			for (j = 0; j < no_of_terms; j++)
			{
				if (other.terms[i].expo == p.terms[j].expo)
				{
					p.terms[j].coeff -= other.terms[i].coeff;
					break;
				}
			}
			if (j == no_of_terms)
			{
				p.terms[p.no_of_terms].coeff = (-1) * other.terms[i].coeff;
				p.terms[p.no_of_terms].expo = other.terms[i].expo;
				p.no_of_terms++;
			}
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

void polynomial2impl()
{
	Polynomial2 p1;
	Polynomial2 p2;
	Polynomial2 p3;

	char selection;

	system("cls");
	cout << "      ***** Assignment 2 - Polynomials *****\n\n";
	while (true) {
		system("cls");
		cout << "First Polynomial:-\n";
		p1.read();
		p1.print();
		cout << '\n';
		system("pause");
		cout << "Enter Second Polynomial:- \n";
		p2.read();
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
					cout << endl << "Result: " << p3.Evaluation(x) << endl;
					system("pause");
				}
			}
			else if (selection == 'B' || selection == 'b')
			{
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
			else if (selection == 'C' || selection == 'c')
			{
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
		if (selection == 'e' || selection == 'E')
			break;
	}
}
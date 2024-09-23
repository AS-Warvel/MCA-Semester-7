#include <iostream>
using namespace std;
struct TermNode
{
	int coeff;
	int expo;
	TermNode* next;
};

class Polynomial_LL
{
	TermNode* first;
public:
	Polynomial_LL()
	{
		first = nullptr;
	}

	~Polynomial_LL()
	{
	}

	void addTerms(int coeff, int expo)
	{
		if (first == nullptr)
		{
			first = new TermNode;
			first->coeff = coeff;
			first->expo = expo;
			first->next = nullptr;
		}
		else if (first->expo < expo)
		{
			TermNode* newNode = new TermNode;
			newNode->coeff = coeff;
			newNode->expo = expo;
			newNode->next = first;
			first = newNode;
		}
		else
		{
			TermNode* temp;
			temp = first;
			while (temp->next != nullptr)
			{
				if (temp->next->expo == expo)
				{
					temp->next->coeff += coeff;
					return;
				}
				else if (temp->next->expo < expo)
					break;

				temp = temp->next;
			}
			TermNode* newNode = new TermNode;
			newNode->coeff = coeff;
			newNode->expo = expo;
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}

	Polynomial_LL operator+(Polynomial_LL other)
	{
		if (first != nullptr || other.first != nullptr)
		{
			Polynomial_LL p;
			TermNode** p_curr_address;
			TermNode* curr;
			TermNode* other_curr;

			p_curr_address = &p.first;
			curr = first;
			other_curr = other.first;
			do {
				*p_curr_address = new TermNode;
				if (curr->expo == other_curr->expo)
				{
					(*p_curr_address)->coeff = curr->coeff + other_curr->coeff;
					(*p_curr_address)->expo = curr->expo;
					(*p_curr_address)->next = nullptr;
					p_curr_address = &((*p_curr_address)->next);
				}
				else if (curr->expo > other_curr->expo)
				{
					(*p_curr_address)->coeff = curr->coeff;
					(*p_curr_address)->expo = curr->expo;
					(*p_curr_address)->next = nullptr;
					p_curr_address = &((*p_curr_address)->next);
				}
				else
				{

				}
			} while (curr->next != nullptr && other_curr->next != nullptr);
			//delete p_curr->next;
			//p_curr->next = nullptr;
		}
	}

	Polynomial_LL operator-(Polynomial_LL other)
	{

	}

	void print()
	{
		TermNode* curr;
		curr = first;
		while (curr != nullptr) {
			if (curr->coeff < 0)
				cout << '(' << curr->coeff << ')';
			else
				cout << curr->coeff;
			if (curr->expo != 0)
			{
				if (curr->expo > 0)
					cout << 'x' << '^' << curr->expo;
				else
					cout << 'x' << '^' << '(' << curr->expo << ')';
			}
			if (curr->next != nullptr)
				cout << " + ";

			curr = curr->next;
		}
	}
};

void polynomial_LL_impl()
{
	Polynomial_LL p;
	p.addTerms(2, 2);
	p.addTerms(1, 3);
	p.addTerms(5, 0);
	p.print();
	system("pause");
}

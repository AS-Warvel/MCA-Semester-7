#include <iostream>
using namespace std;
# define MAX 10

void editDistanceImpl()
{
	system("cls");
	
	char s1[MAX] = "keep";
	char s2[MAX] = "helps";
	int n = 5;
	int m = 6;

	int d[MAX][MAX];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			d[i][j] = -1;
	}

	int cost, min;

	for (int i = 0; i < n; i++)
		d[i][0] = i;
	for (int i = 0; i < m; i++)
		d[0][i] = i;

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (s1[i - 1] == s2[j - 1])
				cost = 0;
			else
				cost = 1;
			min = d[i - 1][j] + 1;
			if (d[i][j - 1] + 1 < min)
				min = d[i][j - 1] + 1;
			if (d[i - 1][j - 1] + cost < min)
				min = d[i - 1][j - 1] + cost;
			d[i][j] = min;
		}
	}
	cout << "\t";
	for (int i = 0; i < m - 1; i++)
		cout << "\t" << s2[i];
	cout << endl << endl;

	for (int j = 0; j < m; j++)
		cout << "\t" << d[0][j];
	cout << endl << endl;
	for (int i = 1; i < n; i++)
	{
		cout << s1[i - 1] << "\t";
		for (int j = 0; j < m; j++)
			cout << d[i][j] << "\t";
		cout << endl << endl;
	}

	system("pause");
}
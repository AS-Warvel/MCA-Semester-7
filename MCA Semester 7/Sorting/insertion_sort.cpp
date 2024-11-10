#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
	int ele;
	int j;
	for (int i = 1; i < size; i++)
	{
		ele = arr[i];
		for (j = i - 1; j >= 0 && ele < arr[j]; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = ele;
	}
}

void insertionSortImpl()
{
	system("cls");

	int size;
	int arr[20];

	cout << "Enter No. of Elements (max = 20): ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter: ";
		cin >> arr[i];
	}

	insertionSort(arr, size);

	cout << "\nBubble Sort:-\n\n";
	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t";
	cout << endl;

	system("pause");
}
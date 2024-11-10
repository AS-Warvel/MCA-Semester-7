#include <iostream>
using namespace std;

void quickSort(int arr[], int start, int end)
{
	if (start >= end)
		return;

	int pivot = arr[end];

	int aux;
	int i = start;
	for (int j = start; j <= end - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			aux = arr[i];
			arr[i] = arr[j];
			arr[j] = aux;
			i++;
		}
	}
	arr[end] = arr[i];
	arr[i] = pivot;

	quickSort(arr, start, i - 1);
	quickSort(arr, i + 1, end);
}

void quickSortImpl()
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

	quickSort(arr, 0, size - 1);

	cout << "\nBubble Sort:-\n\n";
	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t";
	cout << endl;

	system("pause");
}
#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{
	int aux;
	int minIndex;
	for (int i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < size; j++)
			if (arr[minIndex] > arr[j])
				minIndex = j;
		// swapping
		aux = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = aux;
	}
}
void selectionSortImpl()
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

	selectionSort(arr, size);

	cout << "\nBubble Sort:-\n\n";
	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t";
	cout << endl;

	system("pause");
}
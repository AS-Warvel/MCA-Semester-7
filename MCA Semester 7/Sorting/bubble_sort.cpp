#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
	int aux;
	bool swapped;
	for (int i = 0; i < size; i++)
	{
		swapped = false;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				aux = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = aux;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}




void bubbleSortImpl()
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

	bubbleSort(arr, size);

	cout << "\nBubble Sort:-\n\n";
	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t";
	cout << endl;

	system("pause");
}
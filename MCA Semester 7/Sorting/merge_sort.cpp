#include <iostream>
using namespace std;

void mergeSort(int arr[], int start, int end)
{
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);

	int l = mid - start + 1;
	int r = end - mid;
	int* L = new int[l];
	int* R = new int[r];

	for (int i = 0; i < l; i++)
		L[i] = arr[start + i];

	for (int i = 0; i < r; i++)
		R[i] = arr[mid + 1 + i];

	int i = 0, j = 0, arrIdx = start;
	while (i < l && j < r)
	{
		if (L[i] <= R[j])
		{
			arr[arrIdx] = L[i];
			i++;
		}
		else
		{
			arr[arrIdx] = R[j];
			j++;
		}
		arrIdx++;
	}

	while (i < l)
	{
		arr[arrIdx] = L[i];
		i++;
		arrIdx++;
	}
	while (j < r)
	{
		arr[arrIdx] = R[j];
		j++;
		arrIdx++;
	}
	delete[] L;
	delete[] R;
}

void mergeSortImpl()
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

	mergeSort(arr, 0, size - 1);

	cout << "\nBubble Sort:-\n\n";
	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t";
	cout << endl;

	system("pause");
}
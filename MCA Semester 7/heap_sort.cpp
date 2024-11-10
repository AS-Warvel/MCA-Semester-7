#include <iostream>
using namespace std;

void addToHeap(int val, int heap[], int& size)
{
	int childIndex = size + 1;
	heap[childIndex] = val;
	size++;
	
	int parentIndex;
	while (childIndex != 1)
	{
		if (childIndex % 2 == 1)
			parentIndex = (childIndex - 1) / 2;
		else
			parentIndex = childIndex / 2;
		
		if (heap[parentIndex] >= heap[childIndex])
			break;
		// sifting Up
		int temp;
		temp = heap[parentIndex];
		heap[parentIndex] = heap[childIndex];
		heap[childIndex] = temp;

		childIndex = parentIndex;
	}
}

void heapSort(int heap[], int size)
{
	int temp;
	int childIndex;
	int parentIndex;
	for (int i = 0; i < size; i++)
	{
		temp = heap[1];
		heap[1] = heap[size - i];
		heap[size - i] = temp;
		parentIndex = 1;
		
		while (true)
		{
			if ((parentIndex * 2 + 1 <= size - 1 - i) && heap[parentIndex * 2 + 1] >= heap[parentIndex * 2] && heap[parentIndex] < heap[parentIndex * 2 + 1])
				childIndex = parentIndex * 2 + 1;
			else if (parentIndex * 2 <= size - 1 - i && heap[parentIndex] < heap[parentIndex * 2])
				childIndex = parentIndex * 2;
			else
				break;
			temp = heap[parentIndex];
			heap[parentIndex] = heap[childIndex];
			heap[childIndex] = temp;
			parentIndex = childIndex;
		}
	}
}

void heapSortImpl()
{
	system("cls");

	int dataSize;
	int givenData[100];
	
	cout << "Enter No. of Elements (max = 100): ";
	cin >> dataSize;
	for (int i = 0; i < dataSize; i++)
	{
		cout << "Enter: ";
		cin >> givenData[i];
	}

	int heapSize = 0;
	int heapedData[100];
	heapedData[0] = 0;
	
	for (int i = 0; i < dataSize; i++)
		addToHeap(givenData[i], heapedData, heapSize);
	cout << endl;
	cout << "Heapified Tree:-\n";
	for (int i = 1; i < heapSize + 1; i++)
		cout << heapedData[i] << '\t';

	cout << endl << endl;

	cout << "Heap Sorted:-\n";
	heapSort(heapedData, heapSize);
	for (int i = 1; i < heapSize + 1; i++)
		cout << heapedData[i] << '\t';
	
	cout << endl;
	system("pause");
}
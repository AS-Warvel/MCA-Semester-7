#include <iostream>
using namespace std;

void inputArray(int max_size, int& curr_size, int arr[]) {
	int user_input_size;
	while (true) {
		curr_size = 0;
		cout << "Enter the no of elements to add into array(max_size = 10): ";
		cin >> user_input_size;
		if (user_input_size <= 10) {
			for (int i = 0; i < user_input_size; i++) {
				cout << "Enter element: ";
				cin >> arr[i];
				curr_size++;
			}
			break;
		}
	}
}

void displayArray(int arr[], int size) {
	cout << "Array: \n";
	cout << "element: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << '\t';
	}
	cout << endl;
	cout << "index:   ";
	for (int i = 0; i < size; i++) {
		cout << i << '\t';
	}
}

void deleteFromArray(int index, int arr[], int& curr_size) {
	for (int i = index; i < curr_size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	curr_size--;
}

void insertIntoArray(int index, int arr[], int& array_size, int value) {
	for (int i = array_size - 1; i >= index; i--) {
		arr[i + 1] = arr[i];
	}
	arr[index] = value;
	array_size++;
}

int linearSearch(int arr[], int size, int value) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			return i;
		}
	}
	cout << "\nvalue not found !!";
	return -1;
}

void deleteByIndex(int arr[], int& curr_size, int max_size) {
	int selection;
	int index;
	if (curr_size == 0)
	{
		cout << "Array is Empty !!\n";
		system("pause");
		return;
	}
	while (true) {
		system("cls");
		displayArray(arr, curr_size);
		cout << "\n1) Delete At index.";
		cout << "\n2) Delete After index.";
		cout << "\n3) Delete Before index.";

		cout << "\n\nEnter: ";
		cin >> selection;

		if (selection == 1) {
			while (true) {
				cout << "\nEnter index: ";
				cin >> index;
				if (index >= curr_size || index < 0) {
					cout << "Index out of Range !!";
					continue;
				}

				deleteFromArray(index, arr, curr_size);
				break;
			}
			break;
		}
		else if (selection == 2) {
			while (true) {
				cout << "\nEnter index: ";
				cin >> index;
				if (index + 1 >= curr_size || index < -1) {
					cout << "Index out of Range !!";
					continue;
				}

				deleteFromArray(index + 1, arr, curr_size);
				break;
			}
			break;
		}
		else if (selection == 3) {
			while (true) {
				cout << "\nEnter index: ";
				cin >> index;
				if (index > curr_size || index < 1) {
					cout << "Index out of Range !!";
					continue;
				}

				deleteFromArray(index - 1, arr, curr_size);
				break;
			}
			break;
		}
	}
}

void deleteByValue(int arr[], int& curr_size, int max_size) {
	int selection;
	int index;
	int entered_value;
	if (curr_size == 0)
	{
		cout << "Array is Empty!!\n";
		system("pause");
		return;
	}
	while (true) {
		system("cls");
		displayArray(arr, curr_size);
		cout << "\n1) Delete After value.";
		cout << "\n2) Delete Before value.";
		cout << "\n\nEnter: ";
		cin >> selection;
		if (!(selection == 1 || selection == 2))
			continue;
		cout << "\nEnter value to Search: ";
		cin >> entered_value;
		if (selection == 1) {
			index = linearSearch(arr, curr_size, entered_value);
			if (index == -1) {
				cout << endl;
				system("pause");
				return;
			}
			if (index == curr_size - 1)
				return;
			deleteFromArray(index + 1, arr, curr_size);
			return;
		}
		else if (selection == 2) {
			index = linearSearch(arr, curr_size, entered_value);
			if (index == -1) {
				system("pause");
				return;
			}
			if (index == 0)
				return;
			deleteFromArray(index, arr, curr_size);
			return;
		}
	}
}

void insertByIndex(int arr[], int &curr_size, int max_size) {
	int selection;
	int index;
	int value;
	if (curr_size >= max_size)
	{
		cout << "Array is already Full !!\n";
		system("pause");
		return;
	}
	while (true)
	{
		system("cls");

		displayArray(arr, curr_size);

		cout << "\n1) Enter At index.";
		cout << "\n2) Enter After index.";
		cout << "\n3) Enter Before index.";
		cout << "\n\nEnter: ";
		cin >> selection;

		if (selection == 1) {
			while (true) {
				cout << "\nEnter index: ";
				cin >> index;
				if (index > curr_size || index < 0) {
					cout << "Index out of Range !!";
					continue;
				}

				cout << "\nEnter value: ";
				cin >> value;
				insertIntoArray(index, arr, curr_size, value);
				break;
			}
			break;
		}
		else if (selection == 2)
		{
			while (true)
			{
				cout << "\nEnter index: ";
				cin >> index;
				if (index >= curr_size || index < -1)
				{
					cout << "Index out of Range !!";
					continue;
				}

				cout << "\nEnter value: ";
				cin >> value;

				insertIntoArray(index + 1, arr, curr_size, value);

				break;
			}
			break;
		}
		else if (selection == 3) {
			while (true) {
				cout << "\nEnter index: ";
				cin >> index;
				if (index >= curr_size + 2 || index - 1 < 0) {
					cout << "Index out of Range !!";
					continue;
				}

				cout << "\nEnter value: ";
				cin >> value;
				insertIntoArray(index - 1, arr, curr_size, value);
				break;
			}
			break;
		}


	}
}

void insertByValue(int arr[], int& curr_size, int max_size) {
	int selection;
	int index;
	int entered_value;
	int value;
	if (curr_size >= max_size)
	{
		cout << "Array is already Full !!\n";
		system("pause");
		return;
	}
	while (true) {
		system("cls");
		displayArray(arr, curr_size);
		cout << "\n1) Enter After value.";
		cout << "\n2) Enter Before value.";
		cout << "\n\nEnter: ";
		cin >> selection;
		if (!(selection == 1 || selection == 2))
			continue;
		cout << "\nEnter value to Search: ";
		cin >> entered_value;
		if (selection == 1) {
			index = linearSearch(arr, curr_size, entered_value);
			if (index == -1) {
				system("pause");
				return;
			}
			cout << "\nEnter the new value: ";
			cin >> value;
			insertIntoArray(index + 1, arr, curr_size, value);
			return;
		}
		else if (selection == 2) {
			index = linearSearch(arr, curr_size, entered_value);
			if (index == -1) {
				system("pause");
				return;
			}
			cout << "\nEnter the new value: ";
			cin >> value;
			insertIntoArray(index, arr, curr_size, value);
			return;
		}
	}
}


int optionSelection() {
	int selection;
	cout << endl << endl;
	cout << "1) insert element by Index.";
	cout << "\n2) insert element by Value.";
	cout << "\n3) delete element by index.";
	cout << "\n4) delete element by value";
	cout << "\n5) Restart the Program.";
	cout << "\n6) End the Program.";
	cout << "\n\nEnter Option:";
	cin >> selection;
	return selection;
}
void arrayInsDelImpl() {
	const int max_size = 10;
	int current_size;
	int arr[max_size];
	int user_selection;

	while (true) {
		system("cls");
		cout << "      ***** Assignment 1 - Arrays *****\n\n";
		inputArray(max_size, current_size, arr);
		
		while (true) {
			system("cls");
			
			displayArray(arr, current_size);
			
			user_selection = optionSelection();

			if (user_selection == 1)
				insertByIndex(arr, current_size, max_size);
			else if (user_selection == 2)
				insertByValue(arr, current_size, max_size);
			else if (user_selection == 3)
				deleteByIndex(arr, current_size, max_size);
			else if (user_selection == 4)
				deleteByValue(arr, current_size, max_size);
			else if (user_selection == 5 || user_selection == 6)
				break;
		}
		if (user_selection == 6) {
			break;
		}
	}

}


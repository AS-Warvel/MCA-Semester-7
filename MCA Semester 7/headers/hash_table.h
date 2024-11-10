#pragma once
#include <iostream>
using namespace std;
#define MAX 23

struct StudentRecord
{
    int key;
    char name[20];
    int marks;
};

class HashTable
{
    StudentRecord table[MAX];
    int size;

private:
    int hashFunction(int key)
    {
        int tempArr[10];
        int arrSize = 0;

        while (key != 0)
        {
            tempArr[arrSize++] = key % 100;
            key = key / 100;
        }
        int sum = 0;
        for (int i = 0; i < arrSize; i++)
            sum += tempArr[i];
        // cout << endl <<  sum << endl;
        return sum % 100;
    }

public:
    HashTable()
    {
        size = MAX;
        for (int i = 0; i < size; i++)
        {
            table[i].key = 0;
        }
    }
    ~HashTable() {}

    void insert(int key, char name[], int marks)
    {
        int hash = hashFunction(key);
        // int index = hash % size;

        // linear probing...
        int i = 0;
        while (table[(hash + i) % size].key != 0)
            i++;

        // cout << endl << (hash + i) % size << endl;

        table[(hash + i) % size].key = key;

        int j;
        for (j = 0; name[j] != '\0'; j++)
            table[(hash + i) % size].name[j] = name[j];
        table[(hash + i) % size].name[j] = name[j];

        table[(hash + i) % size].marks = marks;
    }

    void search(int key)
    {
        int hash = hashFunction(key);
        int i = 0;
        while (table[(hash + i) % size].key != key && (i < size))
            i++;
        if (i < size)
        {
            cout << "Key : " << table[(hash + i) % size].key << endl;
            cout << "Name : " << table[(hash + i) % size].name << endl;
            cout << "Marks : " << table[(hash + i) % size].marks << endl;
        }
        else
            cout << "No Record Found" << endl;
    }

    void remove(int key)
    {
        int hash = hashFunction(key);
        int i = 0;
        while (table[(hash + i) % size].key != key && (i < size))
            i++;
        if (i < size)
            table[(hash + i) % size].key = 0;
        else
            cout << "Record doesn't Exist" << endl;
    }
};
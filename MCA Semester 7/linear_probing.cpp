#include "headers/hash_table.h"

void hashingImpl()
{
    system("cls");
    char name1[20] = "Amit";
    char name2[20] = "Rahul";
    char name3[20] = "Arsh";
    HashTable hashTable;
    hashTable.insert(21271457, name1, 90);
    hashTable.insert(21271400, name2, 95);
    hashTable.insert(21271480, name3, 85);
    hashTable.search(21271457);
    hashTable.search(21271400);
    hashTable.search(21271480);
    hashTable.remove(21271400);
    hashTable.search(21271400);
    system("pause");
    return;
}
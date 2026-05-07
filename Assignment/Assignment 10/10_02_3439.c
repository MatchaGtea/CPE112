#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 13

long long hashTable[TABLE_SIZE];

/* Initialize the hash table by setting all slots to -1 */
void initTable(void) {
    /* TODO 1 */
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

/* Insert a key using the Division Method and Linear Probing */
void insertHash(long long key) {
    /* TODO 2 */
    int index = key % TABLE_SIZE;           // a. initial index
    while (hashTable[index] != -1) {        // b. slot occupied?
        index = (index + 1) % TABLE_SIZE;   //    probe next slot
    }
    hashTable[index] = key;                 // c. store the key
}

/* Print the contents of the hash table */
void printTable(void) {
    /* TODO 3 */
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: %lld\n", i, hashTable[i]);
    }
}

void solve(void);

int main(void) {
    solve();
    return 0;
}

void solve(void) {
    long long students[] = {68070503480, 68070503468, 68070503493, 68070503410};
    int n = sizeof(students) / sizeof(students[0]);

    /* TODO 4 */
    initTable();                        // 1. prepare the array
    for (int i = 0; i < n; i++) {       // 2. insert each student
        insertHash(students[i]);
    }
    printTable();                       // 3. show final result
}
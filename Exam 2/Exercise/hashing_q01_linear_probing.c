/*
Topic: Hashing
Question 1: Linear probing

What to do:
- Complete insertHash.
- Hash function: h(k) = k % m.
- If table[index] is occupied, move to (index + 1) % m.
- Empty slots should contain -1.
- If table is full, ignore remaining keys.

Example input:
5 4
1 6 11 16

Example output:
-1 1 6 11 16
*/

#include <stdio.h>

#define MAX 100

void insertHash(int table[], int m, int keys[], int n)
{
    // TODO: initialize table slots to -1
    // TODO: insert each key using linear probing
    // TODO: wrap around using (index + 1) % m
    // TODO: stop inserting a key if the table is full
}

int main()
{
    int m, n;
    int table[MAX];
    int keys[MAX];

    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &keys[i]);
    }

    insertHash(table, m, keys, n);

    for (int i = 0; i < m; i++)
    {
        printf("%d", table[i]);
        if (i < m - 1)
        {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}

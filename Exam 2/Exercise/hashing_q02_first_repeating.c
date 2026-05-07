/*
Topic: Hashing
Question 2: First repeating ID

What to do:
- Complete firstRepeating.
- Return the first value that appears for the second time while scanning left to right.
- Return -1 if there is no repeated value.
- IDs are from 0 to 1000, so a seen/HASH array can be used.

Example input:
6
5 3 2 5 4 2

Example output:
5
*/

#include <stdio.h>

#define MAX 100
#define HASH 1001

int firstRepeating(int arr[], int n)
{
    // TODO: create seen[HASH] initialized to 0
    // TODO: scan arr from left to right
    // TODO: if seen[arr[i]] is already true, return arr[i]
    // TODO: otherwise mark seen[arr[i]] = 1

    return -1;
}

int main()
{
    int n;
    int arr[MAX];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int result = firstRepeating(arr, n);
    printf("%d\n", result);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 20

typedef struct {
    int audio_id;
    int frequency;
} HashEntry;

HashEntry table[TABLE_SIZE];

/* Initialize the hash table */
void initTable(void) {
    /* TODO 1: Loop from 0 to TABLE_SIZE - 1 */
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].audio_id  = -1;
        table[i].frequency =  0;
    }
}

/* Insert ID into Hash Table or increment frequency if it already exists */
void insertAndCount(int id) {
    /* TODO 2 */
    int index = id % TABLE_SIZE;                                        // a. initial index

    while (table[index].audio_id != -1 && table[index].audio_id != id) // b. skip occupied & different
        index = (index + 1) % TABLE_SIZE;

    if (table[index].audio_id == -1) {   // c. new ID → empty slot
        table[index].audio_id  = id;
        table[index].frequency = 1;
    } else {                             //    existing ID → increment
        table[index].frequency++;
    }
}

/* Scan the table and print sounds that appear 5 or more times */
void findViralSounds(void) {
    printf("Viral Brainrot Sounds (appeared 5 or more times):\n");
    /* TODO 3 */
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].audio_id != -1 && table[i].frequency >= 5)
            printf("Audio ID %d (Frequency: %d)\n", table[i].audio_id, table[i].frequency);
    }
}

void solve(void);

int main(void) {
    solve();
    return 0;
}

void solve(void) {
    int feed[] = {
        101, 777, 404, 777, 777, 202, 777, 101, 999, 999,
        101, 888, 999, 999, 777, 101, 888, 999, 101, 777
    };
    int n = sizeof(feed) / sizeof(feed[0]);

    /* TODO 4 */
    initTable();
    for (int i = 0; i < n; i++)
        insertAndCount(feed[i]);
    findViralSounds();
}
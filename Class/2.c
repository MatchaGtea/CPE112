#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;                  // Fixed: added semicolon
    struct node *next;
};

void countNodes(struct node *START);
struct node* search(struct node *START, int VAL);
struct node* insertBeg(struct node *START, int VAL);
struct node* insertEnd(struct node *START, int VAL);
struct node* insertBegCircular(struct node *START, int VAL);

int main() {
    // ...existing code...
}

// Algorithm to print the number of nodes [cite: 281]
void countNodes(struct node *START) {
    int count = 0;              // Step 1: Initialize count [cite: 264]
    struct node *ptr = START;   // Step 2: Initialize pointer [cite: 266]
    
    while (ptr != NULL) {       // Step 3: Repeat while ptr is not NULL [cite: 268]
        count = count + 1;      // Step 4: Increment count [cite: 271]
        ptr = ptr->next;        // Step 5: Move to next node [cite: 274]
    }
    printf("%d", count);        // Step 6: Write count [cite: 277]
}

// Searching for a value in the list [cite: 283]
struct node* search(struct node *START, int VAL) {
    struct node *ptr = START;   // Step 1 [cite: 285]
    
    while (ptr != NULL) {       // Step 2 [cite: 285]
        if (ptr->data == VAL) { // Step 3: Check if match [cite: 287]
            return ptr;         // Return the position [cite: 288]
        }
        ptr = ptr->next;        // Move to next node [cite: 291]
    }
    return NULL;                // Value not found [cite: 295]
}

// Case 1: Inserting at the beginning [cite: 331, 347]
struct node* insertBeg(struct node *START, int VAL) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node)); // Allocate memory [cite: 350]
    new_node->data = VAL;       // Step 4 [cite: 345]
    new_node->next = START;     // Step 5: Point to current start [cite: 346]
    START = new_node;           // Step 6: Update START [cite: 346]
    return START;
}

// Case 2: Inserting at the end [cite: 332, 389]
struct node* insertEnd(struct node *START, int VAL) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = VAL;       // Step 4 [cite: 382]
    new_node->next = NULL;      // Step 5 [cite: 383]

    if (START == NULL) {
        return new_node;
    }

    struct node *ptr = START;   // Step 6 [cite: 384]
    while (ptr->next != NULL) { // Step 7: Find the last node [cite: 385]
        ptr = ptr->next;        // Step 8 [cite: 386]
    }
    ptr->next = new_node;       // Step 9: Link new node [cite: 388]
    return START;
}

// Inserting at the beginning of a circular list [cite: 825, 872]
struct node* insertBegCircular(struct node *START, int VAL) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = VAL;

    if (START == NULL) {
        new_node->next = new_node;
        return new_node;
    }

    struct node *ptr = START;
    while (ptr->next != START) { // Step 6: Traverse to the last node [cite: 852]
        ptr = ptr->next;         // Step 7 [cite: 853]
    }
    new_node->next = START;      // Step 8: New node points to old start [cite: 855]
    ptr->next = new_node;        // Step 9: Last node points to new node [cite: 856]
    START = new_node;            // Step 10: Update START [cite: 870]
    return START;
}
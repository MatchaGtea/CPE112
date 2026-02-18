#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    int priority;
    struct node *next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int value, int priority) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;
    
    if (!front) {
        front = rear = newNode;
        return;
    }
    if (priority < front->priority) {
        newNode->next = front;
        front = newNode;
        return;
    }

    Node *temp = front;
    while (temp->next != NULL && temp->next->priority <= priority) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}/* insert by priority (highest first) */

int dequeue(void) {
    Node *temp;
    int val;
    if (!front) {
        return -1;
    }
    temp = front;
    val = front->data;
    front = front->next;
    if (!front) {
        rear = NULL;
    }
    free(temp);
    return val;
};/* remove from front; return -1 if empty */

int peek(void) {
    if (!front) {
        return -1;
    }
    return front->data;
};/* return front value, -1 if empty */

/* TODO: read n pairs (value, priority), enqueue each, then dequeue all and print */
void solve(int n) {
    int val, priority;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &val, &priority);
        enqueue(val, priority);
    }
    while (front != NULL) {
        printf("%d ", dequeue());
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}
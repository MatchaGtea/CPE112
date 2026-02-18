#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        return;
    }
    newNode->data = x;
    
    if (!front) {
        front = rear = newNode;
        newNode->next = front;
    } else {
        newNode->next = front;
        rear->next = newNode;
        rear = newNode;
    }
    rear = newNode;
}/* add at rear; rear->next = front to keep circular */

int dequeue(void) {
    Node *temp;
    int val;
    val = front->data;
    if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        temp = front;
        front = front->next;
        rear->next = front;
        free(temp); 
    }
    return val;

};/* remove from front; return -1 if empty */

int peek(void) {
    if (!front) {
        return -1;
    }
    return front->data;
};/* return front element, -1 if empty */

/* TODO: enqueue 1..n, then dequeue all and print in order */
void solve(int n) {
    int val;
    for (int i = 1; i <= n; i++){
        enqueue(i);
    }
    for (int i = 0; i < n; i++) {
        val = dequeue();
        printf("%d ", val);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

//enqueue เพิ่ม tail
//dequeue เอา head ออก
//peek ดู head

typedef struct node{
    int data;
    struct node* next;
}Node;

//insertlast
void enqueue(Node **head,int data){
    Node *newNode = malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    Node *current = *head;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(current -> next != NULL) current = current ->next;
    current -> next = newNode;
}

//pop head
int dequeue(Node **head){
    Node *current = *head;
    int data = current ->data;
    *head = current ->next;
    free(current);
    return data;
}

int peek(Node **head){
    Node *current = *head;
    if(current == NULL) return -1;
    return current->data;
}

int main(){
    int i ,n ,data;
    Node *head = NULL;
    scanf("%d",&n);
    for(i=0 ; i < n ;i++){
        scanf("%d",&data);
        enqueue(&head,data);
    }
    for(i = 0 ; i< n ; i++){
        printf("%d",dequeue(&head));
    }
}


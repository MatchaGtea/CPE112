#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//do Create Insert ( Head , Last )
struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data,struct Node* next){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) return NULL;
    newNode -> data = data;
    newNode -> next = next;
    return newNode;
}

struct Node* insertHead(int data,struct Node* head){
    struct Node *newNode  = ( struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) return NULL;
    newNode -> data = data;
    newNode -> next = head;
    return newNode;
}

struct Node* insertLast(int data,struct Node* head){
    struct Node* newNode = createNode(data,NULL);
    if(head == NULL) return newNode;
    
    struct Node* Last = head;
    while(Last->next != NULL){
        Last = Last->next;
    }

    Last -> next = newNode;
    return head;
}

void printList(struct Node* temp){
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

int main(){
    struct Node *start = NULL;
    start = createNode(20,start);
    start = insertHead(50,start);
    start = insertLast(10,start);

    printList(start);
}
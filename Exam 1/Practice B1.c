#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void insertHead(struct node **head,int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    (*head) = newNode;
}

void insertLast(struct node **head,int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct node *current = *head;
    while (current ->next != NULL) current = current ->next;
    newNode ->prev = current;
    current->next = newNode;
}

void Printlist(struct node* head){
    struct node *current = head;
    if(current == NULL) return;
    while(current != NULL){
        if(current->prev != NULL && current->data < current->prev->data){
            printf("%d ",current->data);
        }
        current = current->next;
    }
    printf("\n");
}

int main(){
    int i,n,data;
    struct node *head = NULL;
    scanf("%d",&n);
    for(i = 0 ; i < n ; i++){
        scanf("%d",&data);
        insertLast(&head,data);
    }
    Printlist(head);
}
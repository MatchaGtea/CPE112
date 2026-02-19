#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}Node;

void print(Node *head){
    Node *current = head;
    while(current != NULL){
        printf("%d",current->data);
        current = current ->next;
    }
}

void printrev(Node *head){
    Node *current = head;
    while(current -> next != NULL) current = current -> next;
    do{
        printf("%d",current->data);
        current = current->prev;
    }while(current != NULL);
}

void insertLast(Node **head,int data){
    Node *newNode = malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node *current = *head;
    while(current -> next != NULL)  current = current->next;
    current->next = newNode;
    newNode-> prev = current;
}

void insertHead(Node **head,int data){
    Node* newNode = malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    if(*head == NULL){
        *head = newNode;
        return ;
    }
    newNode -> next = *head;
    (*head) -> prev = newNode;
    (*head) = newNode;
}

void Remove(Node **head){
    Node* current = *head;
    if (current == NULL) return; // Check if head is NULL

    Node* before = current->prev;
    Node* after = current->next;

    if (before != NULL) {
        before->next = after; // Update previous node's next pointer
    }
    if (after != NULL) {
        after->prev = before; // Update next node's previous pointer
    }

    free(current);
    *head = after; // Update head to the next node
}

int main(){
    int i , n , data;
    Node *head = NULL;
    scanf("%d",&n);
    for(i = 1 ; i<= n ;i++){
        insertHead(&head,i);
    }

    Node* temp = head; // Temporary pointer to traverse the list
    while(temp != NULL){
        if(temp->data == 3){
            Node* nextNode = temp->next; // Save the next node before removing
            Remove(&temp);
            temp = nextNode; // Move to the next node
        } else {
            temp = temp->next;
        }
    }

    printf("-----------\n");
    printf("Print\t : ");
    print(head);
    printf("\n");
    printf("PrintRev : ");
    printrev(head);
}
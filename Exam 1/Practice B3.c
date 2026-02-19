#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

void insertLast(struct node **head,int data){
    // 3 2 1  -> 3 2 1 
    // Head / 3 2 1 -> 1 2 3
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct node *current = *head;
    while(current -> next != NULL) current = current -> next;
    current ->next = newNode;
    newNode ->prev = current;
}

int Finddiff(struct node *head){
    struct node *current = head;
    if(current -> prev == NULL || current -> next == NULL) return 0  ;
    int before = current -> prev -> data;
    int after =  current -> next -> data;
    int diff = abs(before - after);
    return diff;
}

void PrintList(struct node *head){
    struct node* current = head;
    // currnt != NULL;
    while(current != NULL){ 
        // if(current -> prev == NULL || current ->data < current -> prev -> data)
        // {
        //     printf("%d",current->data);
        // }
        // printf("%d",current ->data);
        printf("%d",Finddiff(current));
        current = current->next;
    }
}

// prev => NULL x x
// next => x x NULL



int main(){
    int i , n ,data;
    struct node *head = NULL;
    scanf("%d",&n);
    for(i = 0 ; i < n ; i++){
        scanf("%d",&data);
        insertLast(&head,data);
    }
    PrintList(head);
}
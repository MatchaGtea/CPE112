#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insertHead(struct node **head,int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(*head == NULL){
        *head = newNode;
    }
    newNode ->data = data;
    newNode ->next = *head;
    *head = newNode;
}

void insertLast(struct node **head , int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode ->data = data;
    newNode ->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }else{
    struct node* current = *head;
    while(current->next != NULL) current = current->next;
    current -> next = newNode;
    }
}

void printList(struct node **head){
    struct node *current = *head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current ->next;
    }
}

int findNth(struct node *head, int index){
    //struct node* current = *head;
    if(head == NULL) return 99;
    if(index == 0){
        return head -> data;
    }
    else return findNth(head->next,index-1);
}

int main(){
    int i , n ,index;
    struct node* head =NULL;
    scanf("%d %d",&n,&index);
    for(i = 1 ; i < n ; i ++){
        insertLast(&head,i);
    }
    insertHead(&head,n);
    printList(&head);
    printf("\n%d",findNth(head,index));
}
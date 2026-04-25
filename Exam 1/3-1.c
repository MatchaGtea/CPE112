#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prv;
};

void insertHead(struct node **head, int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prv  = NULL;
    if(*head == NULL){
        *head = newNode;
        return ;
    }
    newNode -> next = *head;
    (*head)->prv = newNode;
    *head = newNode;
}


void PrintList(struct node *head){
    struct node *current = head;
    while(current != NULL){
        printf("%d ",current->data);
        current = current -> next;
    }
    printf("\n");
}

int palindrome(struct node* head){
    if(head == NULL) return 1;
    
    struct node *tail = head;
    while(tail->next != NULL) tail = tail->next;  // หา tail
    
    struct node *next = head;
    struct node *prv = tail;
    
    while(next != NULL && prv != NULL){
        if(next->data != prv->data) return 0;
        if(next == prv || next->next == prv) break;
        next = next->next;
        prv = prv->prv;
    }
    return 1;
}

int main(){
    struct node *head = NULL;
    int i , n ,  data;
    scanf("%d",&n);
    for(i = 0 ; i<n ; i++){
        scanf("%d",&data);
        insertHead(&head,data);
    }
    if(palindrome(head) == 1){
        printf("Palindrome");
    }else printf("NOT");

    
}
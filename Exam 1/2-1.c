#include <stdio.h>
#include <stdlib.h>

struct node { 
    int data;
    struct node* next;
};

void printList(struct node *head){
    struct node *print = head;
    while(print != NULL){
        printf("%d ", print->data);
        print = print->next;
    }
    printf("\n");
}

void insertHead(struct node **head , int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> next = *head;
    //
    newNode -> data = data;
    *head = newNode;
}

void insertEnd(struct node **head, int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> next = NULL;
    newNode -> data = data;
    
    if(*head == NULL) {
        *head = newNode;
    }
    else{
        struct node *current = *head;
        while(current->next != NULL) current = current -> next;
        current -> next = newNode;
    }
}

int findNth(struct node * head , int index){
    if(head == NULL){
        return 0 ;
    }else if(index == 0){
        return head->data;
    }return findNth((head->next),index-1);
}

int main(){
    struct node *head = NULL;
    int i , n , index;
    scanf("%d %d",&n,&index);
    //
    for(i = 1 ; i < n ; i++) insertEnd(&head,i);
    //
    insertHead(&head,n);
    printList(head);
    printf("\n%d",findNth(head,index));
}
#include <stdio.h>
#include <stdlib.h>

struct node { 
    int data;
    struct node* next;
};

void printList(struct node *head){
    struct node *print = head;
    do {
        printf("%d ", print->data);
        print = print->next;
    } while(print != head);  // ✓ ถูก
    printf("\n");
}

void insertHead(struct node **head , int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    
    if(*head == NULL) {
        newNode -> next = newNode;
        *head = newNode;
    } else {
        struct node *current = *head;
        do{
            current = current->next;
        }while(current -> next != *head);
        newNode -> next = *head;
        current -> next = newNode;
        *head = newNode;
    }
}

void insertEnd(struct node **head, int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = data;
    
    if(*head == NULL) {
        *head = newNode;
        newNode -> next = newNode;
    }
    else{
        struct node *current = *head;
        while(current->next != *head) current = current -> next;
        newNode -> next = *head;
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
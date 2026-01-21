#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void printList(struct node* head){

    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insertHead(struct node **head, int data){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->next = *head;
    newNode->data = data;
    *head = newNode;

}

void insertEnd(struct node **head, int data){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }else{
        struct node *current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

int findNth(struct node *head, int index){
    if(head == NULL){
        return -1;}
    if(index == 0){
        return head->data;
    }else{
        return findNth(head->next, index - 1);
    }
}


int main(){
    struct node *head = NULL;
    int i,n;
    scanf("%d",&n);
    //
    int index;
    scanf("%d",&index);
    for(i = 1; i<n ; i++){
        insertEnd(&head,i);
    }
    
    insertHead(&head,n);
    //
    printf("%d",findNth(head,index));
    //printList(head);
}
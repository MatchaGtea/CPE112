#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void printListCir(struct node* head){

    struct node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

void insertHeadCir(struct node **head, int data){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    struct node *last = *head;
    while (last->next != *head) {
        last = last->next;
    }

    newNode->next = *head;
    last->next = newNode;
    *head = newNode;
}

void insertEndCir(struct node **head, int data){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;

    if(*head == NULL){
        *head = newNode;
        newNode->next = *head;
        return;
    }else{
        struct node *current = *head;
        while(current->next != *head){
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;

    }
}



int main(){
    struct node *head = NULL;
    int i,n;
    scanf("%d",&n);
    //

    for(i = 1; i<n ; i++){
        insertEndCir(&head,i);
    }
    
    insertHeadCir(&head,n);

    //
    printListCir(head);
}
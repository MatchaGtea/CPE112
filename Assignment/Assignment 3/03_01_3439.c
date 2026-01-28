#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void insertHead(struct node **head, int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    if(*head == NULL){
        *head = newNode;
        return ;
    }
    newNode -> next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertEnd(struct node **head, int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(*head == NULL){
        *head = newNode;
    }else{
        struct node *ptr = *head;
        while(ptr->next != NULL) ptr = ptr->next;
        ptr->next = newNode;
        newNode->prev = ptr;
    }
}

void printList(struct node* head){
    if (head == NULL) return;

    struct node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

void printListReverse(struct node*head){
    if (head ==NULL) return;

    struct node* current = head;
    while(current->next != NULL) current = current->next;
    do{
        printf("%d ", current -> data);
        current = current->prev;
    }while(current != NULL);

    printf("\n");
}

int main(){
    int num;
    struct node *head = NULL;

    printf("Input to insertHead: ");
    scanf("%d",&num);
    insertEnd(&head,num);
    for(int i = 1 ; i < num ; i++){
        insertEnd(&head, i);
    }

    // Optional: แสดงผลลัพธ์
    printf("Output: ");
    printListReverse(head);
    printf("\n");

    return 0;
}
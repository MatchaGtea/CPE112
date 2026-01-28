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

int palindrome(struct node* head){
    if (head == NULL) return 0;
    struct node* current = head;
    struct node* last = head;
    while(last->next != NULL) last = last->next;
    while( current-> next != NULL){
        if(last -> data == current -> data){
            last = last -> prev;
            current = current -> next;
        }
        else return 0;
    }
    return 1;
}

int main(){
    struct node* head = NULL;
    int i , n , data;
    printf("Input: ");
    scanf("%d",&n);
    for(i = 0 ; i< n ; i++){
        scanf("%d",&data);
        insertEnd(&head,data);
    }
    int temp = palindrome(head);
    printf("Output: %d\n",temp);
    
}
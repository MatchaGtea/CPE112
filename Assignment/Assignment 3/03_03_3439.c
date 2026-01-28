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
    if(*head == NULL){
        newNode->next = newNode;
        newNode ->prev = newNode;
        *head = newNode;
        return ;
    }
    struct node *last = (*head)->prev;
    newNode->next = *head;
    newNode->prev = last;
    last->next = newNode;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertEnd(struct node **head, int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = newNode -> prev = NULL;
    if(*head == NULL){
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }else{
        struct node *last = (*head)->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = *head;
        (*head)->prev = newNode;
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

void sumFind(struct node * head, int sum){
    if(head == NULL){
        return ;
    }
    struct node *ptr = head;
   int result = 0;

    //printf("\nbefore while\n");

   do{
    int before = ptr->prev->data;
    int after = ptr->next->data;
    result = before + after;
    if(result == sum) printf("( %d , %d ) ",before,after);
    ptr = ptr->next;
   }while(ptr != head);

}

int main(){
    struct node* head = NULL;
    int i , n , data,sum;
    printf("Input: ");
    scanf("%d",&n);
    for(i = 0 ; i< n ; i++){
        scanf("%d",&data);
        insertEnd(&head,data);
    }
    scanf("%d",&sum);
    sumFind(head,sum);
    
}
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void printListCir(struct node* head){
    if (head == NULL) return;

    struct node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}


void insertHeadCir(struct node **head, int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
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


void insertAtN(struct node **head, int data, int index){
    if(index == 0 ){
        insertHeadCir(head,data);
    }else{
        struct node *current = *head;
        int i;
        for(i = 0 ; i < index -1 ; i++){
            current = current->next;
        }
        struct node *newNode = malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteAtN(struct node** head, int index){
    if(*head == NULL){
        return;
    }
    if(index == 0){
        struct node *temp = *head;
        struct node *last = *head;
        while(last->next != *head){
            last = last->next;
        }
        last->next = temp->next;
        *head = temp->next;
        free(temp);
    }else{
        struct node *current = *head;
        int i;
        for(i = 0 ; i < index -1 ; i++){
            current = current->next;
        }
        struct node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

int main(){
    struct node *head = NULL;
    int i,n;
    int data, pos, index;
    scanf("%d %d %d %d",&n,&pos,&data,&index);

    //

    for(i = 1; i<n ; i++){
        insertEndCir(&head,i);
    }
    
    insertHeadCir(&head,n);

    //

    insertAtN(&head, data , pos);

    deleteAtN(&head, index);

    printListCir(head);
}
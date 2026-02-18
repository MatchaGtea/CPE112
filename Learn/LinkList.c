#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* CreateNode(int data, struct Node *next){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return NULL;
    newNode -> data = data;
    newNode -> next = next;
    return newNode;
}

struct Node* InsertHead(int data,struct Node *head){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return NULL;
    newNode -> data = data;
    newNode -> next = head;
    return newNode;
}

struct Node* InsertLast(int data,struct Node *head){
    struct Node *newNode = CreateNode(50,NULL);

    if (head == NULL)   return newNode;

    struct Node *last = head;
    while (last->next != NULL){
        last = last->next;
    }

    last -> next = newNode;

    return head;
}



int main(){
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    struct Node *insert = NULL;

    // head = (struct Node *)malloc(sizeof(struct Node));
    // second = (struct Node *)malloc(sizeof(struct Node));
    // third = (struct Node *)malloc(sizeof(struct Node));
    // insert = (struct Node*)malloc(sizeof(struct Node));


    // if(!head || !second || !third) return 1;

    // head -> data = 10;
    // head -> next = second;

    // second -> data = 20;
    // second -> next = third;

    // insert ->data = 25;
    // insert -> next = third;
    // second -> next = insert;

    // third -> data = 30;
    // third -> next = NULL;

    third = CreateNode(30,NULL);
    second = CreateNode(20,third);
    head = CreateNode(10,second);

    //Insert Head
    head = InsertHead(5,head);
    head = InsertLast(50,head);

    remove(20,head);

    
    

    struct Node *temp = head;
    while (temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    temp = head;
    while(temp != NULL){
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}


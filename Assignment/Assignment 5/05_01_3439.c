#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MSG_LEN 64

typedef struct node{
    char msg[MSG_LEN];
    struct node *next;
}Node;

Node *front = NULL, *rear = NULL;

void enqueue(char *s);
int dequeue(char * out);
int peek(char* out);

void solve(int n); // TODO

int main(void){
    int n;
    printf("Input : ");
    scanf("%d",&n);
    solve(n);
    return 0;
}

void solve(int n){
    char temp[MSG_LEN];
    for(int i = 0 ; i < n ; i++){
        scanf("%s",temp);
        enqueue(temp);
    }
    printf("Output :");
    for(int i = 0 ; i < n ;i++){
        dequeue(temp);
        printf(" %s",temp);
    }
}

void enqueue(char *s){
    Node *new = (Node *) malloc(sizeof(Node));
    if(!new) return;
    strcpy(new->msg,s);
    new->next = NULL;
    if(rear) rear->next = new;
    else front = new;
    rear = new;
    //printf("Enqueued %s into the queue\n",s);
}

int dequeue(char *out){
    Node* tmp;
    //char val[MSG_LEN];
    if(!front) return 0;
    tmp = front ;
    strcpy(out,front->msg);
    front = front -> next ; 
    if(!front ) rear = NULL;
    free(tmp);
    return 1;
}

int peek(char *out){
    if(!front)return 0;
    strcpy(out,front->msg);
    return 1;
}
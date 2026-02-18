#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

Node *front = NULL , *rear = NULL;

void enqueue(int x);
int dequeue(void);
int peek(void);

int main(void){
    int n , i , val;
    scanf("%d",&n);

    for(i = 1 ; i<=n ; i++){
        enqueue(i);
    }

    printf("Front Element: %d\n", peek());

    for( i = 0 ; i <= n ; i++){
        val = dequeue();
        if(val == -1){
            printf("Queue underflow\n-1\n");
        }else{
            printf("%d",val);
        }
    }
    return 0;
}

void enqueue(int x){
    Node *new = (Node *) malloc(sizeof(Node));
    if(!new) return;
    new->data = x;
    new->next = NULL;
    if(rear) rear->next = new;
    else front = new;
    rear = new;
    printf("Enqueued %d into the queue\n",x);
}

int dequeue(void){
    Node* tmp;
    int val;
    if(!front) return -1;
    tmp = front ;
    val = front ->data;
    front = front -> next ; 
    if(!front ) rear = NULL;
    free(tmp);
    return val;
}

int peek(void){
    if(!front)return -1;
    return front ->data;
}
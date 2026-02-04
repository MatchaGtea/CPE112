#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 20

struct stack { 
    char arr[MAX];
    int top;
};

void initialize(struct stack* stk){
    stk->top = -1;
}

void push(struct stack* stk, char value){
    if(stk->top >= MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    stk->arr[++stk->top] = value;
    //printf("Pushed %c onto the stack\n", value);
}

char pop(struct stack* stk){
    if(stk->top == -1){
        printf("Stack Underflow\n");
        return -1;
    }
    char popped = stk->arr[stk->top];
    stk->top--;
    return popped;
}

char peek(struct stack* stk){
    if(stk->top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    return stk->arr[stk->top];
}

void reverse(char* str , int len)
{
    struct stack stk;
    initialize(&stk);
    for(int i = 0 ; i < len ; i++){
        push(&stk, str[i]);
    }   
    for(int i = 0 ; i<len ; i++){
        str[i] = pop(&stk);
    }
}

int main(){
    // struct stack stk;
    // int i,n;
    // initialize(&stk);
    // scanf("%d",&n);
    // for(i = 0;i < n;i++){
    //     push(&stk, i+1);
    // }
    // printf("Top element: %d\n", peek(&stk));
    // for(i = 0;i < n+1;i++){
    //     printf("%d ",pop(&stk));
    // }

    char rever[MAX];
    int i,n;
    scanf("%s",rever);
    int len = strlen(rever);

    reverse(rever,len);
    printf("%s\n", rever);
}
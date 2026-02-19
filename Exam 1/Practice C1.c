#include <stdio.h>
#include <stdbool.h>
#define MAX 20

struct stack{
    char arr[MAX];
    int top;
};

void initialize(struct stack* stk){
    stk ->top = -1;
}

void push(struct stack* stk,char value){
    if(stk->top >= MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    stk->arr[++stk->top] = value; // main
    printf("Pushed %d onto the stack\n", value);
}

char pop(struct stack* stk){
    if(stk->top == -1){
        printf("Stack Underflow\n");
        return -1;
    }
    char popped = stk ->arr[stk->top]; // main
    stk->top--;
    return popped;
}

char peek(struct stack* stk){
    if(stk->top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    return stk->arr[stk->top]; // main
}

int main(){
    struct stack stk;
    int i,n;
    initialize(&stk);
    scanf("%d",&n);
    for(i = 0 ; i< n ; i++){
        push(&stk , i+1);
    }
    printf("Top element: %d\n", peek(&stk));
    for(i=0 ; i <n ; i++){
        printf("%d ",pop(&stk));
    }
}

#include <stdio.h>
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
    //printf("Pushed %d onto the stack\n", value);
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

int findFibonacci(int n){
    int fibo[2] = {0,1};
    int temp;
    if( n == 0 ) return -1;
    if( n == 1 ) return 0;
    if( n == 2 ) return 1;
    for( int i = 2 ; i < n ; i++){
        temp = fibo[0] + fibo[1];
        if(i%2 == 0) fibo[0] = temp;
        else fibo[1] = temp;
    }
    return temp;
}

void fibonaci(struct stack* stk,int fibo){
    int i;
    for(i = 1 ; i <= fibo ;i++){
        push(stk,findFibonacci(i));
    }
}

int main(){
    int i , n ;
    struct stack stk;
    initialize(&stk);
    scanf("%d",&n);
    fibonaci(&stk,n);
    for(i = 0;i < n;i++){
         printf("%d ",pop(&stk));
    }
    // printf("%d",findFibonacci(n));
}
#include <stdio.h>
#include <string.h>
#define MAX 20
//stack : pop push peek ini

struct Stack
{
    char arr[MAX];
    int top;
};

void initilize(struct Stack* stk){
    stk->top = -1;
}

char pop(struct Stack* stk){
    if(stk->top < 0){
        printf("stack underflow");
        return -1;
    }
    // --stk->top;
    return stk->arr[stk->top--];
}

void push(struct Stack* stk,char temp){
    if(stk->top >= MAX){
        printf("stack overflow");
        return;
    }
    printf("test push = %c\n",temp);
    stk->arr[++stk->top] = temp;
}

char peek(struct Stack* stk){
    if(stk->top < 0){
        printf("Stack is empty.");
        return -1;
    }
    return stk->arr[stk->top];
}

int main(){
    int i , n;
    char data = ' ';
    struct Stack stk;
    initilize(&stk);
    scanf("%d",&n);
    for(i = 0 ; i < n ; i++){
        scanf(" %c", &data);
        push(&stk,data);
    }
    for(i = 0 ; i < n ; i++){
        printf("%c ",pop(&stk));
    }
}


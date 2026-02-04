#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
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

int precendence(char x){
    if(x == '(') return 0;
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    return 0;
}

void infixToPostfix(char exp[]){
    int i,n,pos,popped;
    struct stack stk;
    initialize(&stk);


    pos = 0;
    while(exp[pos] != '\0'){
        if(isalnum(exp[pos])) printf("%c",exp[pos]);
        else if(exp[pos] == '('){
            push(&stk,exp[pos]);
        }
        else if(exp[pos] == ')'){
            char temp = pop(&stk);
            while(temp != '('){
                printf("%c",temp);
                temp = pop(&stk);
            }
        }else{
            while (precendence((stk.arr[stk.top]))>= precendence(exp[pos])){
                printf("%c", pop(&stk));
        }
        push(&stk,exp[pos]);
    }
        pos++;
    }
    while(stk.top != -1){
        popped = pop(&stk);
        printf("%c", popped);
    }
}


int main(){
    char exp[MAX];
    scanf("%s",exp);
    infixToPostfix(exp);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

#define TABLE_SIZE 13

int Caugh = -1;

long long Hash[TABLE_SIZE];

void initHash(){
    for(int i = 0 ; i < MAX ; i++){
        Hash[i] = -1;
    }
}

void insertHash(long long int key){
    int index = key % TABLE_SIZE;
    while(Hash[index] != -1){
        if(Caugh == -1) Caugh = key;
        index = (index+1) % TABLE_SIZE;
    }
    Hash[index] = key;
}

void printHash(){
    int n = sizeof(Hash) / sizeof(Hash[0]);
    for(int i = 0 ; i<  n ;i++){
        printf("index %d : %lld\n" , i , Hash[i]);
    }
}

void solve(void){
    initHash();
    int time;
    scanf("%d",&time);
    for(int i = 0 ; i < time ;i++){
        int data;
        scanf("%d",&data);
        insertHash(data);
    }
    if(Caugh != -1){
        printf("Caugh monkey Index : %d",Caugh);
    }else printf("-1");
}

int main(){
    solve();
    return 0;
}
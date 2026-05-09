#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 15

long long Hash[TABLE_SIZE];

void initTable(void){
    for(int i = 0 ; i < TABLE_SIZE ;i++){
        Hash[i] = -1;
    }
}

void insertHash(long long data){
    int index = data % TABLE_SIZE;
    while(Hash[index] != -1){
        index = (index +1) % TABLE_SIZE;
    }
    Hash[index] = data;
}

void PrintTable(void){
    int n = sizeof(Hash) / sizeof(Hash[0]);
    for(int i = 0 ; i < n ; i++){
        printf("index %d : %lld\n",i,Hash[i]);
    }
}

int main(){
    initTable();
    long long data[] = { 1 ,2 ,3 , 5};
    int n = sizeof(data) / sizeof(data[0]);
    for(int i = 0 ; i<n ;i++){
        insertHash(data[i]);
    }
    printf("Before ");
    PrintTable();
    return 0;
}
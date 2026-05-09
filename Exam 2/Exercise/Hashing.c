#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Table_size 13

long long hashtable[Table_size];

void initTable(void){
    for(int i = 0 ; i < Table_size ; i++){
        hashtable[i] = -1;
    }
}

void insertHash(long long key){
    int index = key % Table_size;
    while(hashtable[index] != -1){
        index = (index +1) % Table_size;
    }
    hashtable[index] = key;
}

void printTable(void){
    int n = sizeof(hashtable) / sizeof(hashtable[0]);
    for(int i = 0 ; i< n ;i++){
        printf("Index %d : %lld\n",i , hashtable[i]);
    }
}

void solve(void){
    long long data[] = {68070503480, 68070503468, 68070503493, 68070503410};
    initTable();
    int n = sizeof(data)/sizeof(data[0]);
    for(int i = 0 ; i < n ;i++){
        insertHash(data[i]);
    }
    printTable();
}

int main(){
    solve();
    return 0;
}
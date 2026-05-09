#include <stdio.h>
#include <stdlib.h>

#define Table_size 13

long long Hashing[Table_size];

void initTable(){
    for(int i = 0 ; i < Table_size ; i++){
        Hashing[i] = -1;
    }
}

void insertHash(long long key){
    int index = key % Table_size;
    while(Hashing[index] != -1){
        index = (index+1) % Table_size;
    }
    Hashing[index] = key;
}

void PrintHash(){
    int n = sizeof(Hashing) / sizeof(Hashing[0]);
    for(int i = 0 ; i < n ; i++){
        printf("Index %d : %lld\n",i , Hashing[i]);
    }
}

void solve(){
    long long data[] = {1 ,3 ,8 ,9};
    initTable();
    int n = sizeof(data) / sizeof(data[0]);
    for(int i = 0 ; i< n ;i++){
        insertHash(data[i]);
    }
    PrintHash();
}

int main(){
    solve();
    return 0;
}
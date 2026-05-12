#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

void PrintList(int arr[]){
    int n = MAX;
    printf("Print :");
    for(int i = 0 ; i < n ; i++){
        printf(" %d",arr[i]);
    }
}
//สลับติดกัน
void Bubble_Sort(int arr[]){
    int n = MAX;
    for(int i = 0 ; i < n-1 ;i++){
        for(int j = 0 ; j < n - i -1 ;j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j],&arr[j+i]);
            }
        }
    }
}
//
void Insertiong_sort(int arr[]){
    int n = MAX;
    for(int i= 1 ; i< n ; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        
    }
}

void Selection_Sort(int arr[]){
    int n=MAX;
    for(int i = 0 ;i < n-1 ; i++){
        int min = arr[i];
        for(int j = i+1; j < n ;j++){
            if(arr[min] > arr[j]) min = j;
        }
        swap(&arr[i],&arr[min]);
    }
}

int main(){
    int arr[MAX] = {10 ,5 ,6 ,4 ,3 ,2 ,7, 8 ,9 ,1};
    Bubble_Sort(arr);
    PrintList(arr);
}
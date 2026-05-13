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
    printf("\n");
}
//สลับติดกัน

void swap(int *a ,int *b);

void Bubble_sort(int arr[]){
    int n = MAX;
    for(int i = 0 ; i< n-1 ;i++){
        for(int j = 0 ; j < n-i-1; j++){
            if(arr[j+1] <= arr[j]) swap(&arr[j+1],&arr[j]);
        }
    }
}

void Insertion_sort(int arr[]){
    int n = MAX;
    for(int i = 1 ; i < n ; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void Selection_sort(int arr[]){
    int n = MAX;
    for(int i = 0 ; i< n-1 ; i++){
        int min = i;
        for(int j = i+1 ; j< n ;j++){
            if(arr[j] < arr[min]) min = j;
        }
        swap(&arr[i] , &arr[min]);
    }
}

void swap(int *a ,int *b ){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int arr[MAX] = {10 ,5 ,6 ,4 ,3 ,2 ,7, 8 ,9 ,1};
    // Bubble_sort(arr);
    // printf("Bubbule Sort ");

    // Insertion_sort(arr);
    // printf("Insertion_sort ");

    Selection_sort(arr);
    printf("Selection ");

    PrintList(arr);
}
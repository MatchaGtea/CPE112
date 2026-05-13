#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void PrintList(int arr[]){
    int n = MAX;
    printf("arr :");
    for(int i = 0 ; i<n ;i++){
        printf(" %d",arr[i]);
    }
    printf("\n");
}

void merge(int arr[] , int l , int m , int r){
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1] , R[n2];

    i = 0;
    while(i < n1){
        L[i] = arr[l+i];
        i++;
    }
    j = 0;
    while(j < n2){
        R[j] = arr[m+j+1];
        j++;
    }

    i = 0 ; j = 0 ; k=l;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++; k++;
        }else{
            arr[k] = R[j];
            j++; k++;
        }
    }
    while(i < n1){
        arr[k] = L[i];
        i++; k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int l , int r){
    int m = l+ (r-l)/2;
    if(l<r){
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int arr[MAX] = {10 ,5 ,6 ,4 ,3 ,2 ,7, 8 ,9 ,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr,0,size-1);
    printf("Merge ");
    PrintList(arr);
}
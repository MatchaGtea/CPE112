#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

void PrintList(int arr[]){
    int n = MAX;
    printf("Print :");
    for(int i = 0 ; i < n ; i++){
        printf(" %d", arr[i]);
    }
    printf("\n");
}

void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Bubble_Sort(int arr[]){
    int n = MAX;
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < n-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Insertion_Sort(int arr[]){
    int n = MAX;
    for(int i = 1 ; i < n ; i++){
        int key = arr[i];
        int j = i-1;

        while(j>= 0  && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

// void Selection_Sort(int arr[]){
//     int n = MAX;
//     for(int i = 0 ; i < n ; i++){
//         int min_idx = i;

//         for(int j = i+1 ; j < n ; j++){
//             if(__________ < __________){
//                 min_idx = __________;
//             }
//         }

//         int temp = __________;
//         arr[i] = __________;
//         arr[min_idx] = __________;
//     }
// }

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1], R[n2];

    for(i = 0 ; i < n1 ; i++){
        L[i] = arr[i+l];
    }
    for(j = 0 ; j < n2 ; j++){
        R[j] = [m+1+j];
    }

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr,l, m, r);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j = low ; j < high ; j++){
        if(arr[j] < pivot){
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }

    Swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr,low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    int arr[MAX] = {10, 5, 6, 4, 3, 2, 7, 8, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    /*
        Choose one sorting function after completing the blanks.

        Bubble_Sort(arr);
        Insertion_Sort(arr);
        Selection_Sort(arr);
        mergeSort(arr, 0, size - 1);
        quickSort(arr, 0, size - 1);
    */

    PrintList(arr);
    return 0;
}

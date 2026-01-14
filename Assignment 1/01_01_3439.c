#include <stdio.h>

int largest(int arr[] , int n){
    int large = arr[0];
    int second;
    for(int i = 0 ; i<n ; i++){
        if(large < arr[i]){
            second = large;
            large = arr[i];
        }
        else if(second < arr[i]){
            second = arr[i];
        }
    //printf(" large = %d , Second = %d , n = %d\n",large,second,n);
    }
    return second;
}

int main(){
    int n , arr[10];
    int large , Second;

    scanf("%d",&n);
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }

    Second = largest(arr,n);
    printf("%d",Second);
    return 0;
}
#include <stdio.h>

int strlength(char arr[]){
    int i = 1;
    while(arr[i] != '\0') {
        //printf("%c , %d\n",arr[i] , i);
        i++;
    }
    return i;
}

int main(){
    int n ;
    char arr[10];
    scanf("%s",arr);

    n = strlength(arr);

    printf("%d",n);
}
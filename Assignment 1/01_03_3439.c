#include <stdio.h>
#include <stdlib.h>

void fillptr(int *p,int i ){
    for(int j = 0 ; j < i ; j++){
        *(p+j) = j+1;
    }
}

int main(){
    int i , n;
    scanf("%d",&n);
    int *ptr = malloc(n * sizeof(int));
    if(ptr == NULL){
        //Allocation failure
        return 1;
    }
    fillptr(ptr,n);
    for(i = 0 ; i < n ; i++){
        printf("%d ",ptr[i]);
    }

    free(ptr);
    ptr = NULL;
    return 0;
}
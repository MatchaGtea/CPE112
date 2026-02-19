#include <stdio.h>
#include <stdlib.h>

void fillptr(int *p,int i ){
    for(int j = 0 ; j < i ; j++){
        p[j] = j+1;
    }
}

int main(){
    int i , n = 3;
    scanf("%d",&n);
    //int ptr[3];
    int *ptr = malloc(n * sizeof(int));
    if(ptr == NULL){
        //Allocation failure
        return 1;
    }
    fillptr(ptr,n);

    
    for(i = 0 ; i < n ; i++){
        scanf("%d",&ptr[i]);
    }

    for(i = 0 ; i < n ; i++){
        printf("%p ",&ptr[i]);
    }

    free(ptr);
    ptr = NULL;
    return 0;
}
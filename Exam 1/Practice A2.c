#include <stdio.h>

int main(){
    char arr[20];
    scanf("%s",arr);
    char temp = ' ';
    int count = 0 ,i = 0;
    //aaabbccaaa
    while(arr[i] != '\0'){
        temp = arr[i];
        if(arr[i+1] == temp){
            count++;
            int index = 1;
            while(arr[i + index] == temp){
                index++;
            }
            i = i + index;
            continue;
        }
        i++;
    }
    printf("%d",count);
}
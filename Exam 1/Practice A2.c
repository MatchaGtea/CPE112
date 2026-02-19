#include <stdio.h>
#define Max 100


int main(){
    char str[Max];
    scanf("%s",str);
    int i=0,count=0;
    while(str[i] != '\0'){
        char temp;
        if(temp != str[i]) {
            temp = str[i];
            i++;
            continue;
        }else if(temp == str[i]){
            count++;
            int index = 1;
            while(str[i+index] == temp) index++;
            i = i+index;
        }
    }
    printf("%d",count);
}
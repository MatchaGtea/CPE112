#include <stdio.h>
#include <ctype.h>
#define MAX 20
//Abcd  AABBCC // BBCC

int main(){
    int i = 0,count = 0,temp = 0;
    char str[MAX];
    scanf("%s",str);
    while(str[i] != '\0'){
        str[i] = tolower(str[i]);
        i++;
    }
    i = 0 ;
    while(str[i] != '\0'){
        if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') count++;
        else{
            if(count > temp) temp = count;
            count = 0;
        }
        i++;
    }
    if(count > temp) temp = count;  // Check the last sequence of consonants
    printf("%d",temp);

}

#include <stdio.h>

int isConsonant(char c) {
    // แปลงเป็นพิมพ์เล็กโดยไม่ใช้ tolower
    if (c >= 'A' && c <= 'Z') {
        c = c + ('a' - 'A');
    }

    // เช็กว่าเป็นตัวอักษร
    if (c >= 'a' && c <= 'z') {
        // ถ้าไม่ใช่สระ → เป็นพยัญชนะ
        if (c!='a' && c!='e' && c!='i' && c!='o' && c!='u')
            return 1;
    }
    return 0;
}

int longestConsonantSubstring(char str[]) {
    int maxLen = 0;
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (isConsonant(str[i])) {
            count++;
            if (count > maxLen)
                maxLen = count;
        } else {
            count = 0;
        }
        i++;
    }

    return maxLen;
}

int main() {
    char str[100];
    scanf("%s", str);

    printf("%d\n", longestConsonantSubstring(str));
    return 0;
}

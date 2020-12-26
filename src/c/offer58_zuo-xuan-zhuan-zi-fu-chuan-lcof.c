#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseLeftWords(char* s, int n)
{
    if (!s) {
        return s;
    }

    int len = strlen(s);
    if (n >= len) {
        return s;
    }
    int c = n % len;
    char* tmp = malloc(c + 1);
    tmp[c] = '\0';
    strncpy(tmp, s, c);
    int i = 0;
    for (; i < len - c; i++) {
        s[i] = s[i + c];
    }

    int m = 0;
    for (; i < len; i++) {
        s[i] = tmp[m++];
    }
    free(tmp);
    return s;
}

int main()
{
    char* origin = malloc(10);
    strncpy(origin, "abcdefgij", 9);
    origin[9] = '\0';
    char* str = reverseLeftWords(origin, 2);
    printf("str is %s\n", origin);
    free(origin);
    return 0;
}
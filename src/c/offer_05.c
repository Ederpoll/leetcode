#include <stdio.h>
#include <string.h>
char* replaceSpace(char* s)
{
    int len = strlen(s);
    char* str = malloc(3 * len + 1);
    str[3 * len] = '\0';
    int n = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            str[n] = '%';
            str[n + 1] = '2';
            str[n + 2] = '0';
            n = n + 3;
            continue;
        }
        str[n++] = s[i];
    }

    str[n] = '\0';
    return str;
}
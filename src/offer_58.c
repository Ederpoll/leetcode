#include <stdio.h>
#include <string.h>
char* reverseWords(char* s)
{
    int len = strlen(s);
    if (len == 0)
        return "";
    int i = 0;
    while (*(s + i) == ' ') {
        i++;
    }

    if (i == len)
        return "";
    int left = len - 1;
    int right = len - 1;
    char* ans = malloc(len);
    int size = 0;
    while (right > i - 1) {
        while (right >= 0 && *(s + right) == ' ') {
            right--;
        }
        left = right;
        while (left >= 0 && *(s + left) != ' ') {
            left--;
        }
        //printf("%d, %d\n", left, right);
        for (int j = left + 1; j <= right; j++) {
            ans[size++] = *(s + j);
        }
        ans[size++] = ' ';
        right = left;
    }

    ans[size - 1] = '\0';
    return ans;
}
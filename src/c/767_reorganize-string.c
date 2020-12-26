#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* reorganizeString(char* S)
{
    int len = strlen(S);
    int symbol[26] = { 0 };
    for (int i = 0; i < len; i++) {
        symbol[*(S + i) - 'a'] += 1;
    }

    for (int i = 0; i < 26; i++) {
        if (symbol[i] > (len + 1) / 2) {
            return "";
        }
    }

    char* ans = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        ans[i] = ' ';
    }
    ans[len] = '\0';
    int even = 0;
    int odd = 1;
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        while (symbol[i] > 0 && symbol[i] <= len / 2 && odd < len) {
            ans[odd] = c;
            symbol[i]--;
            odd += 2;
        }

        while (symbol[i] > 0) {
            ans[even] = c;
            symbol[i]--;
            even += 2;
        }
    }

    return ans;
}

int main()
{
    char* str = reorganizeString("aab");
    printf("str:%s\n", str);
    return 0;
}
#include <string.h>
#include <stdio.h>
#define MAX(A, B) (A > B ? A : B)
int lengthOfLongestSubstring(char *s)
{
    int length = 0;
    int ret = 0;
    int hashmap[256] = {0};
    char *cur = s;
    while (*cur)
    {
        if (hashmap[*cur] != 0)
        {
            while (hashmap[*cur])
            {
                hashmap[*(cur - length)] -= 1;
                length--;
            }
        }

        hashmap[*cur] = 1;
        length++;
        ret = MAX(ret, length);
        cur++;
    }

    return ret;
}
#include <stdio.h>
#include <string.h>

int main()
{
    char *s1 = "10";
    char *s2 = "1";
    int ret = strcmp(s1, s2);
    printf("cmp ret: %d\n", ret);
    return 0;
}
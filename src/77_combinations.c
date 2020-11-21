#include <stdio.h>
#include <stdlib.h>
long long getCnt(int n, int k)
{
    long long ans = 1;
    for (int i = k + 1; i <= n; i++) {
        ans *= i;
    }

    for (int i = 1; i <= n - k; i++) {
        ans = ans / i;
    }

    return ans;
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
{
    int cnt = getCnt(n, k);
    int** result = (int**)malloc(sizeof(int*) * cnt);
    int* tmp = (int*)malloc(sizeof(int) * k);

    return NULL;
}

int main()
{
    int cnt = getCnt(25, 12);
    printf("%d\n", cnt);
    return 0;
}
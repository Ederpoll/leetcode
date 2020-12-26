#include <stdbool.h>
#include <stdio.h>
bool recur(int* postorder, int i, int j)
{
    if (i >= j)
        return true;
    int p = i;
    while (postorder[p] < postorder[j])
        p++;
    int m = p;
    while (postorder[p] > postorder[j])
        p++;
    return p == j && recur(postorder, i, m - 1) && recur(postorder, m, j - 1);
}

bool verifyPostorder(int* postorder, int postorderSize)
{
    return recur(postorder, 0, postorderSize - 1);
}
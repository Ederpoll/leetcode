#include <stdio.h>
#include <stdlib.h>

int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes)
{
    if (target < 3) {
        *returnSize = 0;
        return NULL;
    }

    int** result = malloc(sizeof(int*) * target);
    *returnColumnSizes = malloc(sizeof(int) * target);
    *returnSize = 0;
    int left = 1;
    int right = 1;
    int len = target / 2;
    int sum = 0;
    while (left <= len) {
        if (sum == target) {
            result[*returnSize] = malloc(sizeof(int) * (right - left));
            (*returnColumnSizes)[*returnSize] = right - left;
            for (int i = left; i < right; i++) {
                result[*returnSize][i - left] = i;
            }
            (*returnSize)++;
            sum -= left;
            left++;
        } else if (sum < target) {
            sum += right;
            right++;
        } else {
            sum -= left;
            left++;
        }
    }

    return result;
}
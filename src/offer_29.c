#include <stdio.h>
#include <stdlib.h>
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    if (matrixSize == 0 || *matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int size = matrixSize * (*matrixColSize);
    int* ret = malloc(sizeof(int) * size);
    *returnSize = 0;
    int left = 0, right = *matrixColSize - 1;
    int top = 0, bot = matrixSize - 1;
    while (*returnSize < size) {
        for (int i = left; *returnSize < size && i <= right; i++) {
            ret[(*returnSize)++] = matrix[top][i];
        }
        top++;

        for (int i = top; *returnSize < size && i <= bot; i++) {
            ret[(*returnSize)++] = matrix[i][right];
        }
        right--;

        for (int i = right; *returnSize < size && i >= left; i--) {
            ret[(*returnSize)++] = matrix[bot][i];
        }
        bot--;

        for (int i = bot; *returnSize < size && i >= top; i--) {
            ret[(*returnSize)++] = matrix[i][left];
        }
        left++;
    }

    return ret;
}

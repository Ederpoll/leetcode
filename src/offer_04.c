#include <stdbool.h>
#include <stdio.h>

bool findTarget(int* arr, int arrSize, int target)
{
    int i = 0;
    int j = arrSize - 1;
    while (i <= j) {
        int mid = i + (j - i) / 2;
        if (arr[mid] < target) {
            i = mid + 1;
        } else if (arr[mid] == target) {
            return true;
        } else {
            j = mid - 1;
        }
    }

    return false;
}
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    if (matrix == NULL || matrixSize == 0 || matrixColSize[0] == 0) {
        return false;
    }

    int n = 0;
    while (n < matrixSize && matrix[n][0] <= target) {
        n++;
    }

    for (int i = 0; i < n; i++) {
        if (findTarget(matrix[i], *matrixColSize, target)) {
            return true;
        }
    }

    return false;
}
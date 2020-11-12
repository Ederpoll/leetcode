#include <stdio.h>
#include <stdlib.h>
void bubleSort(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
            }
        }
    }
}

void insertSort(int *nums, int numsSize)
{
    if (numsSize <= 1)
    {
        return;
    }
    for (int i = 1; i < numsSize; i++)
    {
        int value = nums[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (nums[j] > value)
            {
                nums[j + 1] = nums[j];
            }
            else
            {
                break;
            }
        }

        nums[j + 1] = value;
    }
}

void merge(int *nums, int numsSize, int left, int mid, int right)
{
    int *tmp = (int *)malloc(sizeof(int) * numsSize);

    int i = left;
    int j = mid + 1;
    int n = 0;
    while (i <= mid && j <= right)
    {
        if (nums[i] > nums[j])
        {
            tmp[n++] = nums[j++];
        }
        else
        {
            tmp[n++] = nums[i++];
        }
    }

    while (i <= mid)
    {
        tmp[n++] = nums[i++];
    }

    while (j <= right)
    {
        tmp[n++] = nums[j++];
    }

    for (int k = 0; k < numsSize; k++)
    {
        nums[k] = tmp[k];
    }
    free(tmp);
    tmp = NULL;
    return;
}

void mergeSortChild(int *nums, int numsSize, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSortChild(nums, numsSize, left, mid);
    mergeSortChild(nums, numsSize, mid + 1, right);

    merge(nums, numsSize, left, mid, right);
}
void mergeSort(int *nums, int numsSize)
{
    return mergeSortChild(nums, numsSize, 0, numsSize - 1);
}
int main()
{
    int nums[5] = {1, -1, 2, 4, 3};
    //bubleSort(nums, 5);
    //insertSort(nums, 5);
    mergeSort(nums, 5);
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
    {
        printf("%d\n", nums[i]);
    }

    return 0;
}
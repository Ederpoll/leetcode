#include <stdio.h>
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
#if 0
// 这个方法太慢了
int *sortArrayByParityII(int *A, int ASize, int *returnSize)
{
    *returnSize = ASize;
    for (int i = 0; i < ASize; i++)
    {
        if ((i % 2 == 0 && A[i] % 2 == 0) || (i % 2 == 1 && A[i] % 2 == 1))
        {
            continue;
        }
        else if (i % 2 == 0)
        {
            int j = i + 1;
            while (j < ASize)
            {
                if (j % 2 == 1 && A[j] % 2 == 0)
                {
                    swap(A + i, A + j);
                    break;
                }
                j++;
            }
        }
        else
        {
            int j = i + 1;
            while (j < ASize)
            {
                if (j % 2 == 0 && A[j] % 2 == 1)
                {
                    swap(A + i, A + j);
                    break;
                }
                j++;
            }
        }
    }

    return A;
}
#endif

// 双指针法

int *sortArrayByParityII(int *A, int ASize, int *returnSize)
{
    *returnSize = ASize;
    int i = 0;
    int j = 1;
    for (; i < ASize; i += 2)
    {
        if (A[i] % 2)
        {
            while (j < ASize)
            {
                if (A[j] % 2 == 0)
                {
                    swap(A + i, A + j);
                    break;
                }
                j += 2;
            }
        }
    }

    return A;
}
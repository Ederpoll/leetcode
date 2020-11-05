#include <stdio.h>
#define SHIFT 31
typedef struct ans
{
    int val;
    int oneCnt;
} ans;

int cmp(const void *a, const void *b)
{
    ans *_a = (ans *)a;
    ans *_b = (ans *)b;

    if (_a->oneCnt == _b->oneCnt)
    {
        return _a->val - _b->val;
    }

    return _a->oneCnt - _b->oneCnt;
}

int *sortByBits(int *arr, int arrSize, int *returnSize)
{
    *returnSize = 0;
    if (!arr)
    {
        return NULL;
    }

    ans *map = (ans *)malloc(sizeof(ans) * arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        map[i].val = arr[i];
        int cnt = 0;
        for (int j = 0; j < SHIFT; j++)
        {
            if (arr[i] & (1 << j))
            {
                cnt++;
            }
        }
        map[i].oneCnt = cnt;
    }

    qsort(map, arrSize, sizeof(map[0]), cmp);
    int *ret = (int *)malloc(sizeof(int) * arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        ret[(*returnSize)++] = map[i].val;
    }

    free(map);
    return ret;
}

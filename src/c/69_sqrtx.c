#include <stdio.h>
int mySqrt(int x)
{
    if (x == 0) {
        return 0;
    }

    int left = 1;
    int right = x;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int sqrt = x / mid;
        if (mid == sqrt) {
            return mid;
        } else if (mid < sqrt) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
}

int main()
{
    int num = 256777;
    int ans = mySqrt(num);
    printf("%d\n", ans);
    return 0;
}
#include <stdio.h>

// 考察位运算的知识
// a + b = 进位值 + 非进位值
// 0 + 0 = 0 + 0
// 0 + 1 = 0 + 1
// 1 + 0 = 0 + 1
// 1 + 1 = 1 + 0  -->  a & b << 1  + a ^ b
int add(int a, int b)
{
    while (b != 0) {
        int c = (unsigned int)(a & b) << 1;
        a ^= b;
        b = c;
    }
    return a;
}
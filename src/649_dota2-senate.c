#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 贪心算法 ： 前面的选择后面的一个去处理，用队列去处理，每个队列里面记录下再数组中的位置，如果位置在前面
char* predictPartyVictory(char* senate)
{
    int len = strlen(senate);
    int RqueueHead = 0;
    int RqueueTail = 0;
    int DqueueHead = 0;
    int DqueueTail = 0;
    int* Rqueue = malloc(sizeof(int) * len);
    int* Dqueue = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        if (*(senate + i) == 'D') {
            Dqueue[DqueueTail++] = i;
        } else if (*(senate + i) == 'R') {
            Rqueue[RqueueTail++] = i;
        }
    }

    while (RqueueHead < RqueueTail && DqueueHead < DqueueTail) {
        if (Dqueue[DqueueHead] < Rqueue[RqueueHead]) {
            Dqueue[DqueueTail++] = DqueueHead + len;
        } else {
            Rqueue[RqueueTail++] = RqueueHead + len;
        }

        DqueueHead++;
        RqueueHead++;
    }

    return RqueueHead < RqueueTail ? "Radiant" : "Dire";
}

int main()
{
    char* orign = "RRDDD";
    char* res = predictPartyVictory(orign);
    printf("%s\n", res);
    return 0;
}
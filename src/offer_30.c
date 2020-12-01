#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10000
typedef struct {
    int stack[MAX_STACK_SIZE];
    int minIdx;
    int top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate()
{
    MinStack* obj = malloc(sizeof(MinStack));
    obj->top = 0;
    obj->minIdx = 0;
    return obj;
}

void minStackPush(MinStack* obj, int x)
{
    if (x < obj->stack[obj->minIdx]) {
        obj->minIdx = obj->top;
    }
    obj->stack[obj->top++] = x;
}

void minStackPop(MinStack* obj)
{
    if (obj->minIdx == obj->top - 1) {
        int min = obj->stack[0];
        for (int i = 0; i < obj->top - 1; i++) {
            if (obj->stack[i] <= min) {
                min = obj->stack[i];
                obj->minIdx = i;
            }
        }
    }
    obj->top--;
}

int minStackTop(MinStack* obj)
{
    return obj->stack[obj->top - 1];
}

int minStackMin(MinStack* obj)
{
    return obj->stack[obj->minIdx];
}

void minStackFree(MinStack* obj)
{
    free(obj);
}
#include <stdbool.h>
#include <stdio.h>

int g_number = 0;
bool check(int columIndex[], int length)
{
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (i - j == columIndex[i] - columIndex[j] || j - i == columIndex[i] - columIndex[j]) {
                return false;
            }
        }
    }

    return true;
}
void dfs(int columIndex[], int length, int index)
{
    if (index == length) {
        if (check(columIndex, length)) {
            g_number++;
        }
    } else {
        for (int i = index; i < length; i++) {
            int temp = columIndex[i];
            columIndex[i] = columIndex[index];
            columIndex[index] = temp;

            dfs(columIndex, length, index + 1);

            temp = columIndex[index];
            columIndex[index] = columIndex[i];
            columIndex[i] = temp;
        }
    }
}

void eightQueen()
{
    const int queues = 8;
    int columIndex[queues];
    for (int i = 0; i < queues; i++) {
        columIndex[i] = i;
    }

    dfs(columIndex, queues, 0);
}
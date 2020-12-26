#include "../include/uthash.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct hash {
    char* key;
    int value;
    UT_hash_handle hh;
} hash;
hash* globalHash;
int getCnt(int n)
{
    int val = 1;
    for (int i = 1; i <= n; i++) {
        val *= i;
    }
    return val;
}
void dfs(char* s, char** result, int* returnSize, char* tmp, int tmpSize, int* visited)
{
    int len = strlen(s);
    if (tmpSize == len) {
        hash* h = NULL;
        HASH_FIND_STR(globalHash, tmp, h);
        if (!h) {
            h = (hash*)calloc(1, sizeof(hash));
            h->key = (char*)calloc((len + 1), sizeof(char));
            strcpy(h->key, tmp);
            h->value = 1;
            HASH_ADD_STR(globalHash, key, h);
            char* ans = (char*)calloc(len + 1, sizeof(char));
            strcpy(ans, tmp);
            result[(*returnSize)++] = ans;
            return;
        } else {
            return;
        }
    }

    for (int i = 0; i < len; i++) {
        if (visited[i]) {
            continue;
        }

        tmp[tmpSize] = s[i];
        visited[i] = 1;
        dfs(s, result, returnSize, tmp, tmpSize + 1, visited);
        visited[i] = 0;
    }
}

char** permutation(char* s, int* returnSize)
{
    *returnSize = 0;
    if (!s) {
        return NULL;
    }

    int len = strlen(s);
    int size = getCnt(len);
    char** result = (char**)malloc(sizeof(char*) * size);

    char* tmp = (char*)malloc(sizeof(char) * (len + 1));
    memset(tmp, 0, sizeof(char) * (len + 1));
    int* visited = (int*)calloc(len, sizeof(int));
    globalHash = NULL;
    dfs(s, result, returnSize, tmp, 0, visited);
    return result;
}
#include "../include/uthash.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct hash {
    int key;
    int val;
    UT_hash_handle hh;
} hash;
hash* gHash;
int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize)
{
    gHash = NULL;
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < BSize; j++) {
            int key1 = A[i] + B[j];
            hash* tmp = NULL;
            HASH_FIND_INT(gHash, &key1, tmp);
            if (!tmp) {
                tmp = (hash*)malloc(sizeof(hash));
                tmp->key = key1;
                tmp->val = 1;
                HASH_ADD_INT(gHash, key, tmp);
            } else {
                tmp->val++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < CSize; i++) {
        for (int j = 0; j < DSize; j++) {
            int key2 = -C[i] - D[j];
            hash* tmp = NULL;
            HASH_FIND_INT(gHash, &key2, tmp);
            if (tmp) {
                ans += tmp->val;
            }
        }
    }

    return ans;
}
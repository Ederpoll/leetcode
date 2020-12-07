#include "../include/uthash.h"
#include <stdio.h>
typedef struct listNode {
    int key;
    int val;
    struct listNode* next;
    struct listNode* prev;
} listNode;

typedef struct hash {
    int key;
    listNode* value;
    UT_hash_handle hh;
} hashTable;

typedef struct {
    int cap;
    int used;
    hashTable* hashPtr;
    listNode* head;
    listNode* tail;
} LRUCache;

void delNode(listNode* node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
}
void addNode(listNode* prev, listNode* next, listNode* node)
{
    prev->next = node;
    next->prev = node;
    node->prev = prev;
    node->next = next;
}

void addHead(listNode* head, listNode* node)
{
    addNode(head, head->next, node);
}

listNode* delTail(listNode* tail)
{
    listNode* node = tail->prev;
    delNode(node);
    return node;
}

LRUCache* lRUCacheCreate(int capacity)
{
    LRUCache* obj = malloc(sizeof(LRUCache));
    obj->cap = capacity;
    obj->used = 0;
    obj->hashPtr = NULL;
    obj->head = malloc(sizeof(listNode));
    obj->tail = malloc(sizeof(listNode));
    obj->head->next = obj->tail;
    obj->head->prev = NULL;
    obj->tail->prev = obj->head;
    obj->tail->next = NULL;
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key)
{
    hashTable* tmp = NULL;
    HASH_FIND_INT(obj->hashPtr, &key, tmp);
    if (!tmp) {
        return -1;
    } else {
        listNode* ptr = tmp->value;
        delNode(ptr);
        addHead(obj->head, ptr);
        return ptr->val;
    }
}

void lRUCachePut(LRUCache* obj, int key, int value)
{
    hashTable* tmp = NULL;
    HASH_FIND_INT(obj->hashPtr, &key, tmp);
    if (tmp == NULL) {
        if (obj->used >= obj->cap) {
            listNode* tail = delTail(obj->tail);
            int key1 = tail->key;
            hashTable* temp = NULL;
            HASH_FIND_INT(obj->hashPtr, &key1, temp);
            if (!temp) {
                printf("bug: key1\n", key1);
            } else {
                temp->key = key;
                tail->key = key;
                tail->val = value;
                addHead(obj->head, tail);
            }
        } else {
            tmp = malloc(sizeof(hashTable));
            listNode* node = malloc(sizeof(listNode));
            node->key = key;
            node->val = value;
            addHead(obj->head, node);
            tmp->key = key;
            tmp->value = node;
            HASH_ADD_INT(obj->hashPtr, key, tmp);
            obj->used++;
        }
    } else {
        listNode* node = tmp->value;
        node->key = key;
        node->val = value;
        delNode(node);
        addHead(obj->head, node);
    }

    return;
}

void lRUCacheFree(LRUCache* obj)
{
    hashTable* cur = NULL;
    hashTable* safe = NULL;
    HASH_ITER(hh, obj->hashPtr, cur, safe)
    {
        HASH_DEL(obj->hashPtr, cur);
        free(cur);
    }

    free(obj->head);
    free(obj->tail);
    free(obj);
}
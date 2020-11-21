#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int key;
    int value;
    struct node* prev;
    struct node* next;
} cacheNode;

typedef struct
{
    int cap;
    int used;
    cacheNode* head;
    cacheNode* tail;
} LRUCache;

cacheNode* LRUnode[3001];

void removeNode(cacheNode* node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

cacheNode* delTail(cacheNode* tail)
{
    cacheNode* node = tail->prev;
    tail->prev = node->prev;
    node->prev->next = tail;
    return node;
}
void addHead(cacheNode* head, cacheNode* node)
{
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
}
LRUCache* lRUCacheCreate(int capacity)
{
    for (int i = 0; i < 3001; i++) {
        LRUnode[i] = NULL;
    }

    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->head = (cacheNode*)malloc(sizeof(cacheNode));
    obj->tail = (cacheNode*)malloc(sizeof(cacheNode));
    obj->cap = capacity;
    obj->used = 0;

    obj->head->prev = NULL;
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;
    obj->tail->next = NULL;

    return obj;
}

int lRUCacheGet(LRUCache* obj, int key)
{
    if (NULL == LRUnode[key]) {
        return -1;
    }

    cacheNode* tmp = LRUnode[key];
    removeNode(tmp);
    addHead(obj->head, tmp);
    return tmp->value;
}

void lRUCachePut(LRUCache* obj, int key, int value)
{
    if (NULL == LRUnode[key]) {
        if (obj->cap == obj->used) {
            cacheNode* node = delTail(obj->tail);
            LRUnode[node->key] = NULL;
            LRUnode[key] = node;
            node->key = key;
            node->value = value;
            addHead(obj->head, node);
        } else {
            obj->used++;
            cacheNode* node = (cacheNode*)malloc(sizeof(cacheNode));
            node->key = key;
            node->value = value;
            LRUnode[key] = node;
            addHead(obj->head, node);
        }
    } else {
        cacheNode* tmp = LRUnode[key];
        removeNode(tmp);
        addHead(obj->head, tmp);
        tmp->value = value;
    }
}

void lRUCacheFree(LRUCache* obj)
{
    for (int i = 0; i < 3001; i++) {
        if (LRUnode[i]) {
            free(LRUnode[i]);
        }
    }

    free(obj->head);
    free(obj->tail);
    free(obj);
}

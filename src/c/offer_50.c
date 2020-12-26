#include <stdio.h>

struct ans {
    int cnt;
    int idx;
};

int cmp(const void* a, const void* b)
{
    struct ans* _a = (struct ans*)a;
    struct ans* _b = (struct ans*)b;
    if (_a->cnt == _b->cnt) {
        return _a->idx - _b->idx;
    }
    return _a->cnt - _b->cnt;
}

char firstUniqChar(char* s)
{
    if (!s) {
        return ' ';
    }

    int len = strlen(s);
    struct ans tmp[26];
    for (int i = 0; i < 26; i++) {
        tmp[i].cnt = 0;
        tmp[i].idx = -1;
    }

    for (int i = 0; i < len; i++) {
        int c = *(s + i) - 'a';
        tmp[c].cnt++;
        if (tmp[c].idx == -1) {
            tmp[c].idx = i;
        }
    }

    qsort(tmp, 26, sizeof(struct ans), cmp);
    for (int i = 0; i < 26; i++) {
        if (tmp[i].cnt == 1) {
            return *(s + tmp[i].idx);
        }
    }

    return ' ';
}
#include <stdio.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
#define MAX_QUEUE_SIZE 5000
int getLevel(struct TreeNode* root)
{
    if (!root) {
        return NULL;
    }

    return 1 + fmax(getLevel(root->left), getLevel(root->right));
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int level = getLevel(root);

    int** result = malloc(sizeof(int*) * level);
    *returnColumnSizes = malloc(sizeof(int) * level);
    struct TreeNode* queue[MAX_QUEUE_SIZE];
    int head = 0;
    int tail = 0;
    *returnSize = 0;
    queue[tail++] = root;
    while (head < tail) {
        int num = tail - head;
        result[*returnSize] = malloc(sizeof(int) * num);
        (*returnColumnSizes)[*returnSize] = num;
        for (int i = 0; i < num; i++) {
            struct TreeNode* tmp = queue[head++];
            result[*returnSize][i] = tmp->val;
            if (tmp->left) {
                queue[tail++] = tmp->left;
            }
            if (tmp->right) {
                queue[tail++] = tmp->right;
            }
        }
        (*returnSize)++;
    }

    return result;
}

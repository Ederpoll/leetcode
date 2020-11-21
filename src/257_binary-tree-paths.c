#include <stdio.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void dfs(struct TreeNode* root, char** path, int* returnSize, int* sta, int top)
{
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            char* tmp = (char*)malloc(sizeof(char) * 1001);
            int len = 0;
            for (int i = 0; i < top; i++) {
                len += sprintf(tmp + len, "%d->", sta[i]);
            }

            sprintf(tmp + len, "%d", root->val);
            path[(*returnSize)++] = tmp;
        } else {
            sta[top++] = root->val;
            dfs(root->left, path, returnSize, sta, top);
            dfs(root->right, path, returnSize, sta, top);
        }
    }
}
char** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    char** path = (char**)malloc(sizeof(char*) * 1001);
    *returnSize = 0;
    int sta[1001];
    dfs(root, path, returnSize, sta, 0);
    return path;
}
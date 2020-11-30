#include <stdio.h>
#define MAX_TREE_NUM 10000
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
void order(struct TreeNode* root, int* ans, int* ansSize)
{
    if (!root) {
        return;
    }

    order(root->left, ans, ansSize);
    ans[(*ansSize)++] = root->val;
    order(root->right, ans, ansSize);
}
int kthLargest(struct TreeNode* root, int k)
{
    int* ans = malloc(sizeof(int) * MAX_TREE_NUM);
    int ansSize = 0;
    order(root, ans, &ansSize);
    int ret = ans[ansSize - k];
    free(ans);
    return ret;
}
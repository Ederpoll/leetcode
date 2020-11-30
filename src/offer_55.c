#include <stdbool.h>
#include <stdio.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
int getLength(struct TreeNode* root)
{
    if (!root) {
        return 0;
    }

    return 1 + fmax(getLength(root->left), getLength(root->right));
}

bool isBalanced(struct TreeNode* root)
{
    if (!root) {
        return true;
    }

    return isBalanced(root->left) && isBalanced(root->right) && fabs(getLength(root->left) - getLength(root->right)) <= 1;
}
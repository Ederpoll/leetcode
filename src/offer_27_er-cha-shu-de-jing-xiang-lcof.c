#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* mirrorTree(struct TreeNode* root)
{
    if (!root) {
        return root;
    }

    struct TreeNode* left = mirrorTree(root->right);
    struct TreeNode* right = mirrorTree(root->left);
    root->left = left;
    root->right = right;
    return root;
}
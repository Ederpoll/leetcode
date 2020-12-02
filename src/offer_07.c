#include <stdio.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if (!preorder || preorderSize == 0 || inorderSize == 0) {
        return NULL;
    }

    int i = 0;
    for (; i < inorderSize; i++) {
        if (inorder[i] == preorder[0]) {
            break;
        }
    }

    struct TreeNode* root = malloc(sizeof(*root));
    root->val = preorder[0];
    root->left = buildTree(preorder + 1, i, inorder, i);
    root->right = buildTree(preorder + i + 1, inorderSize - 1 - i, inorder + i + 1, inorderSize - 1 - i);
    return root;
}
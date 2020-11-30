#include <stdbool.h>
#include <stdio.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isSymmetricChild(struct TreeNode* p1, struct TreeNode* p2)
{
    if (!p1 && !p2) {
        return true;
    }

    if (!p1 || !p2) {
        return false;
    }

    return p1->val == p2->val && isSymmetricChild(p1->left, p2->right) && isSymmetricChild(p1->right, p2->left);
}
bool isSymmetric(struct TreeNode* root)
{
    if (!root) {
        return true;
    }

    return isSymmetricChild(root->left, root->right);

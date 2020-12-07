#include <stdio.h>

typedef struct tree {
    int val;
    struct tree* left;
    struct tree* right;
} tree;

tree* find(int val, tree* root)
{
    if (!root) {
        return NULL;
    }

    while (root) {
        if (val == root->val) {
            return root;
        } else if (val < root->val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
}

tree* insert(int val, tree* root)
{
    if (!root) {
        return;
    }

    while (root) {
        if (val < root->val) {
            if (root->left == NULL) {
                tree* node = (tree*)malloc(sizeof(tree));
                node->val = val;
                return node;
            } else {
                root = root->left;
            }
        } else if (val > root->val) {
            if (root->right == NULL) {
                tree* node = (tree*)malloc(sizeof(tree));
                node->val = val;
                return node;
            } else {
                root = root->right;
            }
        } else {
            return NULL;
        }
    }
}

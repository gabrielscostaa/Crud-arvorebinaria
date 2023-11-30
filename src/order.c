#include <order.h>
#include <main.h>

#include <stdio.h>
#include <stdlib.h>

void preOrder(TreeNode *root) {
    if (root != NULL)
    {
        printf("%d ", root->poltrona);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode *root) {
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->poltrona);
        inOrder(root->right);
    }
}

void postOrder(TreeNode *root) {
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->poltrona);
    }
}
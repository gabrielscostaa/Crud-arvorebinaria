#include <create.h>
#include <main.h>

#include <stdio.h>
#include <stdlib.h>

TreeNode *criarNo(int poltrona) {
    struct TreeNode *no = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (no != NULL)
    {
        no->poltrona = poltrona;
        no->disponivel = 1;
        no->left = NULL;
        no->right = NULL;
    }
    else
    {
        printf("Erro na alocacao...\n");
        exit(0);
    }
    return no;
}

TreeNode *inserirNo(TreeNode *raiz, int poltrona) {
    if (raiz == NULL)
    {
        return criarNo(poltrona);
    }

    if (poltrona < raiz->poltrona)
    {
        raiz->left = inserirNo(raiz->left, poltrona);
    }
    else if (poltrona > raiz->poltrona)
    {
        raiz->right = inserirNo(raiz->right, poltrona);
    }
    else
    {
        printf("Poltrona ja ocupada.\n");
    }
    return raiz;
}
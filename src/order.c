#include <order.h>
#include <main.h>

#include <stdio.h>
#include <stdlib.h>

void preOrder(TreeNode *root) {
    if (root != NULL) {
        printf("%d ", root->poltrona);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->poltrona);
        inOrder(root->right);
    }
}

void postOrder(TreeNode *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->poltrona);
    }
}

void exibirArvore(TreeNode *root) {
    if (root == NULL) {
        printf("Arvore vazia!\n");
        return;
    }
    char escrito[50];
    int opcao;
    printf("Escolha uma opcao de exibicao:\n");
    printf("1 - Pre-ordem\n");
    printf("2 - Em ordem\n");
    printf("3 - Pos-ordem\n");
    printf("4 - Todas\n");
    printf("Opcao: ");
    scanf(" %[^\n]s", escrito);
    if (isNumber(escrito)) {
        opcao = atoi(escrito);
    }
    else {
        opcao = -1;
    }

    switch (opcao) {
    case 1:
        system(CLEAR);
        printf("Pre-ordem: ");
        preOrder(root);
        printf("\n");
        break;
    case 2:
        system(CLEAR);
        printf("Em ordem: ");
        inOrder(root);
        printf("\n");
        break;
    case 3:
        system(CLEAR);
        printf("Pos-ordem: ");
        postOrder(root);
        printf("\n");
        break;
    case 4:
        system(CLEAR);
        printf("Pre-ordem: ");
        preOrder(root);
        printf("\n");
        printf("Em ordem: ");
        inOrder(root);
        printf("\n");
        printf("Pos-ordem: ");
        postOrder(root);
        printf("\n");
        break;
    default:
        printf("Opcao invalida.\n");
        break;
    }
}
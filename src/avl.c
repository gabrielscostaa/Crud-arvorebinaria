#include <avl.h>
#include <main.h>

#include <stdio.h>
#include <stdlib.h>

TreeNode *construirArvoreBalanceada(ListNode **lista, int n) {
   if (n <= 0 || lista == NULL || *lista == NULL) {
        return NULL;
    }

    //constroi árvore esquerda
    TreeNode *left = construirArvoreBalanceada(lista, n / 2);

    //constroi a raiz
    TreeNode *raiz = criarNo((*lista)->poltrona);
    raiz->disponivel = (*lista)->disponivel;
    raiz->left = left;


    *lista = (*lista)->next;


    //constroi arvore direita
    raiz->right = construirArvoreBalanceada(lista, n - n / 2 - 1);

    return raiz;
}

void balancearArvore(TreeNode **raiz) {
    if (*raiz == NULL) {
        printf("Arvore vazia!\n");
        return;
    }
    ListNode *lista = NULL;
    extrairElementos(*raiz, &lista);

    int count = 0;
    ListNode *tmp = lista;
    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }

    *raiz = construirArvoreBalanceada(&lista, count);
    printf("Arvore balanceada com sucesso!\n");
}
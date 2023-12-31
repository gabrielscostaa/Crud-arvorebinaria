#include <delete.h>
#include <main.h>

#include <stdio.h>
#include <stdlib.h>


TreeNode *remove_atual(TreeNode *atual) {
    TreeNode *no1, *no2;
    if (atual->left == NULL) {
        no2 = atual->right;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->left;
    while (no2->right != NULL) {
        no1 = no2;
        no2 = no2->right;
    }
    if (no1 != atual) {
        no1->right = no2->left;
        no2->left = atual->left;
    }
    no2->right = atual->right;
    free(atual);
    return no2;
}

void remove_NO_desejado(TreeNode **raiz)
{
    if (raiz == NULL || *raiz == NULL) {
        printf("Arvore vazia!\n");
        return;
    } 
    TreeNode *atual = *raiz;
    TreeNode *ant = NULL;
    char escrito[50];
    int num = 0;
    int found = 0;
    printf("Digite a poltrona que deseja remover: ");
    scanf(" %[^\n]s", escrito);
    if (isNumber(escrito)) {
        num = atoi(escrito);
    }
    else {
        printf("Digite um numero valido!\n");
        return;
    }
    while (atual != NULL)
    {
        if (num == atual->poltrona)
        {
            if (atual == *raiz)
            {
                *raiz = remove_atual(atual);
            }
            else
            {
                if (ant->right == atual)
                {
                    ant->right = remove_atual(atual);
                }
                else
                {
                    ant->left = remove_atual(atual);
                }
            }
            found = 1;
            break;
        }
        else
        {
            ant = atual;
            if (num > atual->poltrona)
            {
                atual = atual->right;
            }
            else
            {
                atual = atual->left;
            }
        }
    }
    if (!found)
    {
        printf("Elemento nao encontrado!\n");
    } else {
        printf("Elemento removido com sucesso!\n");
    }
}

void liberaArvore(TreeNode *raiz)
{
    if (raiz != NULL)
    {
        liberaArvore(raiz->left);
        liberaArvore(raiz->right);
        free(raiz);
    }
}
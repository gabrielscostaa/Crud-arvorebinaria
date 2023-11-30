#include <search.h>
#include <main.h>

#include <stdio.h>
#include <stdlib.h>

void listarAssentosDisponiveis(TreeNode *raiz)
{
    if (raiz != NULL)
    {
        if (raiz->disponivel)
        {
            printf("Assento %d disponivel\n", raiz->poltrona);
        }
        listarAssentosDisponiveis(raiz->left);
        listarAssentosDisponiveis(raiz->right);
    }
}

void listarAssentosReservados(TreeNode *raiz)
{
    if (raiz != NULL)
    {
        if (!raiz->disponivel)
        {
            printf("Assento %d reservado\n", raiz->poltrona);
        }
        listarAssentosReservados(raiz->left);
        listarAssentosReservados(raiz->right);
    }
}

void reservarAssento(TreeNode *raiz, int poltrona)
{
    printf("Assentos Disponiveis: \n");
    listarAssentosDisponiveis(raiz);

    TreeNode *atual = raiz;
    while (atual != NULL)
    {
        if (atual->poltrona == poltrona)
        {
            if (atual->disponivel)
            {
                atual->disponivel = 0;
                printf("Assento %d reservado com sucesso.\n", poltrona);
            }
            else
            {
                printf("Assento %d ja esta reservado.\n", poltrona);
            }
            return;
        }
        atual = (poltrona < atual->poltrona) ? atual->left : atual->right;
    }
    printf("Assento %d nao encontrado.\n", poltrona);
    return;
}

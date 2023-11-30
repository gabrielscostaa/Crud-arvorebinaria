#include <search.h>
#include <main.h>

#include <stdio.h>
#include <stdlib.h>

void listarAssentosDisponiveis(TreeNode *raiz) {
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

void listarAssentosReservados(TreeNode *raiz) {
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

void listarTodosAssentos (TreeNode *raiz) {
    if (raiz != NULL)
    {
        if (raiz->disponivel)
        {
            printf("Assento %d disponivel\n", raiz->poltrona);
        }
        else
        {
            printf("Assento %d reservado\n", raiz->poltrona);
        }
        listarTodosAssentos(raiz->left);
        listarTodosAssentos(raiz->right);
    }
}

void reservarAssento(TreeNode *raiz, int poltrona) {
    TreeNode *atual = raiz;

    while (atual != NULL && atual->poltrona != poltrona)
    {
        if (poltrona < atual->poltrona)
            atual = atual->left;
        else
            atual = atual->right;
    }

    if (atual == NULL)
    {
        printf("Assento %d nao encontrado.\n", poltrona);
        return;
    }

    char escrito[100];
    int escolha;
    do {
    printf("1. Reservar\n");
    printf("2. Liberar\n");
    printf("0. Cancelar\n");
    printf("Escolha uma opcao: ");
    scanf(" %[^\n]s", escrito);
    if (isNumber(escrito)) {
        escolha = atoi(escrito);
    }
    else {
        escolha = -1;
    }

    switch (escolha)
    {
    case 1:
        system(CLEAR);
        if (atual->disponivel)
        {
            atual->disponivel = 0;
            escolha = 0;
            printf("Assento %d reservado com sucesso.\n", poltrona);
        }
        else
        {
            printf("Assento %d ja esta reservado.\n", poltrona);
        }
        break;
    case 2:
        system(CLEAR);
        if (!atual->disponivel)
        {
            atual->disponivel = 1;
            escolha = 0;
            printf("Assento %d liberado com sucesso.\n", poltrona);
        }
        else
        {
            printf("Assento %d ja esta disponivel.\n", poltrona);
        }
        break;
    case 0:
        system(CLEAR);
        printf("Operacao cancelada.\n");
        break;
    default:
        system(CLEAR);
        printf("Opcao invalida. Tente novamente.\n");
        break;
    }
    } while (escolha != 0);
}

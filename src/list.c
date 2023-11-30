#include <list.h>
#include <main.h>

#include <stdio.h>
#include <stdlib.h>

ListNode *criarNoLista(int poltrona, int disponivel)
{
    ListNode *novo = (ListNode *)malloc(sizeof(ListNode));
    if (novo != NULL)
    {
        novo->poltrona = poltrona;
        novo->disponivel = disponivel;
        novo->prev = NULL;
        novo->next = NULL;
    }
    return novo;
}

void insereOrdenadoLista(ListNode **lista, int poltrona, int disponivel)
{
    ListNode *novo = criarNoLista(poltrona, disponivel);
    if (novo != NULL)
    {
        ListNode *atual = *lista;

        if (*lista == NULL || (*lista)->poltrona >= novo->poltrona)
        {
            novo->next = *lista;
            if (*lista != NULL)
            {
                (*lista)->prev = novo;
            }
            *lista = novo;
        }
        else
        {
            while (atual->next != NULL && atual->next->poltrona < novo->poltrona)
            {
                atual = atual->next;
            }
            novo->next = atual->next;
            if (atual->next != NULL)
            {
                atual->next->prev = novo;
            }
            atual->next = novo;
            novo->prev = atual;
        }
    }
    else
    {
        printf("Erro na alocação de memória.\n");
    }
}

void imprimirLista(ListNode *lista)
{
    ListNode *atual = lista;
    printf("Lista: ");
    while (atual != NULL)
    {
        printf("%d ", atual->poltrona);
        atual = atual->next;
    }
    printf("\n");
}

void liberaLista(ListNode *lista)
{
    ListNode *atual = lista;
    while (atual != NULL)
    {
        ListNode *temp = atual;
        atual = atual->next;
        free(temp);
    }
}

void extrairElementos(TreeNode *raiz, ListNode **lista)
{
    if (raiz != NULL)
    {
        extrairElementos(raiz->left, lista);
        insereOrdenadoLista(lista, raiz->poltrona, raiz->disponivel);
        extrairElementos(raiz->right, lista);
    }
}

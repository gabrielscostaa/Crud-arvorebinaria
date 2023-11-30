#ifndef LIST_H
#define LIST_H

#include <main.h>

ListNode *criarNoLista(int poltrona, int disponivel);
void insereOrdenadoLista(ListNode **lista, int poltrona, int disponivel);
void imprimirLista(ListNode *lista);
void liberaLista(ListNode *lista);
void extrairElementos(TreeNode *raiz, ListNode **lista);

#endif // LIST_H
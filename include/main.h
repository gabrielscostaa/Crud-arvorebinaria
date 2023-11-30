#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _WIN32
    #define CLEAR "cls"
#elif __linux__
    #define CLEAR "clear"
#endif

struct ListNode {
    int poltrona;
    int disponivel;
    struct ListNode *prev;
    struct ListNode *next;
};
typedef struct ListNode ListNode;

struct TreeNode {
    int poltrona;
    int disponivel;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;


// List
ListNode *criarNoLista(int poltrona, int disponivel);
void insereOrdenadoLista(ListNode **lista, int poltrona, int disponivel);
void imprimirLista(ListNode *lista);
void liberaLista(ListNode *lista);
void extrairElementos(TreeNode *raiz, ListNode **lista);

// Create
TreeNode *criarNo(int poltrona);
TreeNode *inserirNo(TreeNode *raiz, int poltrona);

// Delete
TreeNode *remove_atual(TreeNode *atual);
void remove_NO_desejado(TreeNode **raiz);
void liberaArvore(TreeNode *raiz);

// Order
void preOrder(TreeNode *root);
void inOrder(TreeNode *root);
void postOrder(TreeNode *root);
void exibirArvore(TreeNode *root);

// Search
void listarAssentosDisponiveis(TreeNode *raiz);
void listarAssentosReservados(TreeNode *raiz);
void listarTodosAssentos(TreeNode *raiz);
void reservarAssento(TreeNode *raiz, int poltrona);

// AVL Tree
TreeNode *construirArvoreBalanceada(ListNode **lista, int n);                                                                                           
void balancearArvore(TreeNode **raiz);

// Utils
bool isNumber (char *str);

#endif // MAIN_H
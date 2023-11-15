#include <stdio.h>
"includePath": [
    "${workspaceFolder}/**"
]

struct  Teatro{
    int poltrona;
    int Disponivel;
    struct Node *esq
    struct node *dir;
};

typedef teatro *;

//ajuda na impressão da arvore
typedef struct Trunk{
    struct Trunk* prev; // Ponteiro para nó pai
    char* str; // ponteiro para uma string
} Trunk;


struct Node* criarNo(int poltrona){ // adicionar as poltronas
  struct Node *no = (struct node*) malloc(sizeof(Node)); // aloca ponteiro raiz da arvore
    if(no != NULL){
        *no = NULL;
    }else {
        prinf("Erro na alocação...\n");
        exit(0);
    }
return no;

    no -> poltrona = poltrona;
    no -> disponivel = 1;
    no ->esq = Null;
    no _dir = Null;
    return no;
}

Struct Node* Insere_no(struct Node* no){ //função de inserir
    no *novo = (no*) malloc (sizeof(no));//alocação
    if (novo == null){
       return criarNo(int poltrona); //caso for null retornar a escolha da poltrona
    }
    

}



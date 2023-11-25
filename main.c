#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de um nó da árvore binária
struct Node {
    int poltrona;       // Número do assento
    int disponivel;     // Status de disponibilidade (1 - Disponível, 0 - Indisponível)
    struct Node* esq;    // Ponteiro para o filho à esquerda
    struct Node* dir;    // Ponteiro para o filho à direita
};

// Renomeando o ponteiro para a estrutura Node como Teatro
typedef struct Node* Teatro;

// Estrutura para ajudar na impressão da árvore (não afeta a lógica principal)
struct Trunk {
    struct Trunk* prev;
    char* str;
};

// Função para criar um novo nó da árvore
struct Node* criarNo(int poltrona) {
    struct Node* no = (struct Node*)malloc(sizeof(struct Node));
    if (no != NULL) {
        no->poltrona = poltrona;
        no->disponivel = 1;
        no->esq = NULL;
        no->dir = NULL;
    } else {
        printf("Erro na alocação...\n");
        exit(0);
    }
    return no;
}

// Função para inserir um nó na árvore
struct Node* inserirNo(struct Node* raiz, int poltrona) {
    if (raiz == NULL) {
        return criarNo(poltrona);  // Se a raiz é nula, cria um novo nó
    }

    if (poltrona == raiz->poltrona) {
        printf("Assento %d já existe.\n", poltrona);
        return raiz;  // Se o assento já existe, retorna a raiz sem modificar
    } else if (poltrona < raiz->poltrona) {
        raiz->esq = inserirNo(raiz->esq, poltrona);  // Se for menor, insere à esquerda
    } else if (poltrona > raiz->poltrona) {
        raiz->dir = inserirNo(raiz->dir, poltrona);  // Se for maior, insere à direita
    }

    return raiz;
}

// Função auxiliar para exibir a árvore (não afeta a lógica principal)
void showTrunks(struct Trunk* p) {
    while (p != NULL) {
        printf("%s", p->str);
        p = p->prev;
    }
}

// Função auxiliar para criar um novo nó para ajudar na exibição da árvore (não afeta a lógica principal)
struct Trunk* newTrunk(struct Trunk* prev, char* str) {
    struct Trunk* trunk = (struct Trunk*)malloc(sizeof(struct Trunk));
    trunk->str = str;
    trunk->prev = prev;
    return trunk;
}

// Função auxiliar para exibir a árvore (não afeta a lógica principal)
void imprimeArvore(struct Node* raiz, struct Trunk* prev, int isLeft) {
    if (raiz == NULL) {
        return;
    }

    char* prev_str = "    ";
    struct Trunk* trunk = newTrunk(prev, prev_str);
    imprimeArvore(raiz->dir, trunk, 1);

    if (!prev) {
        trunk->str = "---";
    } else if (isLeft) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    printf("%d (%s)\n", raiz->poltrona, (raiz->disponivel == 1) ? "Disponível" : "Indisponível");

    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";
    imprimeArvore(raiz->esq, trunk, 0);
}

// Função para reservar um assento
void reservarAssento(struct Node* raiz) {
    int numeroPoltrona;
    printf("Digite o numero do assento desejado: ");
    scanf("%d", &numeroPoltrona);

    // Encontrar o assento na árvore e reservar
    struct Node* atual = raiz;
    while (atual != NULL) {
        if (numeroPoltrona == atual->poltrona) {
            if (atual->disponivel == 1) {
                atual->disponivel = 0;  // Marcar como indisponível
                printf("Assento %d reservado com sucesso!\n", numeroPoltrona);
            } else {
                printf("Assento %d indisponível.\n", numeroPoltrona);
            }
            return;
        } else if (numeroPoltrona < atual->poltrona) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    // Se o assento não for encontrado
    printf("Assento %d não encontrado.\n", numeroPoltrona);
}

// Função para adicionar novos assentos
void adicionarAssentos(struct Node** raiz) {
    int quantidade;
    printf("Digite a quantidade de novos assentos a serem adicionados: ");
    scanf("%d", &quantidade);

        for (int i = 0; i < quantidade; ++i) {
        int numeroPoltrona;
        printf("Digite o numero do novo assento: ");
        scanf("%d", &numeroPoltrona);

        // Inserir assento apenas se não existir
        if (inserirNo(*raiz, numeroPoltrona) != NULL) {
            printf("Assento %d adicionado com sucesso!\n", numeroPoltrona);
        }
    }
}

// Função para exibir o menu de opções
void menu() {
    printf("\nEscolha uma opcao:\n");
    printf("1. Mostrar mapa de assentos\n");
    printf("2. Reservar assento\n");
    printf("3. Adicionar assentos\n");
    printf("4. Sair\n");
}

// Função principal
int main() {
    struct Node* raiz = NULL;

    // Exemplo de inserção de alguns assentos na árvore
    raiz = inserirNo(raiz, 50);
    raiz = inserirNo(raiz, 30);
    raiz = inserirNo(raiz, 20);
    raiz = inserirNo(raiz, 40);
    raiz = inserirNo(raiz, 70);
    raiz = inserirNo(raiz, 60);
    raiz = inserirNo(raiz, 80);

    int opcao;

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimeArvore(raiz, NULL, 0);
                break;

            case 2:
                reservarAssento(raiz);
                break;

            case 3:
                adicionarAssentos(&raiz);
                break;

            case 4:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}

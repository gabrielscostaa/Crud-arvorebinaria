#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int poltrona;
    int disponivel;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode
{
    int poltrona;
    int disponivel;
    struct ListNode *prev;
    struct ListNode *next;
};

typedef struct TreeNode TreeNode;
typedef struct ListNode ListNode;

//    Área que representa códigos relacionados à lista duplamente encadeada
// ---------------------------------------------------------------------------

ListNode *criarNoLista(int poltrona, int disponivel);
void insereOrdenadoLista(ListNode **lista, int poltrona, int disponivel);
void imprimirLista(ListNode *lista);
void liberaLista(ListNode *lista);
void extrairElementos(TreeNode *raiz, ListNode **lista);


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

//      Área que representa a árvore binária
// --------------------------------------------------

TreeNode *criarNo(int poltrona);
TreeNode *inserirNo(TreeNode *raiz, int poltrona);
void preOrder(TreeNode *root);
void inOrder(TreeNode *root);
void postOrder(TreeNode *root);
void liberaArvore(TreeNode *raiz);
TreeNode *construirArvoreBalanceada(ListNode **lista, int n);
void balancearArvore(TreeNode **raiz);


struct TreeNode *criarNo(int poltrona)
{
    struct TreeNode *no = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (no != NULL)
    {
        no->poltrona = poltrona;
        no->disponivel = 1;
        no->left = NULL;
        no->right = NULL;
    }
    else
    {
        printf("Erro na alocacao...\n");
        exit(0);
    }
    return no;
}

TreeNode *inserirNo(TreeNode *raiz, int poltrona)
{
    if (raiz == NULL)
    {
        return criarNo(poltrona);
    }

    if (poltrona < raiz->poltrona)
    {
        raiz->left = inserirNo(raiz->left, poltrona);
    }
    else if (poltrona > raiz->poltrona)
    {
        raiz->right = inserirNo(raiz->right, poltrona);
    }
    else
    {
        printf("Poltrona ja ocupada.\n");
    }
    return raiz;
}

void preOrder(TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->poltrona);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->poltrona);
        inOrder(root->right);
    }
}

void postOrder(TreeNode *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->poltrona);
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

TreeNode *construirArvoreBalanceada(ListNode **lista, int n)
{
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
    ListNode *lista = NULL;
    extrairElementos(*raiz, &lista);

    int count = 0;
    ListNode *tmp = lista;
    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }

    *raiz = construirArvoreBalanceada(&lista, count);
}
//    Área que representa a reserva de poltronas
// --------------------------------------------------

void listarAssentosDisponiveis(TreeNode *raiz);
void listarAssentosReservados(TreeNode *raiz);
void reservarAssento(TreeNode *raiz, int poltrona);


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

void menu()
{
    printf("\nMenu:\n");
    printf("1. Inserir Assento\n");
    printf("2. Balancear Arvore\n");
    printf("3. Exibir Arvore (Pre-Ordem)\n");
    printf("4. Exibir Arvore (In-Ordem)\n");
    printf("5. Exibir Arvore (Pos-Ordem)\n");
    printf("6. Reservar Assento\n");
    printf("7. Sair\n");
    printf("Escolha uma opcao: ");
}

int main()
{
    TreeNode *raiz = NULL;
    int opcao, poltrona;

    do
    {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            printf("Digite o numero do assento: ");
            scanf("%d", &poltrona);
            raiz = inserirNo(raiz, poltrona);
            break;
        case 2:
            system("cls");
            balancearArvore(&raiz);
            break;
        case 3:
            system("cls");
            preOrder(raiz);
            break;
        case 4:
            system("cls");
            inOrder(raiz);
            break;
        case 5:
            system("cls");
            postOrder(raiz);
            break;
        case 6:
            system("cls");
            int opcaoAssentos = 0;
            while (opcaoAssentos != 4)
            {
                printf("Selecione opcao desejada\n");
                printf("1. Assentos disponiveis:\n");
                printf("2. Assentos reservados:\n");
                printf("3. Reservar assento:\n");
                printf("4. Sair\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &opcaoAssentos);

                switch (opcaoAssentos)
                {
                case 1:
                    system("cls");
                    listarAssentosDisponiveis(raiz);
                    break;
                case 2:
                    system("cls");
                    listarAssentosReservados(raiz);
                    break;
                case 3:
                    system("cls");
                    printf("Digite o numero do assento que deseja reservar: ");
                    scanf("%d", &poltrona);
                    reservarAssento(raiz, poltrona);
                    break;
                case 4:
                    system("cls");
                    printf("Saindo da area de reserva de poltronas\n");
                    break;
                default:
                    printf("Opcao invalida. Tente novamente.\n");
                }
            }
            break;
        case 7:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 7);

    liberaArvore(raiz);
    return 0;
}

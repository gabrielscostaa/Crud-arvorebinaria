#include <main.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool isNumber (char *str) {
    while (*str != '\0')
    {
        if (!isdigit(*str))
        {
            return false;
        }
        str++;
    }
    return true;
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Inserir Assento\n");
    printf("2. Organizar Assentos\n");
    printf("3. Exibir Assentos\n");
    printf("4. Remover Assento\n");
    printf("5. Area de Reservas\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    TreeNode *raiz = NULL;
    char escrito[50];
    int opcao, poltrona, opcaoAssentos;

    printf("  _______ _ _____    ______    ________   ______    _______   \n");
    printf(" |__   __| |_____| ||______|| |__   __|  ||_____|  / ______|| \n");
    printf("    | |  | |___    ||      ||    | |     ||_____|  ||      || \n");
    printf("    | |  | '___|   ||______||    | |     ||||      ||      || \n");
    printf("    | |  | |_____  ||      ||    | |     ||  ||.   ||______||       \n");
    printf("    |_|  |_|_____| ||      ||    | |     ||    ||. ||______/      \n");


    do {
        menu();
        scanf(" %[^\n]s", escrito);
        if (isNumber(escrito)) {
            opcao = atoi(escrito);
        }
        else {
            opcao = -1;
        }

        switch (opcao) {
        case 1:
            system(CLEAR);
            printf("Digite o numero do assento: ");
            scanf(" %[^\n]s", escrito);
            if (isNumber(escrito)) {
                poltrona = atoi(escrito);
            }
            else {
                printf("Numero invalido. Tente novamente.\n");
                break;
            }
            raiz = inserirNo(raiz, poltrona);
            break;
        case 2:
            system(CLEAR);
            balancearArvore(&raiz);
            break;
        case 3:
            system(CLEAR);
            exibirArvore(raiz);
            break;
        case 4:
            system(CLEAR);
            remove_NO_desejado(&raiz);
            break;
        case 5:
            system(CLEAR);
            do {
                if (raiz == NULL) {
                    system(CLEAR);
                    printf("Nao ha assentos cadastrados.\n");
                    break;
                }
                printf("Selecione opcao desejada\n");
                printf("1. Assentos disponiveis\n");
                printf("2. Assentos reservados\n");
                printf("3. Alterar Reservas\n");
                printf("0. Voltar\n");
                printf("Escolha uma opcao: ");
                scanf(" %[^\n]s", escrito);
                if (isNumber(escrito)) {
                    opcaoAssentos = atoi(escrito);
                }
                else {
                    opcaoAssentos = -1;
                }

                switch (opcaoAssentos) {
                case 1:
                    system(CLEAR);
                    listarAssentosDisponiveis(raiz);
                    printf("\n");
                    break;
                case 2:
                    system(CLEAR);
                    listarAssentosReservados(raiz);
                    printf("\n");
                    break;
                case 3:
                    system(CLEAR);
                    listarTodosAssentos(raiz);
                    printf("\n");
                    printf("Digite o numero do assento que deseja alterar: ");
                    scanf(" %[^\n]s", escrito);
                    if (isNumber(escrito)) {
                        poltrona = atoi(escrito);
                    }
                    else {
                        printf("Numero invalido. Tente novamente.\n");
                        break;
                    }
                    reservarAssento(raiz, poltrona);
                    break;
                case 0:
                    system(CLEAR);
                    printf("Saindo da area de reserva de poltronas\n");
                    break;
                default:
                    system(CLEAR);
                    printf("Opcao invalida. Tente novamente.\n");
                }
            } while (opcaoAssentos != 0);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    liberaArvore(raiz);
    return 0;
}

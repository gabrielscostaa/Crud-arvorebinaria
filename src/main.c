#include <main.h>

#include <stdio.h>
#include <stdlib.h>


void menu()
{
    printf("\nMenu:\n");
    printf("1. Inserir Assento\n");
    printf("2. Balancear Arvore\n");
    printf("3. Exibir Arvore (Pre-Ordem)\n");
    printf("4. Exibir Arvore (In-Ordem)\n");
    printf("5. Exibir Arvore (Pos-Ordem)\n");
    printf("6. Reservar Assento\n");
    printf("7. Remover Assento\n");
    printf("8. Sair\n");
    printf("Escolha uma opcao: ");
}

int main()
{
    TreeNode *raiz = NULL;
    int opcao, poltrona;

    printf("  _______ _ _____    ______    ________   ______    _______   \n");
    printf(" |__   __| |_____| ||______|| |__   __|  ||_____|  / ______|| \n");
    printf("    | |  | |___    ||      ||    | |     ||_____|  ||      || \n");
    printf("    | |  | '___|   ||______||    | |     ||||      ||      || \n");
    printf("    | |  | |_____  ||      ||    | |     ||  ||.   ||______||       \n");
    printf("    |_|  |_|_____| ||      ||    | |     ||    ||. ||______/      \n");


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
            system("cls");
            remove_NO_desejado(&raiz);
            break;
        case 8:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 8);

    liberaArvore(raiz);
    return 0;
}

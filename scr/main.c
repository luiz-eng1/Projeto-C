#include <stdio.h>
#include <stdlib.h>
#include "main.h"


#include "cliente.h"
#include "funcionario.h"
#include "quarto.h"
#include "estadia.h"


void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausarTela() {
    printf("\nPressione <ENTER> para continuar...");
    getchar();
    limparBuffer(); 
}



void menuClientes() {
    int op;
    do {
        system("cls || clear"); 
        printf("\n=== GESTAO DE CLIENTES ===\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Pesquisar Cliente\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op);
        limparBuffer();

        switch (op) {
            case 1:
                cadastrarCliente();
                pausarTela();
                break;
            case 2:
                pesquisarCliente();
                pausarTela();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
                pausarTela();
        }
    } while (op != 0);
}

void menuFuncionarios() {
    int op;
    do {
        system("cls || clear");
        printf("\n=== GESTAO DE FUNCIONARIOS ===\n");
        printf("1. Cadastrar Funcionario\n");
        printf("2. Listar Todos\n");
        printf("3. Pesquisar por Codigo\n");
        printf("4. Pesquisar por Nome\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op);
        limparBuffer();

        switch (op) {
            case 1:
                cadastrarFuncionario();
                pausarTela();
                break;
            case 2:
                listarFuncionarios();
                pausarTela();
                break;
            case 3:
                pesquisarFuncionarioPorCodigo();
                pausarTela();
                break;
            case 4:
                pesquisarFuncionarioPorNome();
                pausarTela();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
                pausarTela();
        }
    } while (op != 0);
}

void menuQuartos() {
    int op;
   
    Quarto q;
    int num;

    do {
        system("cls || clear");
        printf("\n=== GESTAO DE QUARTOS ===\n");
        printf("1. Cadastrar Quarto\n");
        printf("2. Buscar/Exibir Quarto\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op);
        limparBuffer();

        switch (op) {
            case 1:
                cadastrarQuarto();
                pausarTela();
                break;
            case 2:
                printf("Digite o numero do quarto: ");
                scanf("%d", &num);
                limparBuffer();
                if (buscarQuartoPorNumero(num, &q)) {
                    exibirQuarto(q);
                } else {
                    printf("Quarto nao encontrado.\n");
                }
                pausarTela();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
                pausarTela();
        }
    } while (op != 0);
}

void menuEstadias() {
    int op;
    do {
        system("cls || clear");
        printf("\n=== GESTAO DE ESTADIAS ===\n");
        printf("1. Cadastrar Estadia (Check-in)\n");
        printf("2. Finalizar Estadia (Check-out)\n");
        printf("3. Dar Baixa / Calcular Pagamento\n");
        printf("4. Listar Estadias de um Cliente\n");
        printf("5. Calcular Pontos Fidelidade\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op);
        limparBuffer();

        switch (op) {
            case 1:
                cadastrarEstadia();
                pausarTela();
                break;
            case 2:
                finalizarEstadia();
                pausarTela();
                break;
            case 3:
                darBaixaEstadia();
                pausarTela();
                break;
            case 4:
                listarEstadiasDeUmCliente();
                pausarTela();
                break;
            case 5:
                calcularPontosFidelidade();
                pausarTela();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
                pausarTela();
        }
    } while (op != 0);
}



int main() {
    
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do {
        system("cls || clear");
        printf("\n=======================================\n");
        printf("   HOTEL DESCANSO GARANTIDO - SISTEMA   \n");
        printf("=======================================\n");
        printf("1. Gestao de Clientes\n");
        printf("2. Gestao de Funcionarios\n");
        printf("3. Gestao de Quartos\n");
        printf("4. Gestao de Estadias\n");
        printf("0. SAIR\n");
        printf("=======================================\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);
        limparBuffer(); 

        switch (opcao) {
            case 1:
                menuClientes();
                break;
            case 2:
                menuFuncionarios();
                break;
            case 3:
                menuQuartos();
                break;
            case 4:
                menuEstadias();
                break;
            case 0:
                printf("\nSaindo do sistema... Ate logo!\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                pausarTela();
        }

    } while (opcao != 0);

    return 0;
}
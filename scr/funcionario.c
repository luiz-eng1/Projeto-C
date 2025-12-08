#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/funcionario.h"

//gerar codigo funcionario
int gerarCodigoFuncionario() {
    FILE *arq = fopen(ARQ_FUNCIONARIOS, "rb");
    if (!arq) return 1;  // se o arquivo não existe, começa em 1

    Funcionario f;
    int ultimoCodigo = 0;

    while (fread(&f, sizeof(Funcionario), 1, arq)) {
        ultimoCodigo = f.idFuncionario;
    }

    fclose(arq);
    return ultimoCodigo + 1;
}

//cadastrar funcionario
void cadastrarFuncionario() {
    FILE *arq = fopen(ARQ_FUNCIONARIOS, "ab");
    if (!arq) {
        printf("Erro ao abrir o arquivo de funcionários!\n");
        return;
    }

    Funcionario f;
    f.idFuncionario = gerarCodigoFuncionario();

    printf("\n--- Cadastro de Funcionário ---\n");
    printf("Nome: ");
    fgets(f.nome, 50, stdin);
    f.nome[strcspn(f.nome, "\n")] = '\0';

    printf("Cargo: ");
    fgets(f.cargo, 30, stdin);
    f.cargo[strcspn(f.cargo, "\n")] = '\0';
    
    printf("Telefone: ");
    fgets(f.telefone, 20, stdin);
    f.telefone[strcspn(f.telefone, "\n")] = '\0';

    printf("Salário: ");
    scanf("%f", &f.salario);

    fwrite(&f, sizeof(Funcionario), 1, arq);
    fclose(arq);

    printf("Funcionário cadastrado com sucesso! ID: %d\n", f.idFuncionario);
}

//lista funcionarios
void listarFuncionarios() {
    FILE *arq = fopen(ARQ_FUNCIONARIOS, "rb");
    if (!arq) {
        printf("Nenhum funcionário cadastrado ainda.\n");
        return;
    }

    Funcionario f;

    printf("\n---- Funcionários Cadastrados ----\n");

    while (fread(&f, sizeof(Funcionario), 1, arq)) {
        printf("\nID: %d\n", f.idFuncionario);
        printf("Nome: %s\n", f.nome);
        printf("Cargo: %s\n", f.cargo);
        printf("Salário: %.2f\n", f.salario);
        printf("-----------------------------------\n");
    }

    fclose(arq);
}

//pesquisar funcionario pelo codigo
void pesquisarFuncionarioPorCodigo() {
    int codigo;
    printf("Digite o código do funcionário: ");
    if (scanf("%d", &codigo) != 1) {
        printf("Código inválido!\n");
        return;
    }

    FILE *arq = fopen(ARQ_FUNCIONARIOS, "rb");
    if (!arq) {
        printf("Erro ao abrir o arquivo de funcionários!\n");
        return;
    }

    Funcionario f;
    int achou = 0;

    while (fread(&f, sizeof(Funcionario), 1, arq)) {
        if (f.idFuncionario == codigo) {
            achou = 1;
            printf("\n--- Funcionário Encontrado ---\n");
            printf("ID: %d\n", f.idFuncionario);
            printf("Nome: %s\n", f.nome);
            printf("Cargo: %s\n", f.cargo);
            printf("Telefone: %s\n", f.telefone);
            printf("Salário: %.2f\n", f.salario);
            printf("------------------------------\n");
            break;
        }
    }

    if (!achou) {
        printf("Nenhum funcionário com código %d foi encontrado.\n", codigo);
    }

    fclose(arq);
}


//funcionario pelo nome (sttrcmp para ignorar letras maiusculas e minusculas)
void pesquisarFuncionarioPorNome() {
    char nomeBuscado[50];
    printf("Digite o nome do funcionário: ");
    fgets(nomeBuscado, 50, stdin);
    nomeBuscado[strcspn(nomeBuscado, "\n")] = '\0';

    FILE *arq = fopen(ARQ_FUNCIONARIOS, "rb");
    if (!arq) {
        printf("Erro ao abrir o arquivo de funcionários!\n");
        return;
    }

    Funcionario f;
    int achou = 0;

    printf("\n--- Resultados da Pesquisa ---\n");

    while (fread(&f, sizeof(Funcionario), 1, arq)) {
        if (strcasecmp(f.nome, nomeBuscado) == 0) {
            achou = 1;
            printf("\nID: %d\n", f.idFuncionario);
            printf("Nome: %s\n", f.nome);
            printf("Cargo: %s\n", f.cargo);
            printf("Telefone: %s\n", f.telefone);
            printf("Salário: %.2f\n", f.salario);
            printf("---------------------------------\n");
        }
    }

    if (!achou) {
        printf("Nenhum funcionário com o nome \"%s\" foi encontrado.\n", nomeBuscado);
    }

    fclose(arq);
}

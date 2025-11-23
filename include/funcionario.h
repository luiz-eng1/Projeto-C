#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#define ARQ_FUNCIONARIOS "funcionarios.bin"

typedef struct {
    int idFuncionario;
    char nome[50];
    char telefone[20];
    char cargo[30];
    float salario;
} Funcionario;

int gerarCodigoFuncionario();
void cadastrarFuncionario();
void listarFuncionarios();
void pesquisarFuncionarioPorCodigo();
void pesquisarFuncionarioPorNome();

#endif

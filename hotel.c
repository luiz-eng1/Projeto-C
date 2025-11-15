//Sistema Hotel Descanso Garantido  
#include <stdio.h>


struct Cliente{
    int idCliente;
    char nome[50];
    char endereço[100];
    int telefone;

};

struct Funcionario{
    int idFuncionario;
    char nome[50];
    int telefone;
    char cargo[50];
    float salario;
};

struct Estadia{
    int idEstadia;
    int dataEntrada;
    int dataSaida;
    int qntDiarias;
    int idCliente;
    int nQuarto;

};

struct Quarto{
    int numeroQuarto;
    int qtdHospedes;
    float valorDiaria;
    char status[20];
};

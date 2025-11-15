//Sistema Hotel Descanso Garantido  
#include <stdio.h>

// structs
struct Cliente{
    int idCliente;
    char nome[50];
    char endereço[100];
    char telefone[20];

};

struct Funcionario{
    int idFuncionario;
    char nome[50];
    char telefone[20];
    char cargo[50];
    float salario;
};

struct Data{
    int dia;
    int mes;
    int ano;
};

struct Estadia{
    int idEstadia;
    struct Data dataEntrada;
    struct Data dataSaida;
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


// criando o vetor de structs
struct Cliente clientes[100];
struct Funcionario funcionarios[100];
struct Data datas[100];
struct Estadia estadias[100];
struct Quarto quartos[100];



//contadores    (para usar Ex. clientes[i].nome, acessando do indice teria que usar laço, ou criar um contador  <-)
int ultimoCodigoCliente = 0;
int qtdClientes = 0;
int qtdFuncionarios = 0;
int qtdQuartos = 0;



// funções 

void CadastrarCliente(){

    printf("Nome do Cliente: ");
    fgets(clientes[qtdClientes].nome, 50, stdin);

    printf("Endereço do cliente: ");
    fgets(clientes[qtdClientes].endereço, 50, stdin);

    printf("Telefone do cliente: ");
    fgets(clientes[qtdClientes].telefone, 20, stdin);

    ultimoCodigoCliente++;
    clientes[qtdClientes].idCliente == ultimoCodigoCliente;
};
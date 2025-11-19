#ifndef ESTADIA_H
#define ESTADIA_H

#include "../include/cliente.h"
#include "../include/quarto.h"

#define ARQ_ESTADIAS "estadias.bin"

typedef struct{
    int idEstadia;
    int idCliente;
    int numeroQuarto;
    char dataEntrada[11];
    char dataSaida[11];
    int qtdDiarias;
}Estadia;

int gerarCodigoEstadia();
int calcularDiarias(char entrada[], char saida[]);
int verificarConflito(int numeroQuarto, char entrada[], char saida[]);
void cadastrarEstadia();
void finalizarEstadia();
void darBaixaEstadia();

#endif 
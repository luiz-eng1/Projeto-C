#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQ_CLIENTES "data/clientes.bin"

typedef struct {
    int idCliente;
    char nome[50];
    char endereco[100];
    char telefone[20];
} Cliente;

int gerarCodigoCliente();

void cadastrarCliente();

void pesquisarCliente();

void exibirCliente(Cliente c);

#endif

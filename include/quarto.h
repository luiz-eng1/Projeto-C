#ifndef QUARTO_H
#define QUARTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQ_QUARTOS "data/quartos.bin"

typedef struct {
    int numero;
    int capacidade;
    float valorDiaria;
    char status[15];   // "ocupado" ou "desocupado"
} Quarto;

void cadastrarQuarto();

int buscarQuartoPorNumero(int numero, Quarto *q);

float buscarValorDiaria(int numeroQuarto);

void exibirQuarto(Quarto q);

#endif

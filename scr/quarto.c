#include "../include/quarto.h"

int buscarQuartoPorNumero(int numero, Quarto *q) {
    FILE *arq = fopen(ARQ_QUARTOS, "rb");
    if (!arq) return 0;

    Quarto temp;
    while (fread(&temp, sizeof(Quarto), 1, arq)) {
        if (temp.numero == numero) {
            if (q) *q = temp;
            fclose(arq);
            return 1;
        }
    }

    fclose(arq);
    return 0;
}

void cadastrarQuarto() {
    FILE *arq = fopen(ARQ_QUARTOS, "ab");
    if (!arq) {
        printf("Erro ao abrir arquivo de quartos.\n");
        return;
    }

    Quarto q;
    printf("\n--- CADASTRO DE QUARTO ---\n");
    char buf[128];
    char *endptr;

    // Número do quarto
    printf("Número do quarto: ");
    if (!fgets(buf, sizeof(buf), stdin)) {
        printf("Entrada inválida. Operação cancelada.\n");
        fclose(arq);
        return;
    }
    q.numero = (int)strtol(buf, &endptr, 10);
    if (endptr == buf) {
        printf("Entrada inválida para número do quarto.\n");
        fclose(arq);
        return;
    }

    if (buscarQuartoPorNumero(q.numero, NULL)) {
        printf("\nERRO: Já existe um quarto com esse número!\n");
        fclose(arq);
        return;
    }

    // Capacidade
    printf("Capacidade de hóspedes: ");
    if (!fgets(buf, sizeof(buf), stdin)) {
        printf("Entrada inválida. Operação cancelada.\n");
        fclose(arq);
        return;
    }
    q.capacidade = (int)strtol(buf, &endptr, 10);
    if (endptr == buf || q.capacidade <= 0) {
        printf("Entrada inválida para capacidade (deve ser > 0).\n");
        fclose(arq);
        return;
    }

    // Valor da diária
    printf("Valor da diária: ");
    if (!fgets(buf, sizeof(buf), stdin)) {
        printf("Entrada inválida. Operação cancelada.\n");
        fclose(arq);
        return;
    }
    q.valorDiaria = strtof(buf, &endptr);
    if (endptr == buf || q.valorDiaria < 0.0f) {
        printf("Entrada inválida para valor da diária (deve ser >= 0).\n");
        fclose(arq);
        return;
    }

    // Status seguro
    strncpy(q.status, "desocupado", sizeof(q.status) - 1);
    q.status[sizeof(q.status) - 1] = '\0';

    // Grava e verifica escrita
    size_t wrote = fwrite(&q, sizeof(Quarto), 1, arq);
    if (wrote != 1) {
        perror("Erro ao gravar quarto");
        fclose(arq);
        return;
    }
    fclose(arq);

    printf("\nQuarto cadastrado com sucesso!\n");
}

void exibirQuarto(Quarto q) {
    printf("\n-----------------------------\n");
    printf("Número: %d\n", q.numero);
    printf("Capacidade: %d\n", q.capacidade);
    printf("Valor da diária: %.2f\n", q.valorDiaria);
    printf("Status: %s\n", q.status);
    printf("-----------------------------\n");
}

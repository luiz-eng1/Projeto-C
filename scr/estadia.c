#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/estadia.h"

int gerarCodigoEstadia(){
    FILE *arq = fopen(ARQ_ESTADIAS, "rb");
    if (!arq) return 1;

    Estadia temp;
    int ultimo = 0;

    while (fread(&temp, sizeof(Estadia), 1, arq)) {
        if (temp.idEstadia > ultimo) {
            ultimo = temp.idEstadia;
        }
    }

    fclose(arq);
    return ultimo + 1;
}
int calcularDiarias(char entrada[], char saida[])
{
    int d1,m1,a1,d2,m2,a2;
    if (sscanf(entrada, "%d/%d/%d", &d1, &m1, &a1) != 3) return 0;
    if (sscanf(saida, "%d/%d/%d", &d2, &m2, &a2) != 3) return 0;

    return (d2 + m2 * 30 + a2 * 365) - (d1 + m1 * 30 + a1 * 365);
}
int verificarConflito(int numeroQuarto, char entrada[], char saida[])
{
    FILE *arq = fopen(ARQ_ESTADIAS, "rb");
    if (!arq) return 0;

    Estadia temp;
    int d1,m1,a1,d2,m2,a2;
    int x1,xm1,xa1,x2,xm2,xa2;

    if (sscanf(entrada, "%d/%d/%d", &d1, &m1, &a1) != 3) {

        fclose(arq);
        return 1;
    }
    if (sscanf(saida, "%d/%d/%d", &d2, &m2, &a2) != 3) {
        fclose(arq);
        return 1;
    }

    while(fread(&temp, sizeof(Estadia), 1, arq)){
        if(temp.numeroQuarto == numeroQuarto){
            if (sscanf(temp.dataEntrada, "%d/%d/%d", &x1, &xm1, &xa1) != 3) continue;
            if (sscanf(temp.dataSaida, "%d/%d/%d", &x2, &xm2, &xa2) != 3) continue;

            int inicioNovo = d1 + m1 * 30 + a1 * 365;
            int finalNovo  = d2 + m2 * 30 + a2 * 365;
            int inicioExistente = x1 + xm1 * 30 + xa1 * 365;
            int finalExistente  = x2 + xm2 * 30 + xa2 * 365;

            if (!(finalNovo <= inicioExistente || inicioNovo >= finalExistente)){
                fclose(arq);
                return 1;
            }
        }
    }
    fclose(arq);
    return 0;
}
void cadastrarEstadia(){
    FILE *arq = fopen(ARQ_ESTADIAS, "ab");
    if(!arq){
        printf("Erro ao abrir o arquivo de estadias.\n");
        return;
    }

    Estadia novaEstadia;
    int hospedes;
    printf("Digite o ID do cliente:");
    if (scanf("%d", &novaEstadia.idCliente) != 1) {
        printf("ID do cliente inválido.\n");
        fclose(arq);
        return;
    }
    if(!buscarClientePorId(novaEstadia.idCliente)){
        printf("Cliente nao encontrado.\n");
        fclose(arq);
        return;
    }
    printf("Digite a quantidade de hospedes:");
    if (scanf("%d", &hospedes) != 1) {
        printf("Quantidade de hospedes inválida.\n");
        fclose(arq);
        return;
    }

    int numeroQuarto = encontrarQuartoDisponivel(hospedes);
    if(numeroQuarto == -1){
        printf("Nao ha quartos disponiveis para essa quantidade de hospedes.\n");
        fclose(arq);
        return;
    }
    novaEstadia.numeroQuarto = numeroQuarto;

    printf("Digite a data de entrada (DD/MM/AAAA): ");
    if (scanf("%10s", novaEstadia.dataEntrada) != 1) {
        printf("Data de entrada inválida.\n");
        fclose(arq);
        return;
    }
    printf("Digite a data de saida (DD/MM/AAAA): ");
    if (scanf("%10s", novaEstadia.dataSaida) != 1) {
        printf("Data de saida inválida.\n");
        fclose(arq);
        return;
    }

    // validação básica de intervalo
    int diarias = calcularDiarias(novaEstadia.dataEntrada, novaEstadia.dataSaida);
    if (diarias <= 0) {
        printf("Intervalo de datas inválido (saída deve ser posterior à entrada).\n");
        fclose(arq);
        return;
    }

    if(verificarConflito(numeroQuarto, novaEstadia.dataEntrada, novaEstadia.dataSaida)){
        printf("Conflito de reserva para o quarto %d nas datas informadas.\n", numeroQuarto);
        fclose(arq);
        return;
    }
    novaEstadia.qtdDiarias = diarias;
    novaEstadia.idEstadia = gerarCodigoEstadia();

    if (fwrite(&novaEstadia, sizeof(Estadia), 1, arq) != 1) {
        perror("Erro ao gravar estadia");
        fclose(arq);
        return;
    }
    fclose(arq);

    atualizarStatusQuarto(numeroQuarto, 0);

    printf("Estadia cadastrada com sucesso! ID da Estadia: %d\n", novaEstadia.idEstadia);
}
void finalizarEstadia(){
    int idEstadia;
    printf("Digite o ID da estadia a ser finalizada: ");
    if (scanf("%d", &idEstadia) != 1) {
        printf("ID da estadia inválido.\n");
        return;
    }

    FILE *arq = fopen(ARQ_ESTADIAS, "r+b");
    if (!arq) {
        printf("Erro ao abrir o arquivo de estadias.\n");
        return;
    }

    Estadia temp;
    int achou = 0;
    while (fread(&temp, sizeof(Estadia), 1, arq)) {
        if (temp.idEstadia == idEstadia) {
            achou = 1;
            break;
        }
    }

    if (!achou) {
        printf("Estadia com ID %d nao encontrada.\n", idEstadia);
        fclose(arq);
        return;
    }

    atualizarStatusQuarto(temp.numeroQuarto, 1);

    printf("Estadia com ID %d finalizada com sucesso.\n", idEstadia);
    fclose(arq);
}
#include "../include/cliente.h"

int gerarCodigoCliente() {
    FILE *arq = fopen(ARQ_CLIENTES, "rb");
    if (!arq) return 1; // se não existe arquivo, começa em 1

    Cliente c;
    int ultimoCodigo = 0;

    while (fread(&c, sizeof(Cliente), 1, arq)) {
        ultimoCodigo = c.idCliente;
    }

    fclose(arq);
    return ultimoCodigo + 1;
}

void cadastrarCliente() {
    FILE *arq = fopen(ARQ_CLIENTES, "ab");
    if (!arq) {
        printf("Erro ao abrir arquivo de clientes.\n");
        return;
    }

    Cliente c;
    c.idCliente = gerarCodigoCliente();

    printf("\n--- CADASTRO DE CLIENTE ---\n");

    printf("Nome: ");
    fgets(c.nome, 50, stdin);
    c.nome[strcspn(c.nome, "\n")] = '\0';

    printf("Endereco: ");
    fgets(c.endereco, 80, stdin);
    c.endereco[strcspn(c.endereco, "\n")] = '\0';

    printf("Telefone: ");
    fgets(c.telefone, 20, stdin);
    c.telefone[strcspn(c.telefone, "\n")] = '\0';

    fwrite(&c, sizeof(Cliente), 1, arq);
    fclose(arq);

    printf("\nCliente cadastrado com sucesso! Codigo: %d\n", c.idCliente);
}

int buscarClientePorCodigo(int codigo, Cliente *resultado) {
    FILE *arq = fopen(ARQ_CLIENTES, "rb");
    if (!arq) return 0;

    Cliente c;

    while (fread(&c, sizeof(Cliente), 1, arq)) {
        if (c.idCliente == codigo) {
            *resultado = c;
            fclose(arq);
            return 1;
        }
    }

    fclose(arq);
    return 0;
}

void buscarClientePorNome(char *nome) {
    FILE *arq = fopen(ARQ_CLIENTES, "rb");
    if (!arq) {
        printf("Nenhum cliente cadastrado ainda.\n");
        return;
    }

    Cliente c;
    int encontrou = 0;

    printf("\nResultados da busca por nome \"%s\":\n", nome);

    while (fread(&c, sizeof(Cliente), 1, arq)) {
        if (strstr(c.nome, nome) != NULL) {
            exibirCliente(c);
            encontrou = 1;
        }
    }

    if (!encontrou)
        printf("Nenhum cliente encontrado.\n");

    fclose(arq);
}

void exibirCliente(Cliente c) {
    printf("\n-----------------------------\n");
    printf("Codigo: %d\n", c.idCliente);
    printf("Nome: %s\n", c.nome);
    printf("Endereco: %s\n", c.endereco);
    printf("Telefone: %s\n", c.telefone);
    printf("-----------------------------\n");
}

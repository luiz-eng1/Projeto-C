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

void pesquisarCliente() {
    FILE *arquivo = fopen("clientes.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro: Nenhum banco de dados de clientes encontrado ou erro na abertura.\n");
        return;
    }

    int opcao;
    printf("\n--- Pesquisar Cliente ---\n");
    printf("1. Buscar por Codigo\n");
    printf("2. Buscar por Nome\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    Cliente c;
    int encontrado = 0;

    if (opcao == 1) {
        int codigoBusca;
        printf("Digite o codigo do cliente: ");
        scanf("%d", &codigoBusca);

        while(fread(&c, sizeof(Cliente), 1, arquivo)) {
            if(c.idCliente == codigoBusca) {
                printf("\n>> Cliente Encontrado:\n");
                printf("Codigo: %d\nNome: %s\nTelefone: %s\nEndereco: %s\n", 
                       c.idCliente, c.nome, c.telefone, c.endereco);
                encontrado = 1;
                break; 
            }
        }
    } 
    else if (opcao == 2) {
        char nomeBusca[100];
        printf("Digite o nome (ou parte dele): ");
        getchar(); 
        fgets(nomeBusca, 100, stdin);
        nomeBusca[strcspn(nomeBusca, "\n")] = 0;

        printf("\n>> Resultados da Busca:\n");
        while(fread(&c, sizeof(Cliente), 1, arquivo)) {

            if(strstr(c.nome, nomeBusca) != NULL) {
                printf("-----------------------------\n");
                printf("Codigo: %d\nNome: %s\nTelefone: %s\n", c.idCliente, c.nome, c.telefone);
                encontrado = 1;
            }
        }
    } else {
        printf("Opcao invalida.\n");
    }

    if (!encontrado) {
        printf("\nNenhum registro encontrado com esses dados.\n");
    }

    fclose(arquivo);
}

void exibirCliente(Cliente c) {
    printf("\n-----------------------------\n");
    printf("Codigo: %d\n", c.idCliente);
    printf("Nome: %s\n", c.nome);
    printf("Endereco: %s\n", c.endereco);
    printf("Telefone: %s\n", c.telefone);
    printf("-----------------------------\n");
}

# Link do vídeo: https://drive.google.com/file/d/1o93TKDpUmh-s7MVssXF7YFAxZ1To1XsA/view?usp=sharing
# Sistema Hotel Descanso Garantido

Sistema de gerenciamento hoteleiro desenvolvido em C para a disciplina de Algoritmos e Estruturas de Dados 1 (2025).

## 📋 Funcionalidades

- **Gestão de Clientes**: Cadastro e pesquisa de clientes (por código ou nome)
- **Gestão de Funcionários**: Cadastro, listagem e pesquisa de funcionários
- **Gestão de Quartos**: Cadastro de quartos com capacidade, valor de diária e status (ocupado/desocupado)
- **Gestão de Estadias**: 
  - Check-in (cadastro de estadia)
  - Check-out (finalização de estadia)
  - Cálculo de diárias e pagamento
  - Listagem de estadias por cliente
  - Sistema de pontos de fidelidade

## 🛠️ Pré-requisitos

- **MinGW** (GCC para Windows) instalado
- Windows PowerShell ou terminal compatível
- Editor de código (VS Code recomendado)

## 📁 Estrutura do Projeto

```
Projeto-C/
├── include/           # Arquivos de cabeçalho (.h)
│   ├── cliente.h
│   ├── estadia.h
│   ├── funcionario.h
│   ├── main.h
│   └── quarto.h
├── scr/              # Código fonte (.c)
│   ├── cliente.c
│   ├── estadia.c
│   ├── funcionario.c
│   ├── main.c
│   └── quarto.c
├── data/             # Arquivos binários (gerados automaticamente)
├── output/           # Executável compilado
└── README.md
```

## 🚀 Como Compilar

### Opção 1: Linha de Comando (PowerShell)

Navegue até a pasta do projeto e execute:

```powershell
cd "c:\Users\eliju\OneDrive\Área de Trabalho\Projeto-C"
& 'C:\MinGW\bin\gcc.exe' -Wall -Wextra -g scr/*.c -I include -o output/main.exe
```

Se o `gcc` estiver no PATH:

```powershell
gcc -Wall -Wextra -g scr/*.c -I include -o output/main.exe
```

### Opção 2: VS Code (Build Task)

1. Abra o projeto no VS Code
2. Pressione `Ctrl+Shift+B` para executar a tarefa de build
3. Ou vá em `Terminal > Run Build Task...`

O arquivo `tasks.json` já está configurado no projeto.

## ▶️ Como Executar

Após compilar, execute o programa:

```powershell
.\output\main.exe
```

## 📖 Como Usar

### Menu Principal

Ao iniciar, você verá o menu principal com 4 opções:

```
=======================================
   HOTEL DESCANSO GARANTIDO - SISTEMA   
=======================================
1. Gestão de Clientes
2. Gestão de Funcionários
3. Gestão de Quartos
4. Gestão de Estadias
0. SAIR
=======================================
```

### Fluxo Recomendado de Uso

1. **Cadastrar Quartos** (Menu 3 → Opção 1)
   - Defina número, capacidade e valor da diária
   
2. **Cadastrar Clientes** (Menu 1 → Opção 1)
   - Registre nome, endereço e telefone
   
3. **Cadastrar Funcionários** (Menu 2 → Opção 1) *(opcional)*
   - Registre nome, cargo, telefone e salário

4. **Cadastrar Estadia / Check-in** (Menu 4 → Opção 1)
   - Informe ID do cliente, quantidade de hóspedes e datas
   - Sistema automaticamente aloca quarto disponível

5. **Finalizar Estadia / Check-out** (Menu 4 → Opção 2)
   - Informe ID da estadia para liberar o quarto

6. **Dar Baixa / Calcular Pagamento** (Menu 4 → Opção 3)
   - Visualize valor total da estadia

7. **Pontos de Fidelidade** (Menu 4 → Opção 5)
   - Consulte pontos acumulados (10 pontos por diária)

## 🗃️ Armazenamento de Dados

Os dados são armazenados em arquivos binários na pasta `data/`:

- `clientes.bin` - Dados dos clientes
- `funcionarios.bin` - Dados dos funcionários
- `quartos.bin` - Dados dos quartos
- `estadias.bin` - Histórico de estadias

## 👥 Autores

Trabalho desenvolvido para a disciplina de Algoritmos e Estruturas de Dados 1 (AED 1) - 2025
- Eli Júnior Domingos Dias
- Guilherme Henrique Ribeiro Silva
- Luiz Eduardo Campos Silva

Este projeto é de uso acadêmico.

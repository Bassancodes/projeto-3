#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "funcoes.h" 


int num_contatos = 0; // Inicializa o número de contatos como zero.

void adicionarContato() { // Função para adicionar um novo contato.
    if (num_contatos >= MAX_CONTATOS) { // Verifica se o número máximo de contatos foi atingido.
        printf("A agenda está cheia!\n"); // Informa ao usuário que a agenda está cheia.
        return; // Sai da função sem adicionar um novo contato.
    }

    Contato novoContato; // Declara uma variável para armazenar o novo contato.

    printf("Digite o nome: "); // Solicita ao usuário que digite o nome do contato.
    scanf("%s", novoContato.nome); // Lê o nome digitado pelo usuário e armazena na variável 'novoContato'.

    printf("Digite o sobrenome: "); // Solicita ao usuário que digite o sobrenome do contato.
    scanf("%s", novoContato.sobrenome); // Lê o sobrenome digitado pelo usuário e armazena na variável 'novoContato'.

    printf("Digite o email: "); // Solicita ao usuário que digite o email do contato.
    scanf("%s", novoContato.email); // Lê o email digitado pelo usuário e armazena na variável 'novoContato'.

    printf("Digite o telefone: "); // Solicita ao usuário que digite o telefone do contato.
    scanf("%s", novoContato.telefone); // Lê o telefone digitado pelo usuário e armazena na variável 'novoContato'.

    agenda[num_contatos++] = novoContato; // Adiciona o novo contato à agenda e incrementa o contador de contatos.
    printf("Contato adicionado com sucesso!\n"); // Informa ao usuário que o contato foi adicionado com sucesso.
}

void listarContatos() { // Função para listar todos os contatos na agenda.
    printf("Lista de contatos:\n"); // Exibe um cabeçalho para a lista de contatos.
    for (int i = 0; i < num_contatos; i++) { // Itera sobre todos os contatos na agenda.
        printf("%d: %s %s - %s, %s\n", i + 1, agenda[i].nome, agenda[i].sobrenome, agenda[i].email, agenda[i].telefone); 
        // Exibe o índice (iniciado em 1) e as informações de cada contato.
    }
}



void deletarContato() { // Função para deletar um contato da agenda.
    char telefone[TAMANHO_TELEFONE]; // Declara uma variável para armazenar o telefone do contato a ser deletado.

    printf("Digite o telefone do contato que deseja deletar: "); // Solicita ao usuário que digite o telefone do contato a ser deletado.
    scanf("%s", telefone); // Lê o telefone digitado pelo usuário e armazena na variável 'telefone'.

    for (int i = 0; i < num_contatos; i++) { // Itera sobre todos os contatos na agenda.
        if (strcmp(agenda[i].telefone, telefone) == 0) { // Verifica se o telefone do contato atual é igual ao telefone fornecido pelo usuário.
            for (int j = i; j < num_contatos - 1; j++) { // Move todos os contatos subsequentes uma posição para trás, sobrescrevendo o contato a ser deletado.
                agenda[j] = agenda[j + 1]; // Substitui o contato atual pelo próximo contato na agenda.
            }
            num_contatos--; // Decrementa o contador de contatos, pois um contato foi deletado.
            printf("Contato deletado com sucesso!\n"); // Informa ao usuário que o contato foi deletado com sucesso.
            return; // Sai da função após deletar o contato.
        }
    }

    printf("Contato não encontrado!\n"); // Informa ao usuário que o contato não foi encontrado na agenda.
}


void salvarAgenda() { // Função para salvar a agenda em um arquivo binário.
    FILE *arquivo = fopen("agenda.bin", "wb"); // Abre o arquivo "agenda.bin" em modo de escrita binária.
    if (arquivo == NULL) { // Verifica se o arquivo foi aberto corretamente.
        printf("Erro ao abrir arquivo!\n"); // Informa ao usuário que houve um erro ao abrir o arquivo.
        return; // Sai da função, pois o arquivo não pôde ser aberto.
    }

    fwrite(&num_contatos, sizeof(int), 1, arquivo); // Escreve o número de contatos na agenda no arquivo.
    fwrite(agenda, sizeof(Contato), num_contatos, arquivo); // Escreve todos os contatos na agenda no arquivo.

    fclose(arquivo); // Fecha o arquivo após terminar de escrever os dados.
    printf("Agenda salva com sucesso!\n"); // Informa ao usuário que a agenda foi salva com sucesso.
}

void carregarAgenda() {
    FILE *arquivo = fopen("agenda.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo de agenda não encontrado!\n");
        return;
    }

    fread(&num_contatos, sizeof(int), 1, arquivo);
    fread(agenda, sizeof(Contato), num_contatos, arquivo);

    fclose(arquivo);
    printf("Agenda carregada com sucesso!\n");
}




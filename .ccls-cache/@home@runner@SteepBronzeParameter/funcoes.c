#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "funcoes.h" 


int num_contatos = 0; // Inicializa o número de contatos como zero.

void adicionarContato() {
    if (num_contatos >= MAX_CONTATOS) {
        printf("A agenda está cheia!\n");
        return;
    }

    Contato novoContato;

    printf("Digite o nome: ");
    scanf("%s", novoContato.nome);
    printf("Digite o sobrenome: ");
    scanf("%s", novoContato.sobrenome);
    printf("Digite o email: ");
    scanf("%s", novoContato.email);
    printf("Digite o telefone: ");
    scanf("%s", novoContato.telefone);

    agenda[num_contatos++] = novoContato;
    printf("Contato adicionado com sucesso!\n");
}

void listarContatos() { // Definição da função para listar todos os contatos na agenda.
    printf("Lista de contatos:\n"); // Exibe uma mensagem indicando que a lista de contatos será exibida.
    for (int i = 0; i < num_contatos; i++) { // Loop para iterar sobre todos os contatos na agenda.
        printf("%d: %s %s - %s, %s\n", i + 1, agenda[i].nome, agenda[i].sobrenome, agenda[i].email, agenda[i].telefone); // Exibe as informações do contato na tela.
    }
}
void listarContatos() {
    printf("Lista de contatos:\n");
    for (int i = 0; i < num_contatos; i++) {
        printf("%d: %s %s - %s, %s\n", i + 1, agenda[i].nome, agenda[i].sobrenome, agenda[i].email, agenda[i].telefone);
    }
}



void deletarContato() {
    char telefone[TAMANHO_TELEFONE];
    printf("Digite o telefone do contato que deseja deletar: ");
    scanf("%s", telefone);

    for (int i = 0; i < num_contatos; i++) {
        if (strcmp(agenda[i].telefone, telefone) == 0) {
            for (int j = i; j < num_contatos - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            num_contatos--;
            printf("Contato deletado com sucesso!\n");
            return;
        }
    }

    printf("Contato não encontrado!\n");
}

void salvarAgenda() {
    FILE *arquivo = fopen("agenda.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    fwrite(&num_contatos, sizeof(int), 1, arquivo);
    fwrite(agenda, sizeof(Contato), num_contatos, arquivo);

    fclose(arquivo);
    printf("Agenda salva com sucesso!\n");
}



void salvarAgenda() { // Definição da função para salvar a agenda em um arquivo binário.
    FILE *arquivo = fopen("agenda.bin", "wb"); // Abre um arquivo binário para escrita.
    if (arquivo == NULL) { // Verifica se houve erro ao abrir o arquivo.
        printf("Erro ao abrir arquivo!\n"); // Exibe uma mensagem de erro informando que houve um erro ao abrir o arquivo.
        return; // Retorna da função em caso de erro.
    }

    fwrite(&num_contatos, sizeof(int), 1, arquivo); // Escreve o número de contatos na agenda no arquivo.
    fwrite(agenda, sizeof(Contato), num_contatos, arquivo); // Escreve os contatos da agenda no arquivo.

    fclose(arquivo); // Fecha o arquivo após terminar de escrever os dados.
    printf("Agenda salva com sucesso!\n"); // Exibe uma mensagem informando que a agenda foi salva com sucesso.
}

void carregarAgenda() { // Definição da função para carregar a agenda de um arquivo binário.
    FILE *arquivo = fopen("agenda.bin", "rb"); // Abre um arquivo binário para leitura.
    if (arquivo == NULL) { // Verifica se houve erro ao abrir o arquivo.
        printf("Arquivo de agenda não encontrado!\n"); // Exibe uma mensagem informando que o arquivo de agenda não foi encontrado.
        return; // Retorna da função em caso de erro.
    }

    fread(&num_contatos, sizeof(int), 1, arquivo); // Lê o número de contatos do arquivo.
    fread(agenda, sizeof(Contato), num_contatos, arquivo); // Lê os contatos do arquivo.

    fclose(arquivo); // Fecha o arquivo após terminar de ler os dados.
    printf("Agenda carregada com sucesso!\n"); // Exibe uma mensagem informando que a agenda foi carregada com sucesso.
}

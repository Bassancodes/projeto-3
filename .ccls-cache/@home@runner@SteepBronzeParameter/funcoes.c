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



void deletarContato() { // Definição da função para deletar um contato da agenda.
    char telefone[15]; // Declara uma variável para armazenar o telefone do contato a ser deletado.
    printf("Digite o telefone do contato que deseja deletar: "); // Solicita ao usuário que digite o telefone do contato a ser deletado.
    scanf("%s", telefone); // Lê o telefone do contato fornecido pelo usuário e armazena na variável.

    for (int i = 0; i < num_contatos; i++) { // Loop para iterar sobre todos os contatos na agenda.
        if (strcmp(agenda[i].telefone, telefone) == 0) { // Verifica se o telefone do contato atual é igual ao telefone fornecido pelo usuário.
            for (int j = i; j < num_contatos - 1; j++) { // Loop para deslocar os contatos uma posição para trás, excluindo o contato a ser deletado.
                agenda[j] = agenda[j + 1]; // Desloca o contato uma posição para trás na agenda.
            }
            num_contatos--; // Decrementa o número de contatos na agenda.
            printf("Contato deletado com sucesso!\n"); // Exibe uma mensagem informando que o contato foi deletado com sucesso.
            return; // Retorna da função após encontrar e deletar o contato.
        }
    }

    printf("Contato não encontrado!\n"); // Exibe uma mensagem informando que o contato não foi encontrado na agenda.
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

#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX_CONTATOS 255
#define TAMANHO_NOME 50
#define TAMANHO_SOBRENOME 50
#define TAMANHO_EMAIL 50
#define TAMANHO_TELEFONE 15



typedef struct {
    char nome[TAMANHO_NOME];
    char sobrenome[TAMANHO_SOBRENOME];
    char email[TAMANHO_EMAIL];
    char telefone[TAMANHO_TELEFONE];
} Contato;

extern Contato agenda[MAX_CONTATOS]; // Declara um array externo de contatos com tamanho MAX_CONTATOS.
extern int num_contatos; // Declara uma variável externa para armazenar o número de contatos atualmente na agenda.

void adicionarContato(); // Protótipo da função para adicionar um novo contato.
void listarContatos(); // Protótipo da função para listar todos os contatos.
void deletarContato(); // Protótipo da função para deletar um contato existente.
void carregarAgenda(); // Protótipo da função para carregar a lista de contatos de um arquivo.
void salvarAgenda(); // Protótipo da função para salvar a agenda de contatos de um arquivo.
#endif

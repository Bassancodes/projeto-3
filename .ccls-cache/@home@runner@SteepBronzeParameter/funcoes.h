#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX_CONTATOS 255

typedef struct {
    char nome[50];
    char sobrenome[50];
    char email[100];
    char telefone[15];
} Contato;

extern Contato agenda[MAX_CONTATOS];
extern int num_contatos;

void adicionarContato();
void listarContatos();
void deletarContato();
void salvarAgenda();
void carregarAgenda();

#endif

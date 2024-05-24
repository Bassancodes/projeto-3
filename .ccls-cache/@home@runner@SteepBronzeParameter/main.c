#include <stdio.h>
#include "funcoes.h" // Inclui o arquivo de cabeçalho com as declarações das funções

int main() {
    int opcao; // Declaração da variável para armazenar a opção escolhida pelo usuário

    do { // Inicia um loop do-while para exibir o menu e receber a entrada do usuário
        // Exibe o menu de opções para o usuário
        printf("\nSelecione uma opção:\n");
        printf("1. Adicionar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Deletar contato\n");
        printf("4. Salvar agenda\n");
        printf("5. Carregar agenda\n");
        printf("0. Sair\n");
        printf("Opção: ");

        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário

        switch (opcao) { // Inicia um switch para executar a função correspondente à opção escolhida
            case 1:
                adicionarContato(); // Chama a função para adicionar um novo contato
                break;
            case 2:
                listarContatos(); // Chama a função para listar todos os contatos
                break;
            case 3:
                deletarContato(); // Chama a função para deletar um contato
                break;
            case 4:
                salvarAgenda(); // Chama a função para salvar a agenda em um arquivo binário
                break;
            case 5:
                carregarAgenda(); // Chama a função para carregar a agenda de um arquivo binário
                break;
            case 0:
                printf("Saindo\n"); // Exibe uma mensagem informando que o programa está saindo
                break;
            default:
                printf("Opção inválida!\n"); // Informa ao usuário que a opção escolhida é inválida
        }
    } while (opcao != 0); // Repete o loop enquanto a opção escolhida for diferente de 0 (Sair)

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}

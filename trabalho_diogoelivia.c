/*Considere que você foi contratado por uma empresa para desenvolver um sistema de controle de acervo de
livros. Esta empresa possui uma vasta biblioteca que é utilizada pelos seus funcionários. No entanto, todo o
controle sobre empréstimos, novas aquisições e baixa de exemplares é realizado de forma manual. O
responsável pela biblioteca precisa que você desenvolva um sistema para gerenciar o acervo de livros da
empresa. O sistema deverá permitir que sejam feitas as seguintes operações:
• Cadastro de novos exemplares;
• Cadastro de usuários da biblioteca;
• Controle de empréstimo e devolução de exemplares;
• Baixa de exemplares;
• Localização de exemplares por título, palavras-chave ou autor;
• Localização de usuários por nome.
O responsável pela biblioteca precisa que os seguintes dados sejam armazenados em relação aos livros:
título, editora, ano de publicação, autor(es) (no máximo três autores), número de páginas, edição, local da
publicação, palavras-chave e quantidade de exemplares. Para um efetivo controle do acervo também é
necessário que se tenha os seguintes dados dos usuários da biblioteca: nome, endereço, telefone para
contato, email, nº do crachá da empresa (identificação numérica), status (ativo, não ativo).
Além das funcionalidades especificadas acima o responsável pela biblioteca precisa que os seguintes
relatórios sejam gerados pelo sistema:
• Relatório de acervo;
• Relatório de usuários;
• Relatório de empréstimos;
• Relatório de pendências (livros emprestados e ainda não devolvidos na data prevista de devolução);
• Relatório de livros editados em uma determinada faixa de ano (Ex. 2020 a 2024).*/

#include <stdio.h>
#include <string.h>

#define STR_TAM 55
#define MAX_LIVROS 100
#define MAX_USUARIOS 100

typedef char string[STR_TAM];

// Estrutura para cadastro de exemplares
struct dados_exemplares {
    string titulo;
    string autor;
    int ano_publicacao;
    int num_paginas;
    string editora;
    int edicao;
    string local_publicacao;
    string palavras_chave;
    int qtd_exemplares;
};

// Estrutura para cadastro de usuários
struct dados_pessoa {
    string nome;
    string endereco;
    string telefone;
    string email;
    int cracha;
    int status; // 1 para ativo, 0 para não ativo
};

// Declaração dos arrays para armazenar os dados
struct dados_exemplares livros[MAX_LIVROS];
struct dados_pessoa usuarios[MAX_USUARIOS];
int qtd_livros = 0, qtd_usuarios = 0;

// Cabeçalho das funções
void cadastrarNovosExemplares();
void cadastrarNovoUsuario();
void controleEmprestimoDevolucao();
void baixaDeExemplares();
void localizacaoDeExemplares();
void localizacaoDeUsuarios();
void relatorioAcervo();
void relatorioUsuarios();
void relatorioEmprestimos();
void relatorioPendencias();
void relatorioLivrosEditados();

// Função principal
int main() {
    int opcao, subopcao;;

    do {
        printf("\nMenu Principal:\n");
        printf("1. Cadastrar novos exemplares\n2. Cadastrar novo usuário\n3. Controle de empréstimo e devolução\n4. Baixa de exemplares\n5. Localizar exemplares por título, palavras-chave ou autor\n6. Localização de usuários por nome\n7. Relatórios\n0. Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: cadastrarNovosExemplares(); break;
            case 2: cadastrarNovoUsuario(); break;
            case 3: controleEmprestimoDevolucao(); break;
            case 4: baixaDeExemplares(); break;
            case 5: localizacaoDeExemplares(); break;
            case 6: localizacaoDeUsuarios(); break;
            case 7:
                printf("\n1. Relatório de acervo\n2. Relatório de usuários\n3. Relatório de empréstimos\n4. Relatório de pendências\n5. Relatório de livros por ano\nEscolha uma opção: ");
                scanf("%d", &subopcao);
                getchar();
                switch (subopcao) {
                    case 1: relatorioAcervo(); break;
                    case 2: relatorioUsuarios(); break;
                    case 3: relatorioEmprestimos(); break;
                    case 4: relatorioPendencias(); break;
                    case 5: relatorioLivrosEditados(); break;
                    default: printf("Opção inválida.\n");
                }
                break;
            case 0: printf("Saindo do sistema...\n"); break;
            default: printf("Opção inválida!\n"); break;
        }
    } while (opcao != 0);

    return 0;
}

// Função para cadastrar novos exemplares
void cadastrarNovosExemplares() {
    if (qtd_livros < MAX_LIVROS) {
        printf("Título: ");
        fgets(livros[qtd_livros].titulo, STR_TAM, stdin);
        printf("Autor: ");
        fgets(livros[qtd_livros].autor, STR_TAM, stdin);
        printf("Ano de publicação: ");
        scanf("%d", &livros[qtd_livros].ano_publicacao);
        getchar();
        qtd_livros++;
        printf("Exemplar cadastrado com sucesso!\n");
    } else {
        printf("Limite de cadastro de livros atingido.\n");
    }
}

// Função para cadastrar novos usuários
void cadastrarNovoUsuario() {
    if (qtd_usuarios < MAX_USUARIOS) {
        printf("Nome: ");
        fgets(usuarios[qtd_usuarios].nome, STR_TAM, stdin);
        printf("Endereço: ");
        fgets(usuarios[qtd_usuarios].endereco, STR_TAM, stdin);
        printf("Telefone: ");
        fgets(usuarios[qtd_usuarios].telefone, STR_TAM, stdin);
        printf("Email: ");
        fgets(usuarios[qtd_usuarios].email, STR_TAM, stdin);
        printf("Crachá (ID): ");
        scanf("%d", &usuarios[qtd_usuarios].cracha);
        getchar();
        usuarios[qtd_usuarios].status = 1;
        qtd_usuarios++;
        printf("Usuário cadastrado com sucesso!\n");
    } else {
        printf("Limite de cadastro de usuários atingido.\n");
    }
}

// Funções de controle de empréstimo e relatórios devem ser implementadas a seguir.

void controleEmprestimoDevolucao()
{
    // Implementar a função para controle de empréstimo e devolução
}

void baixaDeExemplares()
{
    // Implementar a função para baixa de exemplares
}

void localizacaoDeExemplares()
{
    int i; 

    printf("Digite o título do livro para localizar: %s", livros[i].titulo);
    for (i = 0; i < qtd_livros; i++) {
        if(strcmp(livros[i].titulo, titulo) == 0) {
            return i;
        }
    }
}
void localizacaoDeUsuarios()
{
    // Implementar a função para localização de usuários
}

void relatorioAcervo()
{
    // Implementar a função para gerar o relatório de acervo
}

void relatorioUsuarios()
{
    // Implementar a função para gerar o relatório de usuários
}

void relatorioEmprestimos()
{
    // Implementar a função para gerar o relatório de empréstimos
}

void relatorioPendencias()
{
    // Implementar a função para gerar o relatório de pendências
}

void relatorioLivrosEditados()
{
    // Implementar a função para gerar o relatório de livros editados
}
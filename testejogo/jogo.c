#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "player_list.h"


#define LIMITE_NOME 20

int main() {
    setlocale(LC_ALL, "Portuguese");
    char nome[LIMITE_NOME];
    int opcao = 0;

  // Inicializando a lista encadeada.
  Lista personagens;
  inicializaLista(&personagens);

  Personagem *novo, *p; // declaração da variável fora do switch
  
  while (opcao != 6) {
      printf("\nEscolha uma opcao:\n");
      printf("1 - Adicionar Personagem\n");
      printf("2 - Remover Personagem\n");
      printf("3 - Buscar Personagem\n");
      printf("4 - Listar Personagens\n");
      printf("5 - Mudar Atributos\n");
      printf("6 - Sair\n");
      scanf("%d", &opcao);
  
      switch (opcao) {
          case 1:
              // Criando um ponteiro para um novo personagem e solicitando os dados ao usuário.
              novo = (Personagem*) malloc(sizeof(Personagem));
              
              leituraDadosPersonagem(novo); //chamando função para leitura dos dados do personagem
  
              // Chamando a função para inserir o personagem criado na lista.
              inserePersonagem(&personagens, novo);
              printf("\nPersonagem adicionado com sucesso.\n");
              break;
          case 2:
              // Solicitando o nome do personagem que deseja remover ao usuário.
              printf("Digite o nome do personagem que deseja remover: ");
              scanf("%s", nome);
  
              // Chamando a função para remover o personagem da lista.
              removePersonagem(&personagens, nome);
              break;
          case 3:
              // Solicitando o nome do personagem que deseja buscar ao usuário.
              printf("Digite o nome do personagem que deseja buscar: ");
              scanf("%s", nome);
  
              // Chamando a função para buscar o personagem na lista.
              p = buscaPersonagem(&personagens, nome);
              
              // Verificando se o personagem foi encontrado na lista.
              if (p == NULL) {
                  printf("\nPersonagem nao encontrado.\n");
              } else {
                  printf("\n%s - Nivel %d - XP %d - HP %d - MP %d - "
                         "F:%d | D:%d | C:%d | I:%d | S:%d | Ca:%d\n",
                         p->nome, p->nivel, p->experiencia, p->pontos_vida,
                         p->pontos_magia, p->forca, p->destreza, p->constituicao,
                         p->inteligencia, p->sabedoria, p->carisma);
              }
              break;
          case 4:
              // Chamando a função para imprimir todos os personagens da lista.
              imprimePersonagens(&personagens);
              break;
          case 5:
    // Solicitando o nome do personagem que deseja modificar atributos ao usuário.
    printf("Digite o nome do personagem que deseja modificar atributos: ");
    scanf("%s", nome);

    // Buscando o personagem na lista.
    Personagem *p = buscaPersonagem(&personagens, nome);

    // Verificando se o personagem foi encontrado na lista.
    if (p == NULL) {
        printf("\nPersonagem nao encontrado.\n");
    } else {
        int opcaoAtributo = 0;
        int novoValor = 0;

        printf("\nEscolha um atributo:\n");
        printf("1 - Nivel\n");
        printf("2 - Experiencia\n");
        printf("3 - Pontos de vida\n");
        printf("4 - Pontos de magia\n");
        printf("5 - Forca\n");
        printf("6 - Destreza\n");
        printf("7 - Constituicao\n");
        printf("8 - Inteligencia\n");
        printf("9 - Sabedoria\n");
        printf("10 - Carisma\n");
        scanf("%d", &opcaoAtributo);

        switch (opcaoAtributo) {
            case 1:
                printf("Digite o novo nivel: ");
                scanf("%d", &novoValor);
                p->nivel = novoValor;
                printf("Nivel atualizado com sucesso!\n");
                break;
            case 2:
                printf("Digite a nova quantidade de experiencia: ");
                scanf("%d", &novoValor);
                p->experiencia = novoValor;
                printf("Quantidade de experiencia atualizada com sucesso!\n");
                break;
            case 3:
                printf("Digite a nova quantidade de pontos de vida: ");
                scanf("%d", &novoValor);
                p->pontos_vida = novoValor;
                printf("Quantidade de pontos de vida atualizada com sucesso!\n");
                break;
            case 4:
                printf("Digite a nova quantidade de pontos de magia: ");
                scanf("%d", &novoValor);
                p->pontos_magia = novoValor;
                printf("Quantidade de pontos de magia atualizada com sucesso!\n");
                break;
            case 5:
                printf("Digite a nova forca: ");
                scanf("%d", &novoValor);
                p->forca = novoValor;
                printf("Forca atualizada com sucesso!\n");
                break;
            case 6:
                printf("Digite a nova destreza: ");
                scanf("%d", &novoValor);
                p->destreza = novoValor;
                printf("Destreza atualizada com sucesso!\n");
                break;
            case 7:
                printf("Digite a nova constituicao: ");
                scanf("%d", &novoValor);
                p->constituicao = novoValor;
                printf("Constituicao atualizada com sucesso!\n");
                break;
            case 8:
                printf("Digite a nova inteligencia: ");
                scanf("%d", &novoValor);
                p->inteligencia = novoValor;
                printf("Inteligencia atualizado com sucesso!\n");
                break;
            case 9:
                printf("Digite a nova sabedoria: ");
                scanf("%d", &novoValor);
                p->sabedoria = novoValor;
                printf("Sabedoria atualizada com sucesso!\n");
                break;
            case 10:
                printf("Digite o novo carisma: ");
                scanf("%d", &novoValor);
                p->carisma = novoValor;
                printf("Carisma atualizado com sucesso!\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    }
        
    break;
          case 6:
              printf("\nObrigado por jogar!\n");
              break;
          default:
              printf("\nOpcao invalida!\n");
              break;
      }
  }
  
  return 0;
}
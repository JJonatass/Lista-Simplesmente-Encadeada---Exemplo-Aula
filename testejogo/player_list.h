#ifndef PLAYER_LIST_H_INCLUDED
#define PLAYER_LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura do Personagem.
typedef struct {
    char nome[20];
    int nivel;
    int experiencia;
    int pontos_vida;
    int pontos_magia;
    int forca;
    int destreza;
    int constituicao;
    int inteligencia;
    int sabedoria;
    int carisma;
} Personagem;

// Definindo a estrutura da Lista Simplesmente Encadeada.
typedef struct noLista {
    Personagem *p;  // Ponteiro para a struct do personagem.
    struct noLista *prox;  // Ponteiro para o próximo elemento da lista.
} NoLista;

// Definindo a estrutura da Lista Encadeada.
typedef struct {
    NoLista *inicio;  // Ponteiro para o primeiro elemento da lista.
    int tamanho;  // Tamanho atual da lista.
} Lista;

// Função que inicializa a lista encadeada.
void inicializaLista(Lista *lista);

// Função que insere um novo personagem na lista.
void inserePersonagem(Lista *lista, Personagem *p);

// Função que remove um personagem da lista.
void removePersonagem(Lista *lista, char *nome);

// Função que busca um personagem pelo nome.
Personagem* buscaPersonagem(Lista *lista, char *nome);

// Função que imprime todos os personagens da lista.
void imprimePersonagens(Lista *lista);

// Função que modifica dados de um personagem existente.
void modificarPersonagem(Lista *lista, char *nome);

//ler dados inseridos pelo usuário
void leituraDadosPersonagem(Personagem *personagem);

#endif // PLAYER_LIST_H_INCLUDED

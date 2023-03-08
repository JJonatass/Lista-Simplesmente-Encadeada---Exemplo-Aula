#include "player_list.h"
#include <locale.h>


// Função que inicializa a lista encadeada.
void inicializaLista(Lista *lista) {
    lista->inicio = NULL; // O início da lista se torna nulo.
    lista->tamanho = 0; // O tamanho da lista é definido para 0.
}

// Função que insere um novo personagem na lista.
void inserePersonagem(Lista *lista, Personagem *p) {
    NoLista *noNovo = (NoLista*) malloc(sizeof(NoLista)); // Cria-se um novo nó para a lista.

    // Verifica se a alocação de memória foi bem-sucedida.
    if (noNovo == NULL) {
        printf("Erro: nao foi possivel alocar memoria.\n");
        return;
    }

    noNovo->p = p; // Dados do personagem são adicionados ao nó.
    noNovo->prox = NULL; // Próximo elemento aponta para nulo.

    // Verificar se a lista está vazia e inserir na primeira posição se necessário.
    if (lista->inicio == NULL) {
        lista->inicio = noNovo;
    }
    // Caso contrário, percorre-se a lista até encontrar o último elemento e insere o novo nó ao final.
    else {
        NoLista *atual = lista->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = noNovo;
    }

    lista->tamanho++; // Incrementa o tamanho da lista.
}

// Função que remove um personagem da lista.
void removePersonagem(Lista *lista, char *nome) {
    NoLista *anterior = NULL;
    NoLista *atual = lista->inicio;

    // Verifica se há algum elemento a ser removido.
    if (atual == NULL) {
        printf("Erro: Lista vazia\n");
        return;
    }

    // Percorre a lista até encontrar o elemento a ser removido.
    while (atual != NULL && strcmp(atual->p->nome, nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    // Verifica se o elemento foi encontrado.
    if (atual == NULL) {
        printf("Erro: Personagem não encontrado\n");
        return;
    }

    // Remove o elemento e ajusta os ponteiros.
    if (anterior == NULL) { // Elemento a ser removido é o primeiro da lista.
        lista->inicio = atual->prox;
    } else { // Elemento a ser removido não é o primeiro da lista.
        anterior->prox = atual->prox;
    }

    free(atual->p); // Libera o espaço em memória alocado para o elemento.
    free(atual);
    lista->tamanho--; // Decremento o tamanho da lista.
}

// Função que busca um personagem pelo nome.
Personagem* buscaPersonagem(Lista *lista, char *nome) {
    // Verifica se a lista está vazia.
    if (lista == NULL || lista->inicio == NULL)
        return NULL;

    // Procura o personagem na lista.
    NoLista *noAtual = lista->inicio;
    while (noAtual != NULL && strcmp(noAtual->p->nome, nome) != 0)
        noAtual = noAtual->prox;

    // Retorna o personagem encontrado ou NULL caso não encontre.
    if (noAtual == NULL)
        return NULL;
    else
        return noAtual->p;
}

void modificaAtributo(Personagem *p, char *atributo, int valor) {
    if (strcmp(atributo, "nivel") == 0) {
        p->nivel = valor;
    } else if (strcmp(atributo, "experiencia") == 0) {
        p->experiencia = valor;
    } else if (strcmp(atributo, "pontos_vida") == 0) {
        p->pontos_vida = valor;
    } else if (strcmp(atributo, "pontos_magia") == 0) {
        p->pontos_magia = valor;
    } else if (strcmp(atributo, "forca") == 0) {
        p->forca = valor;
    } else if (strcmp(atributo, "destreza") == 0) {
        p->destreza = valor;
    } else if (strcmp(atributo, "constituicao") == 0) {
        p->constituicao = valor;
    } else if (strcmp(atributo, "inteligencia") == 0) {
        p->inteligencia = valor;
    } else if (strcmp(atributo, "sabedoria") == 0) {
        p->sabedoria = valor;
    } else if (strcmp(atributo, "carisma") == 0) {
        p->carisma = valor;
    } else {
        printf("Erro: atributo nao existe\n");
    }
}

void imprimePersonagens(Lista *lista) {
    setlocale(LC_ALL, "Portuguese");
    if (lista->tamanho == 0) {
        printf("Lista vazia!\n");
    } else {
        NoLista *paux = lista->inicio;
        
        while (paux != NULL) {
            printf("Nome: %s\n", paux->p->nome);
            printf(" - Nivel: %d\n", paux->p->nivel);
            printf(" - Experiencia: %d\n", paux->p->experiencia);
            printf(" - Pontos de Vida: %d\n", paux->p->pontos_vida);
            printf(" - Pontos de Magia: %d\n", paux->p->pontos_magia);
            printf(" - Forca: %d\n", paux->p->forca);
            printf(" - Destreza: %d\n", paux->p->destreza);
            printf(" - Constituicao: %d\n", paux->p->constituicao);
            printf(" - Inteligencia: %d\n", paux->p->inteligencia);
            printf(" - Sabedoria: %d\n", paux->p->sabedoria);
            printf(" - Carisma: %d\n\n", paux->p->carisma);
            
            paux = paux->prox;
        }
    }
}

void leituraDadosPersonagem(Personagem *personagem) {
    printf("Digite o nome do personagem: ");
    scanf("%s", personagem->nome);
    printf("Digite o nivel do personagem: ");
    scanf("%d", &personagem->nivel);
    printf("Digite a quantidade de experiencia do personagem: ");
    scanf("%d", &personagem->experiencia);
    printf("Digite a quantidade de pontos de vida do personagem: ");
    scanf("%d", &personagem->pontos_vida);
    printf("Digite a quantidade de pontos de magia do personagem: ");
    scanf("%d", &personagem->pontos_magia);
    printf("Digite a forca do personagem: ");
    scanf("%d", &personagem->forca);
    printf("Digite a destreza do personagem: ");
    scanf("%d", &personagem->destreza);
    printf("Digite a constituicao do personagem: ");
    scanf("%d", &personagem->constituicao);
    printf("Digite a inteligencia do personagem: ");
    scanf("%d", &personagem->inteligencia);
    printf("Digite a sabedoria do personagem: ");
    scanf("%d", &personagem->sabedoria);
    printf("Digite o carisma do personagem: ");
    scanf("%d", &personagem->carisma);
}


#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista duplamente encadeada
struct no {
    int dados;
    struct no* prox;
    struct no* ant;
};

typedef struct no lista;

// Estrutura da fila
struct fila {
    lista* head;
    lista* tail;
};

typedef struct fila fila;

// Função para criar uma fila duplamente encadeada
fila* cria_fila(void) {
    fila* f = (fila*)malloc(sizeof(fila));
    f->head = NULL;
    f->tail = NULL;
    return f;
}

// Função para inserir um elemento na fila (no final)
void fila_insere(fila* f, int x) {
    lista* novo = (lista*)malloc(sizeof(lista));
    novo->dados = x;
    novo->prox = NULL;
    novo->ant = f->tail;

    if (f->tail != NULL) {
        f->tail->prox = novo;
    } else {
        // Se a fila estava vazia, o novo nó também é o primeiro nó (head)
        f->head = novo;
    }
    f->tail = novo;
}

// Função para remover o primeiro elemento da fila (do início)
void fila_retira(fila* f) {
    if (f->head == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    lista* aux = f->head;
    f->head = f->head->prox;

    if (f->head != NULL) {
        f->head->ant = NULL;  // O novo head não tem anterior
    } else {
        f->tail = NULL;  // Se a fila ficou vazia, o tail também é NULL
    }

    free(aux);
}

// Função para liberar a memória da fila
void fila_libera(fila* f) {
    lista* aux = f->head;
    while (aux != NULL) {
        lista* prox = aux->prox;
        free(aux);
        aux = prox;
    }
    free(f);
}

// Função para imprimir os elementos da fila
void fila_imprime(fila* f) {
    lista* aux = f->head;
    while (aux != NULL) {
        printf("%d ", aux->dados);
        aux = aux->prox;
    }
    printf("\n");
}

// Função principal para testar a fila
int main() {
    fila* f = cria_fila();
    fila_insere(f, 10);
    fila_insere(f, 20);
    fila_insere(f, 30);

    fila_imprime(f);  // Saída: 10 20 30

    fila_retira(f);   // Remove o primeiro elemento (10)
    fila_imprime(f);  // Saída: 20 30

    fila_libera(f);   // Libera a memória alocada
    return 0;
}

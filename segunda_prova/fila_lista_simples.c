#include <stdio.h>
#include <stdlib.h>

struct no{
    int dados;
    struct no* prox;
};

typedef struct no lista;

struct fila{
    lista* head;
    lista* tail;
};

typedef struct fila fila;

fila* cria_fila(void){
    fila* f = (fila*)malloc(sizeof(fila));
    f->head = NULL;
    f->tail = NULL;
}

void fila_insere(fila* f, int x){
    lista* novo = (lista*)malloc(sizeof(lista));
    novo->dados = x;
    novo->prox = NULL;
    if(f->head == NULL){
        f->head = novo;
    } else {
        f->tail->prox = novo;
    }
    f->tail = novo;
}

void fila_retira(fila* f){
    lista* aux;
    if(f->head == NULL){
        printf("Fila vazia!\n");
        return;
    }
    aux = f->head;
    f->head = f->head->prox;
    if(f->head == NULL){ // Verifica se a lista ficou vazia
        f->tail = NULL;
    }
    free(aux);
}

void fila_libera(fila* f){
    lista* aux = f->head;
    while(aux != NULL){
        lista* aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(f);
}

/*
void fila_imprime(fila* f){
    lista* aux = f->head;
    while(aux != NULL){
        printf("%d ", aux->dados);
        aux = aux->prox;
    }
    printf("\n");
}*/   

int main(){
    fila* f = cria_fila();
    fila_insere(f, 10);
    fila_insere(f, 20);
    fila_insere(f, 30);
    fila_imprime(f);
    fila_retira(f);
    fila_imprime(f);
    fila_libera(f);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

struct no {
    int dados;
    struct no* prox;
    struct no* ant;    
};

struct ld {
    struct no* li;
    struct no *lf;
}lista;

//Cria a lista vazia
void cria_lista(){
    lista.li = NULL;
    lista.lf = NULL;
}

//Insere no inicio
void insere(int n){
    struct no* novo;
    novo = (struct no*)malloc(sizeof(struct no));
    if (novo){ // Se o malloc funcionar
        novo->dados = n;
        novo->ant = 0;
        novo->prox = lista.li;

        if(lista.li != 0){ // Se a lista não estiver vazia
            novo->prox->ant = novo;
            //lista.li -> ant = novo;
            lista.li = novo;
        }else { 
            lista.li = novo;
            lista.lf = novo;
        }
        

    }
}

//Remove do inicio
void remove_inicio(struct ld *lista){
    struct no* aux;
    if(lista->li){//Se a lista não for vazia
        aux = lista->li;
        if(aux -> prox == 0){//Se for somente um elemento
            lista->li = 0;
            lista->lf = 0;
        }else{
            aux->prox->ant = 0;
            lista->li = aux->prox;
        }

    }
}

//Imprime
void imprime(struct ld lista){
    struct no* aux;
    aux = lista.li;
    while(aux != 0){
        printf("%d\n",aux->dados);
        aux = aux->prox;
    }
}

void procura(struct ld lista, int n){
    struct no* aux;
    for(aux = lista.li; aux != 0; aux = aux->prox){
        if(aux->dados == n){
            printf("Elemento encontrado\n");
            return;
        }
    }
    printf("Elemento nao encontrado\n");
}

int main(){
    cria_lista();
    insere(10);
    insere(20);
    insere(30);
    imprime(lista);
    procura(lista,20);
    remove_inicio(&lista);
    imprime(lista);
}
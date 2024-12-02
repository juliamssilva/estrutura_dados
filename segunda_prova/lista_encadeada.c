#include <stdio.h>
#include <stdlib.h>

//Estrutura de lista encadeada
struct no {
    int dados;
    struct no* prox;
};

typedef struct no ll;

//Criar a lista vazia
ll* cria_lista(void) {
    return NULL;
}

//Insere no início
ll* insere(ll* lista, int dado) {
    ll* novo = (ll*)malloc(sizeof(ll));
    novo->dados = dado;
    novo->prox = lista;
    return novo;
}

//Imprimir a lista circular
void imprimi_circular(ll* lista) {
    ll* aux = lista;
    if (lista != 0) {
        do {
            printf("%d\n", aux->dados);
            aux = aux->prox;
        } while (aux != lista);
    }
}

//Insere de forma ordenada
ll* insere_ordenado(ll* lista, int n) {
    ll* novo = (ll*)malloc(sizeof(ll));
    ll* ant = NULL;
    ll* aux = lista;

    //Procura a posição para inserir 
    while (aux != NULL && aux->dados < n) {
        ant = aux;
        aux= aux->prox;
    }

    //Cria o novo elemento
    novo->dados = n;

    if (ant == NULL) { // Se a lista estiver vazia ou se o novo elemento deve ser inserido no início
        novo->prox = lista;
        lista = novo;
    } else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return lista;
}

//Imprimir a lista
void imprime(ll* lista) {
    ll* aux = lista;
    while (aux != 0) {
        printf("%d\n", aux->dados);
        aux = aux->prox;
    }
}

//Verifica se a lista está vazia
int eh_vazia(ll* lista) {
    return (lista == 0);
}

//Procura um elemento na lista 
ll* busca(ll* lista, int n) {
    ll* aux;
    for (aux = lista; aux != 0; aux = aux->prox) {
        if (aux->dados == n) return aux;
    }
    return 0; // Caso não ache o elemento
}

//Remover um elemento da lista
void remove_elementos(ll** lista, int n) {
    ll* aux = *lista;
    ll* ant = NULL;

    //Percorre a lista e para um antes do dado (caso seja encontrado)
    while (aux != NULL && aux->dados != n) {
        ant = aux;
        aux = aux->prox; // faz o aux ser o dado a ser removido
    }

    if (aux == NULL) return; //Caso não ache o dado devolve a lista original
    
    if (ant == NULL) { // Se o elemento a ser removido for o primeiro
        *lista = aux->prox;
    } else {
        ant->prox = aux->prox;
    }
    free(aux);
}

int main() {
    ll* Lista = cria_lista();
    Lista = insere(Lista, 10);
    Lista = insere(Lista, 20);
    Lista = insere_ordenado(Lista, 15);
    Lista = insere(Lista, 30);
    
    imprime(Lista); // Imprime a lista original
    
    printf("Removendo o elemento 20...\n");
    remove_elementos(&Lista, 20); // Remove o elemento 20
    
    imprime(Lista); // Imprime a lista após a remoção

    return 0;
}



//Outra forma de  inserir elementos na lista
/*void insere (ll **lista, int dado){
    ll* novo = (ll*)malloc(sizeof(ll));
    novo->dados = dado;
    novo->prox = *lista;
    *lista = novo;
}*/
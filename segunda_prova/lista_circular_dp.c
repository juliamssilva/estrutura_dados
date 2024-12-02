#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista duplamente encadeada circular
struct no {
    int dados;
    struct no* prox;
    struct no* ant;
};

typedef struct no lista;

// Função para criar um novo nó
lista* cria_no(int x) {
    lista* novo = (lista*)malloc(sizeof(lista));
    novo->dados = x;
    novo->prox = novo;  // Inicialmente, o nó aponta para si mesmo (circular)
    novo->ant = novo;   // O nó também aponta para si mesmo no campo anterior
    return novo;
}

// Função para inserir um elemento no final da lista circular
lista* insere(lista* tail, int x) {
    lista* novo = cria_no(x);
    
    if (tail == NULL) {
        return novo;  // Se a lista está vazia, o novo nó é o único nó
    }
    
    // Inserir após o tail (último elemento)
    novo->prox = tail->prox;  // O novo nó aponta para o primeiro (head)
    novo->ant = tail;         // O anterior do novo nó é o tail
    tail->prox->ant = novo;   // O antigo primeiro nó (head) aponta para o novo
    tail->prox = novo;        // Tail aponta para o novo nó

    return novo;  // Retorna o novo tail
}

// Função para remover o primeiro elemento (head) da lista
lista* remove_inicio(lista* tail) {
    if (tail == NULL) {
        printf("Lista vazia!\n");
        return NULL;
    }

    lista* head = tail->prox;
    
    if (head == tail) {  // Caso onde a lista só tem um nó
        free(head);
        return NULL;
    }

    tail->prox = head->prox;       // Tail aponta para o novo head
    head->prox->ant = tail;        // O novo head aponta para o tail
    free(head);                    // Remove o antigo head

    return tail;
}

// Função para imprimir a lista circular duplamente encadeada
void imprime(lista* tail) {
    if (tail == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    lista* aux = tail->prox;  // Começa pelo head (próximo do tail)
    do {
        printf("%d ", aux->dados);
        aux = aux->prox;
    } while (aux != tail->prox);  // Continua até voltar ao head
    printf("\n");
}

// Função para liberar toda a lista
void libera(lista* tail) {
    if (tail == NULL) return;

    lista* aux = tail->prox;  // Começa pelo head
    do {
        lista* temp = aux;
        aux = aux->prox;
        free(temp);
    } while (aux != tail->prox);

    free(tail);  // Finalmente libera o tail
}

// Função principal para testar a lista duplamente encadeada circular
int main() {
    lista* tail = NULL;

    // Inserindo elementos na lista circular
    tail = insere(tail, 10);
    tail = insere(tail, 20);
    tail = insere(tail, 30);
    imprime(tail);  // Saída: 10 20 30

    // Removendo o primeiro elemento (head)
    tail = remove_inicio(tail);
    imprime(tail);  // Saída: 20 30

    // Removendo o primeiro elemento novamente
    tail = remove_inicio(tail);
    imprime(tail);  // Saída: 30

    // Liberando a lista
    libera(tail);

    return 0;
}

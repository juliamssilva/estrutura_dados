#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct pilha {
    int vetor[MAX];
    int t;
};

typedef struct pilha pilha;

pilha* cria_pilha() {
    pilha* p = (pilha*)malloc(sizeof(pilha));
    p->t = -1;
    return p;
} 

void push(pilha* p, int x) {
    if (p->t == MAX-1) {
        printf("Pilha cheia!\n");
        return;
    }
    p->t++;
    p->vetor[p->t] = x;
}

void pop(pilha* p) {
    int v;
    if (p->t == -1) {
        printf("Pilha vazia!\n");
        return;
    }
    v = p->vetor[p->t--];
    p->t--;
    return v;
}

void imprime(pilha* p) {
    int i;
    for (i = 0; i <= p->t; i++) {
        printf("%d ", p->vetor[i]);
    }
    printf("\n");
}

int main(){
    pilha* p = cria_pilha();
    push(p, 10);
    push(p, 20);
    push(p, 30);
    imprime(p);
    pop(p);
    imprime(p);
    return 0;
}

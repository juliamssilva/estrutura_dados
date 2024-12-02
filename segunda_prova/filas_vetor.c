#include <stdio.h>
#include <stdlib.h>

struct fila {
    int dados[10];
    int head;
    int tail;
};

typedef struct fila fila;

fila* cria_fila() {
    fila* f = (fila*)malloc(sizeof(fila));
    f->head = 0;  // inicia a fila vazia
    f->tail = 0;  // inicia a fila vazia
    return f;
}

void insere(fila* f, int x) {
    if (f->tail == 10) {  // Verifica se a fila está cheia
        printf("Fila cheia!\n");
        return;
    }
    f->dados[f->tail] = x;
    f->tail++;  // Atualiza a posição da cauda
}

int fila_retira(fila* f) {
    if (f->head == f->tail) {  // Verifica se a fila está vazia
        printf("Fila vazia!\n");
        return -1;
    }
    int x = f->dados[f->head];
    f->head++;  // Atualiza a posição da cabeça
    return x;
}

int fila_vazia(fila* f) {
    return f->head == f->tail;  // Fila está vazia se head == tail
}

void print_fila(fila* f) {
    for (int i = f->head; i < f->tail; i++) {
        printf("%d ", f->dados[i]);
    }
    printf("\n");
}

int main() {
    fila* f = cria_fila();
    insere(f, 10);
    insere(f, 20);
    insere(f, 30);
    print_fila(f);  // imprime os elementos da fila
    fila_retira(f);
    print_fila(f);  // imprime os elementos da fila após a remoção
    return 0;
}

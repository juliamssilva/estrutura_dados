#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // Tamanho máximo da pilha

// Estrutura de uma pilha
struct pilha {
    int dados[MAX];
    int topo;
};

typedef struct pilha pilha;

// Função para criar uma pilha
pilha* cria_pilha() {
    pilha* p = (pilha*)malloc(sizeof(pilha));
    p->topo = -1;
    return p;
}

// Função para verificar se a pilha está vazia
int pilha_vazia(pilha* p) {
    return p->topo == -1;
}

// Função para verificar se a pilha está cheia
int pilha_cheia(pilha* p) {
    return p->topo == MAX - 1;
}

// Função para empilhar um elemento
void empilha(pilha* p, int x) {
    if (pilha_cheia(p)) {
        printf("Erro: pilha cheia!\n");
        return;
    }
    p->dados[++p->topo] = x;
}

// Função para desempilhar um elemento
int desempilha(pilha* p) {
    if (pilha_vazia(p)) {
        printf("Erro: pilha vazia!\n");
        return -1;
    }
    return p->dados[p->topo--];
}

// Função para realizar a operação matemática
int opera(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default:
            printf("Erro: operador desconhecido '%c'\n", op);
            return -1;
    }
}

// Função para avaliar uma expressão pós-fixada
int avalia_expressao(const char* exp) {
    pilha* p = cria_pilha();
    int i = 0;
    while (exp[i] != '\0') {
        if (exp[i] >= '0' && exp[i] <= '9') {
            // Converte o caractere para número inteiro e empilha
            int num = 0;
            while (exp[i] >= '0' && exp[i] <= '9') {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            empilha(p, num);
        } else if (exp[i] == ' ') {
            // Ignora espaços
            i++;
        } else {
            // Assume que é um operador e realiza a operação
            int b = desempilha(p);
            int a = desempilha(p);
            int resultado = opera(a, b, exp[i]);
            empilha(p, resultado);
            i++;
        }
    }
    int resultado_final = desempilha(p);
    free(p);
    return resultado_final;
}

// Função principal
int main() {
    char expressao[MAX];

    printf("Digite a expressão pós-fixada (terminada com \\n): ");
    fgets(expressao, MAX, stdin);

    // Remove o caractere de nova linha no final
    expressao[strcspn(expressao, "\n")] = '\0';

    int resultado = avalia_expressao(expressao);
    printf("Resultado: %d\n", resultado);

    return 0;
}

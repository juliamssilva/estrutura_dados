#include <stdio.h>
#include <stdlib.h>

//Vamos imaginar isso como uma fila de brinquedos

struct no // criando um novo tipo de brinquedo no 
{
    int num; // guarda o número do brinquedo 
    struct no* prox; // como a mão do brinquedo que segura o próximo brinquedo
    
}*l; //  segura a mão do primeiro brinquedo da fila 

void adicionar_item(int numero){
    struct no* novo = (struct no*)malloc(sizeof(struct no)); // alocando memoria
    novo->num= numero; // colocando num no brinquedo
    novo->prox = NULL; //  não aponta para ninguém por enquanto

    if (l == NULL){ // se a lista estiver vazia
        l = novo; // brinquedo vai ser o primeiro da lista
    }else{
        struct no* aux = l; // aponta pro primeiro brinquedo da lista
        while(aux->prox != NULL){
            aux = aux->prox; // vai andando em todos os brinquedos da fila até achar o último
        }
        aux->prox = novo; // o último brinquedo segura o novo
        }
    }

 // Função para imprimir a lista
void imprimirLista(struct no* lista) {
    struct no* aux = lista; // Começamos a partir do primeiro brinquedo
    while (aux != NULL) { // Enquanto houver brinquedos na fila
        printf("%d ", aux->num); // Imprimimos o número do brinquedo
        aux = aux->prox; // Passamos para o próximo brinquedo
    }
    printf("\n");
}

// Função para liberar a memória da lista
void liberarLista(struct no** lista) {
    struct no* aux = *lista; // Começamos a partir do primeiro brinquedo
    while (aux != NULL) { // Enquanto houver brinquedos na fila
        struct no* temp = aux; // Guardamos o brinquedo atual
        aux = aux->prox; // Passamos para o próximo brinquedo
        free(temp); // Liberamos a memória do brinquedo atual
    }
    *lista = NULL; // Definimos a lista como vazia
}

int main(){

    l = NULL; // Inicialmente, a lista está vazia

    adicionar_item(1); // Adicionando o primeiro brinquedo
    adicionar_item(2); // Adicionando o segundo brinquedo
    adicionar_item(3); // Adicionando o terceiro brinquedo

    imprimirLista(l); // Imprimindo os números dos brinquedos na fila

    
    liberarLista(&l); // Liberando a memória usada pela fila

    return 0; // Indica que o programa terminou com sucesso
}
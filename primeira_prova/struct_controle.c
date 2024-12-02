#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5 

struct lista  
{
    int vetor[TAM];
    int contr;
};

void cria_lista (struct lista *vl){
    vl->contr = -1;
}

char esta_cheia (struct lista *vl)
{
    if (vl->contr == TAM -1){
        return 1;
    }else return 0;
};

char esta_vazia(struct lista *vl){

    if(vl->contr == -1) return 0;
    else return 1;
}


void esvaziar_lista (struct lista *vl){

    if (vl->contr != -1){
        vl->contr = -1;
    }
}

void inserir_fim (struct lista *vl){

    printf("Digite o valor: ");
    scanf("%d", &vl->vetor[(vl->contr)+1]);

    vl->contr += 1;
}

char consulta (struct lista *vl){
    if (vl->contr == -1) return 0;

    else{
        printf("Printando a lista\n");
        for (int i=0; i<(vl->contr)+1;i++){
            printf("%d\n", vl->vetor[i]);
        }
    }
};


int main(){

    struct lista l1;

    cria_lista(&l1); // Criando a lista

    printf("A lista esta vazia?\n ");

    if (esta_vazia(&l1)) printf("sim"); //Função que verifica estado da lista 
    else printf("nao\n");

    inserir_fim(&l1); // inserindo elementos na lista
    inserir_fim(&l1); 

    consulta(&l1);

    esvaziar_lista(&l1);

}
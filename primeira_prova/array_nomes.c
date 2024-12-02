#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char* ar[4];
    char str[20];
    int tam;

    //For para criar o array de ponteiros e caso dê errado liberar todos os espaços alocados
    for(int i = 0;i < 4;i++){
        ar[i] = (char*)malloc(20*sizeof(char));

        if(ar[i]==0){
            for(i=i-1;i>=0;i--){
                free(ar[i]);
            }
            return 1;
        }
    }

    // For para ler as string e armazenar no array de strings
    for(int i = 0;i < 4;i++){
        fgets(str,sizeof(str),stdin);

        tam = strlen(str);

        //Remove a nova linha 
        if(tam > 0 && str[tam - 1] == '\n'){
            str[tam - 1] = '\0';
        }

        strncpy(ar[i],str,20);

    }

    //Printa os nomes nas strings
    for(int i = 0; i < 4; i++){
        printf("Nome %d : %s\n", i+1, ar[i]);

    }

    // Libera a memória alocada
    for (int i = 0; i < 4; i++) {
        free(ar[i]);
    }

    return 0;

}

//cria loop lista e preenche a outra linha
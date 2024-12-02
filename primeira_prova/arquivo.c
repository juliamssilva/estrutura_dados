#include <stdio.h> 
#include <string.h> 

void main(){
    FILE *arq;
    char str[20];
    int age,num;

    arq = fopen("dados", "w");

    // Verifica se o arquivo pode ser aberto
    if (arq == NULL){
        printf("Arquivo não foi aberto");
        return;
    }else{
        printf("Arquivo foi aberto\n");
    }
    
    printf("Quantas pessoas serao inseridas: ");
    scanf("%d", &num);


//Le o nome e idade de n pessoas e salva em um arquivo
    for (int i = 0; i< num; i++){
        printf("Digite o nome e a idade: ");
        fscanf(stdin, "%s %d", str, &age); // lê do teclado

        fprintf(arq, "%s %d\n", str, age); //escreve no arquivo

    }

    fclose(arq);

//Le o arquivo e mostra na tela
    arq = fopen("dados", "r");
    if (arq == NULL){
        printf("Não foi possível abrir o arquivo para leitura");
        return;
    }

//Lê todos os nomes e idades das pessoas 18+
    for(int i = 0; i <num; i++){
        fscanf(arq, "%s %d", str, &age); //lê do arquivo 
        if (age > 18){
            fprintf(stdout, "%s %d\n", str, age);// printa
        }
    }

}
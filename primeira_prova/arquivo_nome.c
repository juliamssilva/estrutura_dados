#include <stdio.h> 
#include <string.h> 

void main(){
    FILE *arq;
    int idades[10];
    char linha[100];
    char nomes[10][80];
    int i = 0, j;
    char auxNome[80];
    int auxIdade;

    // Abrir o arquivo para leitura
      if ((arq = fopen("dados.txt", "r")) == NULL) {
         printf("O arquivo não pode ser aberto\n");
         return ;
   }

    // Leitura do arquivo
   while (fgets(linha, sizeof(linha), arq) && i < 10) {
      // Extrair nome e idade da linha lida
      if (scanf(linha, "%s %d", nomes[i], &idades[i]) == 2) {
         i++;
      }
    }

    // Fecha o arquivo
   fclose(arq);

    // Ordenação dos nomes e idades em ordem alfabética
   for (int k = 0; k < i - 1; k++) {
      for (j = k + 1; j < i; j++) {
         if (strcmp(nomes[k], nomes[j]) > 0) {
                // Troca os nomes
               strcpy(auxNome, nomes[k]);
               strcpy(nomes[k], nomes[j]);
               strcpy(nomes[j], auxNome);

               // Troca as idades correspondentes
               auxIdade = idades[k];
               idades[k] = idades[j];
               idades[j] = auxIdade;
         }
      }
   }

    // Exibir os nomes e idades ordenados
   for (int k = 0; k < i; k++) {
      printf("%s %d\n", nomes[k], idades[k]);
   }

   return;

}
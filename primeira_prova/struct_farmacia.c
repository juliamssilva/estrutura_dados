#include <stdio.h>
#include <string.h>

struct fabricante
{
    int cod;
    char nome_fabrica[30];
    char cnpj[13]; // pode ser int até 2026.
    char nome_vendedor[30];

}fabricou;


struct medicamento
{
    char nome_medicamento[30];
    char prin_ativo[30];
    struct fabricante* fabrica;
    
}farm;

//Criaria essa estrutura e armazenaria em um documento.
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

typedef struct{
    int ano;
    char codigoPpg[20];
    char paisDocente[30];
    char nome[100];
    char paisInstituicao[30];
    char sexo[15];
} cedulasDocentes;

typedef struct{
    cedulasProgs *linha;
} matrizProgs;

matrizProgs *matriz  = malloc(sizeof(cedulasProgs) * 1);
m->linha = malloc(sizeof(cedulasProgs) * 100);


m->linha[2].ano = 2005;

printf("%d", &m->linha[1].ano);
}
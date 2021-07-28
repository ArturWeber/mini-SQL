#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int ano;
    char codigoPpg[20];
    char paisDocente[30];
    char nome[100];
    char paisInstituicao[30];
    char sexo[15];
} cedulasDocentes;

typedef struct {
    char nomeInstituicao[150];
    char codigoPrograma[20];
    int nivel; 
    char siglaInstituicao[30];
    char doutorado[10];
    char nomeCurso[150];
    char nomeAvaliacao[150];
} cedulasProgs;

typedef struct {
    int ano;
    char autor[150];
    char codigoPpg[20];
    char idioma[15];
    char nomeOrientador[150];
} cedulasTrabalhos;

typedef struct{
    cedulasDocentes *linhaDocentes;
    cedulasProgs *linhaProgs;
    cedulasTrabalhos *linhaTrabalhos;
} matrizes;

/*
int numeroLinhas(FILE *arquivo){
    arquivo = fopen("arquivo","r");
    int nl;
    char p;
    char letra = '\n';

    while(fgets (&p,  500, arquivo)) {
        nl++;
    } 
    fclose(arquivo);
    return nl;
}

int numeroLinhas('qual arquivo'){
}

FILE *arq;
    char c, letra = '\n';
    int vezes;
    arq = fopen("teste.txt","r");
        while(fread (&c, sizeof(char), 1, arq)) {
            if(c == letra) {
                vezes++;
            }
        } 
    printf("\nLinhas: %i\n",vezes + 1);
    fclose(arq);
*/

int main(int argc, char *argv[]) {




matrizes *vetorDocentes = malloc(sizeof(cedulasDocentes) * 1);
vetorDocentes->linhaDocentes = malloc(sizeof(cedulasDocentes) * nLinha('Docentes.tsv'));

matrizes *vetorProgs = malloc(sizeof(cedulasProgs) * 1);
vetorProgs->linhaProgs = malloc(sizeof(cedulasProgs) * nLinha('Progs.tsv'));

matrizes *vetorTrabalhos = malloc(sizeof(cedulasTrabalhos) * 1);
vetorTrabalhos->linhaTrabalhos = malloc(sizeof(cedulasTrabalhos) * nLinha('Trabalhos.tsv'));

}
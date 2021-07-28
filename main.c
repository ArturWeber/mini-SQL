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
} tabelas;

int numeroLinhas(FILE *arquivo){
    int nl = 0;
    char p;
    char letra = '\n';
        while(fread (&p, sizeof(char), 1, arquivo)) {
            if(p == letra) {
                nl++;
            }
        } 

    return nl;
}




int main(int argc, char *argv[]) {


    //abre arquivos 
    FILE *Docentes;
    Docentes = fopen("Docentes.tsv", "r");

    FILE *Progs;
    Progs = fopen("Progs.tsv", "r");

    FILE *Trabalhos;
    Trabalhos= fopen("Trabalhos.tsv", "r");

    
    //aloca structs 
    tabelas *vetorDocentes = malloc(sizeof(cedulasDocentes) * 1);
    vetorDocentes->linhaDocentes = malloc(sizeof(cedulasDocentes) * numeroLinhas(Docentes));

    tabelas *vetorProgs = malloc(sizeof(cedulasProgs) * 1);
    vetorProgs->linhaProgs = malloc(sizeof(cedulasProgs) * numeroLinhas(Progs));

    tabelas *vetorTrabalhos = malloc(sizeof(cedulasTrabalhos) * 1);
    vetorTrabalhos->linhaTrabalhos = malloc(sizeof(cedulasTrabalhos) * numeroLinhas(Trabalhos));









    //desaloca structs
    free(vetorTrabalhos->linhaTrabalhos);
    free(vetorTrabalhos);

    free(vetorProgs->linhaProgs);
    free(vetorProgs);

    free(vetorDocentes->linhaDocentes);
    free(vetorDocentes);

    
    //fecha arquivos
    fclose(Trabalhos);
    
    fclose(Progs);
    
    fclose(Docentes);





    /*ANOTACOES
    UM POR UM GUARDAR A ENTRADA
    PODE DAR ERRO NO NUMERO DE LINHAS (+1)
    NAO ARMAZENA PRIMEIRA LINHA??
    */
}
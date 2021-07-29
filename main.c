#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int AnodaTitulacao;
    char CodigodoPPG[20];
    char Nacionalidade[30];
    char Nome[100];
    char PaisdaInstituicao[30];
    char Sexo[15];
} cedulasDocentes;

typedef struct {
    char Instituicao[150];
    char Programa[20];
    int Nivel; 
    char Siglao[30];
    char TemDoutorado[10];
    char nome[150];
    char AreadeAvaliacao[150];
} cedulasProgs;

typedef struct {
    int Ano;
    char Autor[150];
    char CodigodoPPG[20];
    char Idioma[15];
    char Orientador[150];
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
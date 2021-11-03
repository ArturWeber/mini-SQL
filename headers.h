#ifndef __headers_h__
#define __headers_h__

#include <stdio.h>

//************************************************************ 
//                                                      Structs

//Struct arquivos docentes
typedef struct {
    int  DAnodaTitulacao;
    char DCodigodoPPG[20];
    char DNacionalidade[30];
    char DNome[100];
    char DPaisdaInstituicao[30];
    char DSexo[15];
} structDocentes;

//Struct arquivos programas
typedef struct {
    char PInstituicao[150];
    char PPrograma[20];
    int  PNivel; 
    char PSigla[30];
    char PTemDoutorado[10];
    char PNome[150];
    char PAreadeAvaliacao[150];
} structProgs;

//Struct arquivos trabalhos
typedef struct {
    int TAno;
    char TAutor[150];
    char TCodigodoPPG[20];
    char TIdioma[15];
    char TOrientador[150];
} structTrabalhos;

//************************************************************ 
//                                                     Funcoes

int separaEntrada(char *entradaPrimaria, char *vetorInicialWhere, char *vetorInicialFrom, char *vetorInicialSelect);

int calculaLinhas(FILE *arquivo);

void rewind(FILE *stream);

void lerDocentes(FILE *arquivo, structDocentes *vetorDocentes, int nLinhas);

void lerProgs(FILE *arquivo, structProgs *vetorProgs, int nLinhas);

void lerTrabalhos(FILE *arquivo, structTrabalhos *vetorTrabalhos, int nLinhas);

int calculamaior(int menu[18]);

int valorMenu(int tamanhoSelect, char *vetorInicialSelect, int menu[18]);

int verificaWhere(structDocentes *vetorDocentes, structProgs *vetorProgs,structTrabalhos *vetorTrabalhos, int menuWhere, char *vetorFerramenta, int i);

char *achaWhere(char *vetorInicialWhere, char *vetorFerramenta);

int funcaoWhere(char *vetorInicialWhere, int menuWhere);

void printarSaida(structDocentes *vetorDocentes, structProgs *vetorProgs,structTrabalhos *vetorTrabalhos,int menu[18], int nLinhasDocentes, int nLinhasProgs, int nLinhasTrabalhos,  int menuWhere, char *vetorFerramenta);

#endif
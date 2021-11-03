//************************************************************ 
//                                                  Declarações

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"


//************************************************************ 
//                                          Separa as entradas

int separaEntrada(char *entradaPrimaria, char *vetorInicialWhere, char *vetorInicialFrom, char *vetorInicialSelect) {
    
    //conta o tamanho total da entrada, isto é, o select + o from + o where
    int tamanhoEntrada = strlen(entradaPrimaria);

    char *token;

    //separa o where e conta tamanho dele, verificando se existe ou nao 
    char where[7] = " where ";
    
    token = strstr(entradaPrimaria, where);
    int tamanhoWhere;

    if (token != NULL){
        strcpy(vetorInicialWhere, token);
        tamanhoWhere = strlen(vetorInicialWhere);
    }
    else{
        tamanhoWhere = 0;
    }

    
    //cria uma entrada secundaria so com o select e o from lendo os n primeiros caracteres da entrada primaria
    char *entradaSecundaria = malloc(sizeof(char) * 400);
    strncpy(entradaSecundaria, entradaPrimaria, (tamanhoEntrada - tamanhoWhere));
    

    //separa o from e conta o tamanho dele, verificando se existe ou nao
    char from[6] = " from ";
    token = strstr(entradaSecundaria, from);
    int tamanhoFrom;
    if (token != NULL){
        strcpy(vetorInicialFrom, token);
        tamanhoFrom = strlen(vetorInicialFrom);
    }
    else{
        tamanhoFrom = 0;
    }

    
    //cria um vetor select usando os tamanhos calculados
    strncpy(vetorInicialSelect, entradaSecundaria, (tamanhoEntrada - tamanhoFrom - tamanhoWhere));

    //desaloca structs 
    free(entradaSecundaria);

    //retorna o tamanho do select que vai ser usado na hora da saida
    return (tamanhoEntrada - tamanhoFrom - tamanhoWhere);
}


//************************************************************ 
//                       Calcula o número de linhas do arquivo

int calculaLinhas(FILE *arquivo){
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
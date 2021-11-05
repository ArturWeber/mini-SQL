//************************************************************ 
//                                                  Declarações

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"


//************************************************************ 
//        Interpreta o vetor menu e exibe uma saída condizente

void printarSaida(structDocentes *vetorDocentes, structProgs *vetorProgs,structTrabalhos *vetorTrabalhos,int menu[18], int nLinhasDocentes, int nLinhasProgs, int nLinhasTrabalhos,  int menuWhere, char *vetorFerramenta){
  int maiormenu = calculamaior(menu);
  for (int i = 0; i < 150; i++){
        if(verificaWhere(vetorDocentes, vetorProgs, vetorTrabalhos, menuWhere, vetorFerramenta, i)){
            for (int j = 1; j < (maiormenu + 1); j++){
                //Verificando se a linha i existe ou nao
                if (i < (nLinhasDocentes - 1)){
                    if (menu[0] == j){
                        printf("%d", vetorDocentes[i].DAnodaTitulacao);
                        //Verificando se é a ultima linha impressa ou não
                        if (menu[0] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }
                    if (menu[1] == j){
                        printf("%s", vetorDocentes[i].DCodigodoPPG);
                        if (menu[1] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }
                    if (menu[2] == j){
                        printf("%s", vetorDocentes[i].DNacionalidade);
                        if (menu[2] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }
                    if (menu[3] == j){
                        printf("%s", vetorDocentes[i].DNome);
                        if (menu[3] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }
                    if (menu[4] == j){
                        printf("%s", vetorDocentes[i].DPaisdaInstituicao);
                        if (menu[4] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }
                    if (menu[5] == j){
                        printf("%s", vetorDocentes[i].DSexo);
                        if (menu[5] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }
                }
                
                if(i < (nLinhasProgs - 1)){
                    if (menu[6] == j){
                        printf("%s", vetorProgs[i].PInstituicao);
                        if (menu[6] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }
                    if (menu[7] == j){
                        printf("%s", vetorProgs[i].PPrograma);
                        if (menu[7] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }
                    if (menu[8] == j){
                        printf("%d", vetorProgs[i].PNivel);
                        if (menu[8] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }
                    if (menu[9] == j){
                        printf("%s", vetorProgs[i].PSigla);
                        if (menu[9] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }
                    if (menu[10] == j){
                        printf("%s", vetorProgs[i].PTemDoutorado);
                        if (menu[10] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }
                    if (menu[11] == j){
                        printf("%s", vetorProgs[i].PNome);
                        if (menu[11] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }
                    if (menu[12] == j){
                        printf("%s", vetorProgs[i].PAreadeAvaliacao);
                        if (menu[12] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }
                }
                if (i < (nLinhasTrabalhos - 1)){
                    if (menu[13] == j){
                        printf("%d", vetorTrabalhos[i].TAno);
                        if (menu[13] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }   
                    if (menu[14] == j){
                        printf("%s", vetorTrabalhos[i].TAutor);
                        if (menu[14] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }
                    if (menu[15] == j){
                        printf("%s", vetorTrabalhos[i].TCodigodoPPG);
                        if (menu[15] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }
                    if (menu[16] == j){
                        printf("%s", vetorTrabalhos[i].TIdioma);
                        if (menu[16] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }
                    if (menu[17] == j){
                        printf("%s", vetorTrabalhos[i].TOrientador);
                        if (menu[17] == maiormenu){
                            printf("\n");
                        }
                        else{
                            printf("\t");
                        }
                    }
                }  
            }
        }
    }
}

//Artur

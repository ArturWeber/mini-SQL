//************************************************************ 
//                                                  Declarações

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"


//************************************************************ 
//                 Retorna o ponteiro de arquivo para o início

void rewind(FILE *stream);


//************************************************************ 
//                                          Le tabela Docentes

void lerDocentes(FILE *arquivo, structDocentes *vetorDocentes, int nLinhas) {
    
    if(arquivo != NULL) {
        char *linhaAtual; 
        linhaAtual = malloc(sizeof(char) * 500);
        
        //primeiro fgets sem utilidade para poder nao ler o cabecalho
        fgets(linhaAtual, 500, arquivo);

        for (int j = 0; j < nLinhas; j++){
            fgets(linhaAtual, 500, arquivo);
            
            char *token = strtok(linhaAtual, "\t");
            int i = 0; 

            while (token != NULL){
                i++;
                switch(i){
                    case 1:
                        vetorDocentes[j].DAnodaTitulacao = atoi(token);
                        break;
                    case 2:
                        strcpy(vetorDocentes[j].DCodigodoPPG,token);
                        break;
                    case 3:
                        strcpy(vetorDocentes[j].DNacionalidade,token);
                        break;
                    case 4:
                        strcpy(vetorDocentes[j].DNome,token);
                        break;
                    case 5:
                        strcpy(vetorDocentes[j].DPaisdaInstituicao,token);
                        break;
                    case 6:
                        strcpy(vetorDocentes[j].DSexo,token);
                        //Tira o \n da ultima linha para nao dar problema na hora da saida 
                        int tamanhoSexo = strlen(vetorDocentes[j].DSexo);
                        vetorDocentes[j].DSexo[tamanhoSexo - 1] = '\0';
                        //Zera o i para ler a proxima linha 
                        i = 0;
                        break;
                }
                token = strtok(NULL, "\t");
            }
        }

        free(linhaAtual);
    }
}


//************************************************************ 
//                                         Le tabela Programas

void lerProgs(FILE *arquivo, structProgs *vetorProgs, int nLinhas) {
    
    if(arquivo != NULL) {
        char *linhaAtual; 
        linhaAtual = malloc(sizeof(char) * 500);
        
        //primeiro fgets sem utilidade para poder nao ler o cabecalho
        fgets(linhaAtual, 500, arquivo);

        for (int j = 0; j < (nLinhas - 1); j++){
            fgets(linhaAtual, 500, arquivo);
            
            char *token = strtok(linhaAtual, "\t");
            int i = 0; 

            while (token != NULL){
                i++;
                switch(i){
                    case 1:
                        strcpy(vetorProgs[j].PInstituicao,token);
                        break;
                    case 2:
                        strcpy(vetorProgs[j].PPrograma,token);
                        break;
                    case 3:
                        vetorProgs[j].PNivel = atoi(token);
                        break;
                    case 4:
                        strcpy(vetorProgs[j].PSigla,token);
                        break;
                    case 5:
                        strcpy(vetorProgs[j].PTemDoutorado,token);
                        break;
                    case 6:
                        strcpy(vetorProgs[j].PNome,token);
                        break; 
                    case 7:
                        strcpy(vetorProgs[j].PAreadeAvaliacao,token);
                        //Tira o \n da ultima linha para nao dar problema na hora da saida 
                        int tamanhoArea = strlen(vetorProgs[j].PAreadeAvaliacao);
                        vetorProgs[j].PAreadeAvaliacao[tamanhoArea - 1] = '\0';
                        //Zera o i para ler a proxima linha 
                        i = 0;
                        break;
                }
                
                token = strtok(NULL, "\t");
            }
        }

        free(linhaAtual);
    }
}


//************************************************************ 
//                                         Le tabela trabalhos

void lerTrabalhos(FILE *arquivo, structTrabalhos *vetorTrabalhos, int nLinhas) {
    
    if(arquivo != NULL) {
        char *linhaAtual; 
        linhaAtual = malloc(sizeof(char) * 500);

        //primeiro fgets sem utilidade para poder nao ler o cabecalho
        fgets(linhaAtual, 500, arquivo);

        for (int j = 0; j < (nLinhas - 1); j++){
            fgets(linhaAtual, 500, arquivo);
            
            char *token = strtok(linhaAtual, "\t");
            int i = 0; 

            while (token != NULL){
                i++;
                switch(i){
                    case 1:
                        vetorTrabalhos[j].TAno = atoi(token);
                        break;
                    case 2:
                        strcpy(vetorTrabalhos[j].TAutor,token);
                        break;
                    case 3:
                        strcpy(vetorTrabalhos[j].TCodigodoPPG,token);
                        break;
                    case 4:
                        strcpy(vetorTrabalhos[j].TIdioma,token);
                        break;
                    case 5:
                        strcpy(vetorTrabalhos[j].TOrientador,token);
                        //Tira o \n da ultima linha para nao dar problema na hora da saida 
                        int tamanhoOrientador = strlen(vetorTrabalhos[j].TOrientador);
                        vetorTrabalhos[j].TOrientador[tamanhoOrientador - 1] = '\0';
                        //Zera o i para ler a proxima linha 
                        i = 0;
                        break; 
                }
                token = strtok(NULL, "\t");
            }
        }
        free(linhaAtual);
    }
}


//************************************************************ 
//       Descobre qual o maior menu para ajudar no espaçamento 

int calculamaior(int menu[18]){
    int maior = 0;
    for(int h = 0; h < 18; h++){
        if ((menu[h] > 0) &&(menu[h] > maior)){
            maior = menu[h];
        }
    }
    return maior;
}


//************************************************************ 
//  Atribui valores para o vetor menu, que vai cuidar da saída

int valorMenu(int tamanhoSelect, char *vetorInicialSelect, int menu[18]){
  int j = 1;

  for (int a = 0; a < (tamanhoSelect); a++){
        if(vetorInicialSelect[a] == '.'){
            
            //verificam qual o documento 
            if (vetorInicialSelect[a - 2] == 'e'){

                //verificam qual a coluna
                if ((vetorInicialSelect[a + 1] == 'A') && (vetorInicialSelect[a + 2] == 'n')){
                    menu[0] = j;
                    j++;
                }
                if ((vetorInicialSelect[a + 1] == 'C') && (vetorInicialSelect[a + 2] == 'o')){
                    menu[1] = j;
                    j++;
                }
                if ((vetorInicialSelect[a + 1] == 'N') && (vetorInicialSelect[a + 2] == 'a')){
                    menu[2] = j;
                    j++;
                }
                if ((vetorInicialSelect[a + 1] == 'N') && (vetorInicialSelect[a + 2] == 'o')){
                    menu[3] = j;
                    j++;
                }
                if ((vetorInicialSelect[a + 1] == 'P') && (vetorInicialSelect[a + 2] == 'a')){
                    menu[4] = j;
                    j++;
                }
                if ((vetorInicialSelect[a + 1] == 'S') && (vetorInicialSelect[a + 2] == 'e')){
                    menu[5] = j;
                    j++;
                }
            }

            if (vetorInicialSelect[a - 2] == 'g'){
                if ((vetorInicialSelect[a + 1] == 'I') && (vetorInicialSelect[a + 2] == 'n')){
                    menu[6] = j;
                    j++;
                }
                if ((vetorInicialSelect[a + 1] == 'P') && (vetorInicialSelect[a + 2] == 'r')){
                    menu[7] = j;
                    j++;
                }
                if ((vetorInicialSelect[a + 1] == 'N') && (vetorInicialSelect[a + 2] == 'i')){
                    menu[8] = j;
                    j++;
                }
                if ((vetorInicialSelect[a + 1] == 'S') && (vetorInicialSelect[a + 2] == 'i')){
                    menu[9] = j;
                    j++;
                }
                if ((vetorInicialSelect[a + 1] == 'T') && (vetorInicialSelect[a + 2] == 'e')){
                    menu[10] = j;
                    j++;
                }
                if ((vetorInicialSelect[a + 1] == 'N') && (vetorInicialSelect[a + 2] == 'o')){
                    menu[11] = j;
                    j++;
                }
                if ((vetorInicialSelect[a + 1] == 'A') && (vetorInicialSelect[a + 2] == 'r')){
                    menu[12] = j;
                    j++;
                }
                
            }

            if (vetorInicialSelect[a - 2] == 'o'){
                if ((vetorInicialSelect[a + 1] == 'A') && (vetorInicialSelect[a + 2] == 'n')){
                    menu[13] = j;
                    j++;
                }
                if ((vetorInicialSelect[a + 1] == 'A') && (vetorInicialSelect[a + 2] == 'u')){
                    menu[14] = j;
                    j++;
                }
                if ((vetorInicialSelect[a + 1] == 'C') && (vetorInicialSelect[a + 2] == 'o')){
                    menu[15] = j;
                    j++;
                }
                if ((vetorInicialSelect[a + 1] == 'I') && (vetorInicialSelect[a + 2] == 'd')){
                    menu[16] = j;
                    j++;
                }
                if ((vetorInicialSelect[a + 1] == 'O') && (vetorInicialSelect[a + 2] == 'r')){
                    menu[17] = j;
                    j++;
                }
            }
        }
    }

    return 0;
}


//*************************************************************
//  Verifica quais linhas deve imprimir de acordo com o "Where"

int verificaWhere(structDocentes *vetorDocentes, structProgs *vetorProgs,structTrabalhos *vetorTrabalhos, int menuWhere, char *vetorFerramenta, int i){
    if (((vetorDocentes[i].DAnodaTitulacao == atoi(vetorFerramenta))&& menuWhere == 0)
    ||(!strcmp(vetorDocentes[i].DCodigodoPPG, vetorFerramenta)&& menuWhere == 1)
    ||(!strcmp(vetorDocentes[i].DNacionalidade, vetorFerramenta)&& menuWhere == 2)
    ||(!strcmp(vetorDocentes[i].DNome, vetorFerramenta)&& menuWhere == 3)
    ||(!strcmp(vetorDocentes[i].DPaisdaInstituicao, vetorFerramenta)&& menuWhere == 4)
    ||(!strcmp(vetorDocentes[i].DSexo, vetorFerramenta)&&menuWhere == 5)
    ||(!strcmp(vetorProgs[i].PInstituicao, vetorFerramenta) &&  menuWhere == 6)
    ||(!strcmp(vetorProgs[i].PPrograma, vetorFerramenta) && menuWhere == 7)
    ||((vetorProgs[i].PNivel == atoi(vetorFerramenta)) && menuWhere == 8)
    ||(!strcmp(vetorProgs[i].PSigla, vetorFerramenta) && menuWhere == 9)
    ||(!strcmp(vetorProgs[i].PTemDoutorado, vetorFerramenta) && menuWhere == 10)
    ||(!strcmp(vetorProgs[i].PNome, vetorFerramenta) && menuWhere == 11)
    ||(!strcmp(vetorProgs[i].PAreadeAvaliacao, vetorFerramenta) && menuWhere == 12)
    ||((vetorTrabalhos[i].TAno == atoi(vetorFerramenta)) && menuWhere == 13)
    ||(!strcmp(vetorTrabalhos[i].TAutor, vetorFerramenta) && menuWhere == 14)
    ||(!strcmp(vetorTrabalhos[i].TCodigodoPPG, vetorFerramenta) && menuWhere == 15)
    ||(!strcmp(vetorTrabalhos[i].TIdioma, vetorFerramenta) && menuWhere == 16)
    ||(!strcmp(vetorTrabalhos[i].TOrientador, vetorFerramenta) && menuWhere == 17)
    ||(menuWhere == -1)){
    return 1;
    }
    else {
        return 0;
    }
}


//**************************************************************
//  Separa a palavra indicada pelo "Where" e salva em uma string 

char *achaWhere(char *vetorInicialWhere, char *vetorFerramenta){
    char *token = strtok(vetorInicialWhere, "=");
    for(int i = 0; i< strlen(token)+3; i++){
        vetorInicialWhere++;
    }
    strncpy(vetorFerramenta, vetorInicialWhere,(strlen(vetorInicialWhere)-2));
    return vetorFerramenta;
}

//************************************************************
//                   identifica a coluna indicada pelo "Where" 
int funcaoWhere(char *vetorInicialWhere, int menuWhere){
    int tamanhoWhere = strlen(vetorInicialWhere);
    for (int a = 0; a < (tamanhoWhere); a++){
        if(vetorInicialWhere[a] == '.'){
            if (vetorInicialWhere[a - 2] == 'e'){
                if ((vetorInicialWhere[a + 1] == 'A') && (vetorInicialWhere[a + 2] == 'n')){
                    menuWhere = 0;
                }
                if ((vetorInicialWhere[a + 1] == 'C') && (vetorInicialWhere[a + 2] == 'o')){
                    menuWhere = 1;
                }
                if ((vetorInicialWhere[a + 1] == 'N') && (vetorInicialWhere[a + 2] == 'a')){
                    menuWhere = 2;
                    
                }
                if ((vetorInicialWhere[a + 1] == 'N') && (vetorInicialWhere[a + 2] == 'o')){
                   menuWhere = 3;
                }
                if ((vetorInicialWhere[a + 1] == 'P') && (vetorInicialWhere[a + 2] == 'a')){
                    menuWhere = 4;
                }
                if ((vetorInicialWhere[a + 1] == 'S') && (vetorInicialWhere[a + 2] == 'e')){
                   menuWhere = 5;
                }
            }

            if (vetorInicialWhere[a - 2] == 'g'){
                if ((vetorInicialWhere[a + 1] == 'I') && (vetorInicialWhere[a + 2] == 'n')){
                    menuWhere = 6;
                }
                if ((vetorInicialWhere[a + 1] == 'P') && (vetorInicialWhere[a + 2] == 'r')){
                    menuWhere = 7;
                }
                if ((vetorInicialWhere[a + 1] == 'N') && (vetorInicialWhere[a + 2] == 'i')){
                    menuWhere = 8;
                }
                if ((vetorInicialWhere[a + 1] == 'S') && (vetorInicialWhere[a + 2] == 'i')){
                   menuWhere = 9;
                }
                if ((vetorInicialWhere[a + 1] == 'T') && (vetorInicialWhere[a + 2] == 'e')){
                    menuWhere = 10;
                }
                if ((vetorInicialWhere[a + 1] == 'N') && (vetorInicialWhere[a + 2] == 'o')){
                    menuWhere = 11;
                }
                if ((vetorInicialWhere[a + 1] == 'A') && (vetorInicialWhere[a + 2] == 'r')){
                    menuWhere = 12;
                }     
            }

            if (vetorInicialWhere[a - 2] == 'o'){
                if ((vetorInicialWhere[a + 1] == 'A') && (vetorInicialWhere[a + 2] == 'n')){
                   menuWhere = 13;
                }
                if ((vetorInicialWhere[a + 1] == 'A') && (vetorInicialWhere[a + 2] == 'u')){
                   menuWhere = 14;
                }
                if ((vetorInicialWhere[a + 1] == 'C') && (vetorInicialWhere[a + 2] == 'o')){
                    menuWhere = 15;
                }
                if ((vetorInicialWhere[a + 1] == 'I') && (vetorInicialWhere[a + 2] == 'd')){
                    menuWhere = 16;
                }
                if ((vetorInicialWhere[a + 1] == 'O') && (vetorInicialWhere[a + 2] == 'r')){
                    menuWhere = 17;
                }
            }
        }
    } 

    return menuWhere;

    //Brenner
}
/************************************************************
 *             Atividade 6 - SCC0600 e SSC0601               *
 *                                                           *
 *      Nome: Artur Brenner Weber                            *
 *            Pedro Gabriel Ferreira Caliari                 *
 *                                                           *
*************************************************************/


//************************************************************ 
//                                                  Declarações

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"


//************************************************************ 
//                                                        Main

int main(int argc, char *argv[]) {

  //Le e guarda a entrada
  char *entrada;
  entrada = malloc(sizeof(char) * 300);
  fgets(entrada, 300, stdin);


  //Aloca espaco para cada um dos comandos 
  char *vetorInicialWhere = malloc(sizeof(char) * 200);
  char *vetorInicialFrom = malloc(sizeof(char) * 200);
  char *vetorInicialSelect = malloc(sizeof(char) * 200);


  //Organiza em vetores os comandos from, where e select 
  int tamanhoSelect;
  tamanhoSelect = separaEntrada(entrada, vetorInicialWhere, vetorInicialFrom, vetorInicialSelect);


  //define menu e atribui valores, sendo 0 = nao imprimir e n = imprimir em enésima posição 
  int menu[18];

  for (int z = 0; z < 18; z++){
      menu[z] = 0;
  }

  valorMenu(tamanhoSelect, vetorInicialSelect, menu);

  //fazer where funcionar
  int menuWhere = -1;
  char *vetorFerramenta = "0";
  vetorFerramenta = malloc(sizeof(char) * 200);
  if (strlen(vetorInicialWhere) >= 1){
    menuWhere = funcaoWhere(vetorInicialWhere, menuWhere);
    vetorFerramenta = achaWhere(vetorInicialWhere, vetorFerramenta);
  }

  //free nos vetores iniciais agora que a informação já foi passada para o menu
  free(vetorInicialWhere);
  free(vetorInicialFrom);
  free(vetorInicialSelect);

  //free na entrada agora que a informação já foi passada para os vetores iniciais
  free(entrada);


  //abre arquivos para leitura
  FILE *arqDocentes = fopen("Docentes.tsv", "r");
  FILE *arqProgs = fopen("Progs.tsv", "r");
  FILE *arqTrabalhos = fopen("Trabalhos.tsv", "r");


  //calcula numero linhas pois nosso programa aceita linhas variáveis no arquivo para que possa ser expandida a quantidade de informacoes
  int nLinhasDocentes = calculaLinhas(arqDocentes);
  int nLinhasProgs = calculaLinhas(arqProgs);
  int nLinhasTrabalhos = calculaLinhas(arqTrabalhos);


  //aloca structs para guardar as informacoes dos arquivos
  structDocentes *vetorDocentes = malloc(sizeof(structDocentes) * nLinhasDocentes);
  structProgs *vetorProgs = malloc(sizeof(structProgs) * nLinhasProgs);
  structTrabalhos *vetorTrabalhos = malloc(sizeof(structTrabalhos) * nLinhasTrabalhos);


  //rewind nos arquivos para usar na função ler apos calcular o numero de linhas
  rewind(arqDocentes);
  rewind(arqProgs);
  rewind(arqTrabalhos);


  //armazena os dados dos arquivos de forma organizada nas structs criadas
  lerDocentes(arqDocentes, vetorDocentes, nLinhasDocentes);
  lerProgs(arqProgs, vetorProgs, nLinhasProgs);
  lerTrabalhos (arqTrabalhos, vetorTrabalhos, nLinhasTrabalhos);


  //fecha arquivos 
  fclose(arqTrabalhos);
  fclose(arqProgs);
  fclose(arqDocentes);


  //descobre qual a ultima coluna a ser imprimida, a de maior valor, para que se possa usar \n no seu fim
  int maiormenu = calculamaior(menu);


  //interpreta o vetor menu e efetua sua saida
  printarSaida(vetorDocentes, vetorProgs, vetorTrabalhos,menu,nLinhasDocentes, nLinhasProgs,nLinhasTrabalhos, menuWhere, vetorFerramenta);


  //desaloca structs
  free(vetorTrabalhos);
  free(vetorProgs);
  free(vetorDocentes);

  return 0;
}
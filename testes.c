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

void lerDocentes() {
    //declara vetor docentos 
    tabelas *vetorDocentes = malloc(sizeof(cedulasDocentes) * 1);
    vetorDocentes->linhaDocentes = malloc(sizeof(cedulasDocentes) * 102 ); // (tem que arurmar)
    
    FILE *fdDocentes = fopen("Docentes.tsv", "r");
    if(fdDocentes != NULL) {
        int contTab = 0;
        char *linhaAtual; 
        linhaAtual = malloc(sizeof(char) * 500);
        //vai da linha 2 ate a linha 102 (tem q arrumar)
        for(int i = 2; i<102; i++){
            *linhaAtual = fdDocentes;
            char *armazCedula; 
            armazCedula = malloc(sizeof(char) * 150); 
            
            if(fdDocentes != '\t'){  // não entendi
                *armazCedula = fdDocentes; 
            }
            else {
                contTab++;
                armazCedula++;
                *armazCedula = '\0';
                
                switch(contTab){
                    case 1:
                        vetorDocentes->linhaDocentes[i].AnodaTitulacao = armazCedula; 
                        break;
                    case 2:
                        fgets(vetorDocentes->linhaDocentes[i].CodigodoPPG, 20, armazCedula);
                        break;
                    case 3:
                        fgets(vetorDocentes->linhaDocentes[i].Nacionalidade, 30, armazCedula);
                        break;
                    case 4:
                        fgets(vetorDocentes->linhaDocentes[i].Nome, 150, armazCedula);
                        break;
                    case 5:
                        fgets(vetorDocentes->linhaDocentes[i].PaisdaInstituicao, 30, armazCedula);
                        break;
                    case 6:
                        fgets(vetorDocentes->linhaDocentes[i].Sexo, 15, armazCedula);
                        i++;
                        contTab = 0;
                        break;
                }
                free(armazCedula);
            }
            linhaAtual++;
            fdDocentes++;
        } 
        free(linhaAtual);
        fclose(fdDocentes);
    }
    free(vetorDocentes->linhaDocentes);
    free(vetorDocentes);
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

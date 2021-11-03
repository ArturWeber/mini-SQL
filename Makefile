all : sql

funcoesEntrada.o : funcoesEntrada.c
		gcc -o funcoesEntrada.o -c funcoesEntrada.c

funcoesProcessamento.o : funcoesProcessamento.c
		gcc -o funcoesProcessamento.o -c funcoesProcessamento.c

funcoesSaida.o : funcoesSaida.c 
		gcc -o funcoesSaida.o -c funcoesSaida.c

main.o : main.c 
		gcc -o main.o -c main.c

sql : funcoesEntrada.o funcoesProcessamento.o funcoesSaida.o main.o
		gcc -o sql funcoesEntrada.o funcoesProcessamento.o funcoesSaida.o main.o


run : sql
		./sql

clean : 
		rm -f *.o
		rm -f *sql
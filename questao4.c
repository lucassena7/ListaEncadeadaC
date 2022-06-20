/*
	FAETERJ-Rio
	FPR - Noite - 2021/2
	Professor Leonrdo Vianna
	Data: 06/12/2021
	
	Listas encadeadas (listas por ponteiros)
	Exerc�cio 04: Implementar uma fun��o que, dadas duas listas din�micas do tipo TLista, verifique se estas s�o
				  iguais; isto �, cont�m os mesmos elementos, na mesma ordem.
*/
//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//Prot�tipo das fun��es
int verificarIguais (TLista L1, TLista L2);

//declara��o de tipos
typedef struct No { //No � uma vari�vel provis�ria de TNo
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista; //chame TNo* por Tlista

//main

//implementa��o das demais fun��es
int verificarIguais (TLista L1, TLista L2)
{
	//declara��o de vari�veis
	TLista aux1 = L1
	TLista aux2 = L2;
	
	while (aux1 != NULL && aux2 != NULL) //verificando se o primeiro n� armazena 'numero'
	{
		if(aux1->valor != aux2->valor)
		{
	    return 0;
		}
		aux1 = aux1->prox;
        aux2 = aux2->prox;
	}
		if (aux1 == NULL && aux2 == NULL)
		{
			return 1;
		}
		else 
		{
    	return 0;
		}
}

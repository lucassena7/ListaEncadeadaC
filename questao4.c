/*
	FAETERJ-Rio
	FPR - Noite - 2021/2
	Professor Leonrdo Vianna
	Data: 06/12/2021
	
	Listas encadeadas (listas por ponteiros)
	Exercício 04: Implementar uma função que, dadas duas listas dinâmicas do tipo TLista, verifique se estas são
				  iguais; isto é, contêm os mesmos elementos, na mesma ordem.
*/
//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//Protótipo das funções
int verificarIguais (TLista L1, TLista L2);

//declaração de tipos
typedef struct No { //No é uma variável provisória de TNo
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista; //chame TNo* por Tlista

//main

//implementação das demais funções
int verificarIguais (TLista L1, TLista L2)
{
	//declaração de variáveis
	TLista aux1 = L1
	TLista aux2 = L2;
	
	while (aux1 != NULL && aux2 != NULL) //verificando se o primeiro nó armazena 'numero'
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

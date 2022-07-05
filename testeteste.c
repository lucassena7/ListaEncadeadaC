/*
            Código escrito por Wagner Gaspar
            Agosto de 2021

            Aula 248: Lista Simplesmente Encadeada
            Como inserir de forma ordenada SEM a estrutura lista?
*/

//definição de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;  //ou     typedef *TNo TLista;

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
void inserir_no_inicio(TLista *L, int numero);
void inserir_no_fim(TLista *L, int numero);
void inserir_no_meio(TLista *L, int numero, int ant);
void inserir_ordenado(TLista *L, int numero);
void exibir (TLista L);
int menu ();

int main()
{
	//declaração de variáveis
    int opcao, valor, anterior;
    TLista L = NULL;

    do{
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - inserirF\n\t3 - InserirM\n\t4 - InserirO\n\t5 - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao)
		{
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&L, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_fim(&L, valor);
            break;
        case 3:
            printf("Digite um valor e o valor de referencia: ");
            scanf("%d%d", &valor, &anterior);
            inserir_no_meio(&L, valor, anterior);
            break;
        case 4:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_ordenado(&L, valor);
            break;
        case 5:
            exibir(L);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}

// procedimento para inserir no início
void inserir_no_inicio(TLista *L, int numero){
	//declaração de variáveis
	TLista aux;
	
   	aux = (TLista) malloc (sizeof(TNo));

    if(aux)
	{
        aux->valor = numero;
        aux->prox = *L;
        *L = aux;
    }
    else
    {
    	printf("Erro ao alocar memoria!\n");
	}
}

// procedimento para inserir no fim
void inserir_no_fim(TLista *L, int numero)
{
    //declaração de variáveis
	TLista aux, temp;
	
   	aux = (TLista) malloc (sizeof(TNo));
   	temp = (TLista) malloc (sizeof(TNo));

    if(aux)
	{
        aux->valor = numero;
        aux->prox = NULL;

        // é o primeiro?
        if(*L == NULL)
        {
        	*L = aux;
		}
        else
		{
            temp = *L;
            
            while(temp->prox)
            {
            	temp = temp->prox;
            	
           		temp->prox = aux;
			}
        }
    }
    else
    {
    	printf("Erro ao alocar memoria!\n");
	}
}

// procedimento para inserir no meio
void inserir_no_meio(TLista *L, int numero, int ant){
   //declaração de variáveis
	TLista aux, temp;
	
   	aux = (TLista) malloc (sizeof(TNo));
   	temp = (TLista) malloc (sizeof(TNo));
   	
    if(aux)
	{
        aux->valor = numero;
        // é o primeiro?
        if(*L == NULL)
		{
            aux->prox = NULL;
            *L = aux;
        }
        else
		{
            temp = *L;
            
            while((temp->valor != ant) && (temp->prox))
            {
	            temp = temp->prox;
	            aux->prox = temp->prox;
	            temp->prox = aux;
			}
        }
    }
    else
    {
    	printf("Erro ao alocar memoria!\n");	
	} 
}

void inserir_ordenado(TLista *L, int numero){
   //declaração de variáveis
	TLista aux, temp;
	
   	aux = (TLista) malloc (sizeof(TNo));
   	temp = (TLista) malloc (sizeof(TNo));

    if(aux)
	{
        aux->valor = numero;
        
        // a lista está vazia?
        if(*L == NULL)
		{
        	aux->prox = NULL;
        	
            *L = aux;
        } 
		// é o menor?
        else if(aux->valor < (*L)->valor)
		{
            aux->prox = *L;
            *L = aux;
        }
        else
		{
            temp = *L;
            
            while((temp->prox) && (aux->valor > temp->prox->valor))
            {
	            temp = temp->prox;
	            
	            aux->prox = temp->prox;
	            
	            temp->prox = aux;
			}
        }
    }
    else
    {
    	printf("Erro ao alocar memoria!\n");
	}
}

void exibir (TLista L)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se a lista está vazia
	if (L == NULL)   //if (!L)
	{
		printf ("Lista vazia!\n");
	}
	else
	{
		printf ("Elementos da lista: ");
		
		//fazer com que 'aux' aponte para o primeiro nó da lista
		aux = L;
		
		while (aux != NULL) //while (aux)
		{
			//exibindo cada elemento da lista
			printf ("%d ", aux->valor);
			
			//atualizar o 'aux', de forma que aponte para o próximo nó
			aux = aux->prox;
		}
		
		printf ("\n");	
	}
}

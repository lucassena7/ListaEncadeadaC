//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;  //ou     typedef *TNo TLista;

//protótipos das funções
int inserirOrdenado (TLista *L, int numero);
void exibir (TLista L);
TLista buscar (TLista L, int numero);
int menu ();



//main
void main ()
{
	//declaração de variáveis
	TLista L = NULL;
	int num1, num2, op;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)
		{
			//Inserção
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        if (inserirOrdenado (&L, num1) == TRUE)
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Exibir
			case 2: exibir (L);
					break;
					
			//Saída
			case 3: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 3);
}

int inserirOrdenado(TLista *L, int numero)
{
   //declaração de variáveis
	TLista aux, temp;
   	
   	//verificando se o valor já existe na lista
	if (buscar (*L, numero) != NULL)
	{
		return FALSE; //essa aqui é a parte q ele verifica se o número ja existe na lista. se existir, ele retorna falso e nao insere
	}
	else
		{
			//verificando se a memória foi alocada
			if (aux == NULL)
			{
				return FALSE;
			}
			else
			{
				aux = (TLista) malloc (sizeof(TNo));
   				temp = (TLista) malloc (sizeof(TNo));
   				
	        	aux->valor = numero;
	        
	       	 	// a lista está vazia?
	       	 	if(*L == NULL)
				{
	        		aux->prox = NULL;
	        	
	            	*L = aux;
	            
	            	return TRUE;
	        	}
					 
				// é o menor?
	        	else if(aux->valor < (*L)->valor)
				{
	            	aux->prox = *L;
	            
	            	*L = aux;
	            
	            	return TRUE;
	        	}
	        	else
				{
	            	temp = *L;
	            
	            	while((temp->prox) && (aux->valor > temp->prox->valor))
	            	{
		          		temp = temp->prox;
		            
		            	aux->prox = temp->prox;
		            
		           		temp->prox = aux;
		            
		            	return TRUE;
					}
	        	}  
    		}
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

TLista buscar (TLista L, int numero)
{
	//declaração de variáveis
	TLista aux;
	
	//fazer com que 'aux' aponte para o primeiro nó da lista
	aux = L;
		
	while (aux != NULL) //while (aux)
	{
		//verificando se o valor apontado por 'aux' é o número sendo buscado
		if (aux->valor == numero)
		{
			return aux;			
		}
						
		//atualizar o 'aux', de forma que aponte para o próximo nó
		aux = aux->prox;
	}
	
	//elemento não existe na lista
	return NULL;
}

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir Ordenado\n");
	printf ("(2) Exibir\n");
	printf ("(3) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

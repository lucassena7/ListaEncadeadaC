//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//defini��o de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;  //ou     typedef *TNo TLista;

//prot�tipos das fun��es
int inserirOrdenado (TLista *L, int numero);
void exibir (TLista L);
TLista buscar (TLista L, int numero);
int menu ();



//main
void main ()
{
	//declara��o de vari�veis
	TLista L = NULL;
	int num1, num2, op;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usu�rio
		op = menu ();
		
		//verificando a op��o escolhida
		switch (op)
		{
			//Inser��o
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a fun��o
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
					
			//Sa�da
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
   //declara��o de vari�veis
	TLista aux, temp;
   	
   	//verificando se o valor j� existe na lista
	if (buscar (*L, numero) != NULL)
	{
		return FALSE; //essa aqui � a parte q ele verifica se o n�mero ja existe na lista. se existir, ele retorna falso e nao insere
	}
	else
		{
			//verificando se a mem�ria foi alocada
			if (aux == NULL)
			{
				return FALSE;
			}
			else
			{
				aux = (TLista) malloc (sizeof(TNo));
   				temp = (TLista) malloc (sizeof(TNo));
   				
	        	aux->valor = numero;
	        
	       	 	// a lista est� vazia?
	       	 	if(*L == NULL)
				{
	        		aux->prox = NULL;
	        	
	            	*L = aux;
	            
	            	return TRUE;
	        	}
					 
				// � o menor?
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
	//declara��o de vari�veis
	TLista aux;
	
	//verificando se a lista est� vazia
	if (L == NULL)   //if (!L)
	{
		printf ("Lista vazia!\n");
	}
	else
	{
		printf ("Elementos da lista: ");
		
		//fazer com que 'aux' aponte para o primeiro n� da lista
		aux = L;
		
		while (aux != NULL) //while (aux)
		{
			//exibindo cada elemento da lista
			printf ("%d ", aux->valor);
			
			//atualizar o 'aux', de forma que aponte para o pr�ximo n�
			aux = aux->prox;
		}
		
		printf ("\n");	
	}
}

TLista buscar (TLista L, int numero)
{
	//declara��o de vari�veis
	TLista aux;
	
	//fazer com que 'aux' aponte para o primeiro n� da lista
	aux = L;
		
	while (aux != NULL) //while (aux)
	{
		//verificando se o valor apontado por 'aux' � o n�mero sendo buscado
		if (aux->valor == numero)
		{
			return aux;			
		}
						
		//atualizar o 'aux', de forma que aponte para o pr�ximo n�
		aux = aux->prox;
	}
	
	//elemento n�o existe na lista
	return NULL;
}

int menu ()
{
	//declara��o de vari�veis
	int opcao;
	
	//exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir Ordenado\n");
	printf ("(2) Exibir\n");
	printf ("(3) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}

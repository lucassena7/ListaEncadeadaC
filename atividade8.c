/* Dadas duas listas encadeadas L1 e L2, ambas do tipo TLista, ordenadas crescentemente e sem repeti��o de elementos, criar uma terceira lista L3, contendo 
   todos os elementos de L1 e L2. Como as duas originais, a nova lista deve ter seus elementos ordenados crescentemente, e repeti��o de valores. */
   
//Importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Defini��es de constantes
#define TRUE 1
#define FALSE 0

//Defini��es de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;  //ou     typedef *TNo TLista;

//Prot�tipos das fun��es
int inserirOrdenado (TLista *L, int numero);
void exibir (TLista L);
TLista buscar (TLista L, int numero);
int menu ();
void copiarLista (TLista *L, TLista *Laux);

//main
void main ()
{
	//Declara��o de vari�veis
	TLista L1 = NULL;
	TLista L2 = NULL;
	TLista L3 = NULL;
	int num1, num2, op;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usu�rio
		op = menu ();
		
		//verificando a op��o escolhida
		switch (op)
		{
			//Inserir na lista 1
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a fun��o
			        if (inserirOrdenado (&L1, num1) == TRUE)
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Inserir na lista 2
			case 2: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a fun��o
			        if (inserirOrdenado (&L2, num1) == TRUE)
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Exibir lista1
			case 3: exibir (L1);
					break;
			
			//Exibir lista2
			case 4: exibir (L2);
					break;
			
			//Chamando a fun��o copiarLista.
			case 5: copiarLista (&L1, &L3);
					copiarLista (&L2, &L3);
					break;
			
			//Exibir lista3
			case 6: exibir (L3);
					break;
					
			//Sa�da
			case 7: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 6);
}


//Implementa��o das demais fun��es
int inserirOrdenado(TLista *L, int numero)
{
   //Declara��o de vari�veis
	TLista aux, temp;
   	
   	//verificando se o valor j� existe na lista
	if (buscar (*L, numero) != NULL)
	{
		return FALSE; //essa aqui � a parte q ele verifica se o n�mero ja existe na lista. se existir, ele retorna falso e nao insere
	}
	else
		{
			aux = (TLista) malloc (sizeof(TNo));
   			temp = (TLista) malloc (sizeof(TNo));
   			
			//verificando se a mem�ria foi alocada
			if ((aux == NULL) || (temp == NULL))
			{
				return FALSE;
			}
			else
			{	
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
      				}
                aux->prox = temp->prox;
                temp->prox = aux;
                return TRUE;
	        	}  
    		}
		}
}

TLista buscar (TLista L, int numero)
{
	//Declara��o de vari�veis
	TLista aux;
	
	//fazer com que 'aux' aponte para o primeiro n� da lista
	aux = L;
		
	while (aux != NULL) //while (aux)
	{
		//verificando se o valor apontado por 'aux' ? o n�mero sendo buscado
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

void copiarLista (TLista *L, TLista *Laux)
{
	//Declara��o de vari�veis
	TLista aux = *L;
	
	while (aux) //Enquanto aux for diferente de NULL
	{
		inserirOrdenado(*Laux, aux->valor);
		aux = aux->prox;
	}
}

void exibir (TLista L)
{
	//Declara��o de vari�veis
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

int menu ()
{
	//Declara��o de vari�veis
	int opcao;
	
	//exibindo o menu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir elementos na lista 1\n");
	printf ("(2) Inserir elementos na lista 2\n");
	printf ("(3) Exibir elementos da lista 1\n");
	printf ("(4) Exibir elementos da lista 2\n");
	printf ("(5) Criar uma lista 'L3' com os elementos de 'L1' e 'L2' ordenados crescentemente e sem repeticao.\n");
	printf ("(6) Exibir elementos da lista 3\n");
	printf ("(7) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}

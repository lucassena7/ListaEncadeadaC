/* Desenvolver uma fun��o que, dada uma lista encadeada L do tipo TLista, exiba os seus elementos
   �de tr�s para frente�; ou seja, o elemento apontado por L ser� o �ltimo a ser exibido.
	
	Nota: por ser uma atividade que avalia a manipula��o de listas encadeadas, nenhuma outra
	estrutura de dados (como vetores, por exemplo) pode ser utilizada nesta solu��o. */

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
int menu ();
int inserir (TLista *L, int numero);
void exibir (TLista L);
void exibirContrario (TLista L);

void main ()
{
	//declara��o de vari�veis
	TLista lista = NULL;
	int opcao, num1, num2, resp;
	
	do
	{
		//o menu de op��es ser� apresentado ao usu�rio at� que ele opte por sair do sistema
		opcao = menu ();
		
		//testando a op��o escolhida
		switch (opcao)
		{
			//Inser��o
			case 1: printf ("Numero a ser inserido: ");
					scanf ("%d", &num1);
			
					//chamando a fun��o
					if (inserir (&lista, num1) == TRUE)
					{
						printf ("\n\tInsercao realizada com sucesso!\n");
					}
					else
					{
						printf ("\n\tInsercao nao realizada!\n");
					}
					break;
			
			//Exibi��o
			case 2: //chamando a fun��o
			        exibir (lista);
			        break;
			       
			//Exibi��o
			case 3: //chamando a fun��o
			        exibirContrario (lista);
			        break;      
			       
			//sa�da do programa 
			case 4: printf ("Fim do programa!\n");
			        break;
			        
			//op��o inv�lida
			default:printf ("Opcao invalida! Tente novamente.\n");
			        break;
		}
		
		system ("pause");
	}
	while (opcao != 4);	  //4 - op��o de sa�da
}

// Implementa��o das demais fun��es
int menu ()
{
	//declara��o de vair�veis
	int op;
	
	//limpando a tela
	system ("cls");
	
	//exibindo o menu de op��es ao usu�rio	
	printf ("Menu de opcoes:\n\n");
	printf ("(1) Inserir.\n");
	printf ("(2) Exibir\n");
	printf ("(3) Exibir elementos de tra's para frente.\n");
	printf ("(4) Sair\n\n");
	
	//lendo a op��o desejada
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &op);
	
	//retornando a op��o
	return op;
}

int inserir (TLista* L, int numero)
{
	//declara��o de vari�veis
	TLista aux;
	
	//posso 1: alocar mem�ria
	aux = (TLista) malloc (sizeof(TNo)); // malloc: argumento -> quantos bytes voce quer ? aux vai guardar a quantidade de mem�ria de TNo (retorna *void)
	
	//verificando se a mem�ria foi alocada
	if (aux == NULL)
	{
		return FALSE;
	}
	
	else
	{
		//passo 2: armazenando 'numero' na posi��o alocada
		aux ->valor = numero;
		
		//passo 3: fazendo o novo n� apontar para a aquele que at� ent�o era o primeiro n� da lista
		aux->prox = *L;
		
		//passo 4: fazer com que a lista aponte para o novo elemento (uma vez que est� sendo inserido no in�cio da lista)
		*L = aux;
		
		return TRUE;
	}
}

void exibir (TLista L)
{
	//declara��o de vari�veis
	TLista aux = L; //fazendo 'aux' apontar, inicialmente, para o primeiro n� (ou seja, aquele apontado por 'L')
	
	if (L == NULL)
	{
		printf ("Lista Vazia!");
	}
	
	else
	{
		printf ("Lista: ");
		
		while (aux != NULL) //enquanto 'aux' for diferente de NULL; ou seja, enquanto existir n� na lista.
		{
			//printf("%d ", ((*aux).valor));
			printf("%d ", aux->valor); //exibindo o valor que est� no n� apontado por 'aux'
			
			aux = aux->prox; //fazendo com que 'aux' aponte para o pr�ximo n� da lista
		}
	}
}

void exibirContrario (TLista L)
{
	//declara��o de vari�veis
	TLista aux = L; //fazendo 'aux' receber o primeiro n� (aquele apontado por 'L').
	
	if (L) //Enquanto a lista existir, ou seja, for diferente de NULL
	{	
		if (aux->prox == NULL) //se o 'prox' de 'aux' for igual a NULL
		{
			printf ("Lista: ");
			printf ("%d ", aux->valor);	
		}
		else //enquanto houver n� na lista
		{
			exibirContrario (aux->prox);
			printf("%d ", aux->valor);
		}
	}
	else
	{
		printf ("Lista Vazia!");
	}
}

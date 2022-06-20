/*
	FAETERJ-Rio
	FPR - Noite - 2021/2
	Professor Leonrdo Vianna
	Data: 06/12/2021
	
	Listas encadeadas (listas por ponteiros)
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//No* prox = No *prox --> prox � um ponteiro de No

//declara��o de tipos
typedef struct No { //No � uma vari�vel provis�ria de TNo
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista; //chame TNo* por Tlista

//prot�tipos das fun��es
//int inserir (Tno** L, int numero); //L � um ponteiro de ponteiro, o L guarda o endere�o onde voc� encontra um endere�o e nesse endere�o voce encontra um inteiro
int inserir (TLista* L, int numero);
int remover (TLista* L, int numero);
int alterar (TLista L, int velho, int novo); //o que muda � o conte�do da struct, e n�o o endere�o de memoria que a lista aponta
int buscar (TLista L, int numero); //s� vai percorrer a lista, n�o mudar� seu endere�o de memoria interno
void exibir (TLista L);
int menu ();

//main
void main ()
{
	//declara��o de vari�veis
	TLista lista = NULL;
	int opcao, num1, num2;
	
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
			
			//Remo��o
			case 2: printf ("Numero a ser removido: ");
					scanf ("%d", &num1);
			
					//chamando a fun��o
					if (remover (&lista, num1) != 0)
					{
						printf ("\n\tRemocao realizada com sucesso!\n");
					}
					else
					{
						printf ("\n\tRemocao nao realizada!\n");
					}
					break;
			
			//Altera��o
			case 3: printf ("Numero a ser alterado: ");
					scanf ("%d", &num1);
					
					printf ("Novo valor: ");
					scanf ("%d", &num2);
			
					//chamando a fun��o
					if (alterar (lista, num1, num2) != 0)
					{
						printf ("\n\tAlteracao realizada com sucesso!\n");
					}
					else
					{
						printf ("\n\tAlteracao nao realizada!\n");
					}
					break;
					
			//Busca
			case 4: printf ("Numero a ser buscado: ");
			        scanf ("%d", &num1);
			        
			        //chamando a fun��o
			        if (buscar (lista, num1) == TRUE)
			        {
			        	printf ("\n\tElemento encontrado na lista!\n");
					}
					else
					{
						printf ("\n\tElemento nao encontrado na lista!\n");
					}
					break;
			
			//Exibi��o
			case 5: //chamando a fun��o
			        exibir (lista);
			        break;
			       
			//sa�da do programa 
			case 6: printf ("Fim do programa!\n");
			        break;
			        
			//op��o inv�lida
			default:printf ("Opcao invalida! Tente novamente.\n");
			        break;
		}
		
		system ("pause");
	}
	while (opcao != 6);	  //6 - op��o de sa�da
}

//implementa��o das demais fun��es
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

int remover (TLista* L, int numero)
{
	//declara��o de vari�veis
	TLista aux1, aux2;
	int cont = 0;
	
	while ((*L != NULL) && ((*L)->valor == numero)) //verificando se o primeiro n� armazena 'numero'
	{
		aux1 = *L; //salvando em 'aux1' o endere�o do n� que ser� removido
		
		*L = aux1->prox; //fazer com que *L aponte para o "at� ent�o segundo elemento da lista" 
	
		free (aux1); //liberar a mem�ria apontada pelo 'aux1'
		
		cont++; //atualizando a quantidade de remo��es realizadas
	}
	
	//verificando se ainda h� elementos na lista
	if (*L != NULL)
	{
		//inicializando 'aux1' e 'aux2' de forma que apontem para os dois primeiros n�s da lista
		aux2 = *L;
		aux1 = (*L)->prox;   //ou   aux1 = aux2->prox;
		
		//percorrendo a lista com 'aux1'
		while (aux1 != NULL)
		{
			//verificando se 'aux1' est� apontando para o valor a ser removido
			if (aux1->valor == numero)
			{
				//fazer o n� anterior �quele que ser� removido apontar para o pr�ximo do n� a ser removido
				aux2->prox = aux1->prox;
				
				//liberar a mem�ria apontada pelo 'aux1'
				free (aux1);
		
				//atualizando a quantidade de remo��es realizadas
				cont++;
				
				//fazendo 'aux1' apontar para o pr�ximo elemento da lista
				aux1 = aux2->prox;
			}
			else
			{
				//andar com os dois auxiliares
				aux2 = aux1;		 //ou    aux2 = aux2->prox	
				aux1 = aux1->prox;   //ou    aux1 = aux2->prox;
			}
		}
	}
	//retornando a quantidade de remo��es realizadas
	return cont;
}

//vers�o da fun��o alterar retornando a quantidade de altera��es feitas
int alterar (TLista L, int velho, int novo)
{
	//declara��o de vari�veis
	TLista aux = L;		//fazendo 'aux' apontar, inicialmente, para o primeiro n� (ou seja, aquele apontado por 'L')
	int cont = 0;		//armazenar� o n�mero de altera��es realizadas
	
	while (aux != NULL)		//enquanto 'aux' for diferente de NULL; ou seja, enquanto existir n� na lista.
	{
		if (aux->valor == velho)	//verificando se o elemento apontado por 'aux' � o n�mero a ser alterado
		{
			aux->valor = novo;		//alterando o 'velho' pelo 'novo'
			cont++;					//atualizando o n�mero de altera��es realizadas
		}
		
		aux = aux->prox; 	//fazendo com que 'aux' aponte para o pr�ximo n� da lista
	}
	
	/*	Ou com FOR:

	for (aux=L;aux!=NULL;aux=aux->prox)
	{
		if (aux->valor == velho)	//verificando se o elemento apontado por 'aux' � o n�mero a ser alterado
		{
			aux->valor = novo;		//alterando o 'velho' pelo 'novo'
			cont++;					//atualizando o n�mero de altera��es realizadas
		}
	}*/
	
	//retornando a quantidade de altera��es realizadas
	return cont;
}
	
/*
//vers�o da fun��o alterar retornando TRUE ou FALSE
int alterar (TLista L, int velho, int novo)
{
	//declara��o de vari�veis
	TLista aux = L;		//fazendo 'aux' apontar, inicialmente, para o primeiro n� (ou seja, aquele apontado por 'L')
	int alterou = FALSE;
	
	while (aux != NULL)		//enquanto 'aux' for diferente de NULL; ou seja, enquanto existir n� na lista.
	{
		if (aux->valor == velho)	//verificando se o elemento apontado por 'aux' � o n�mero a ser alterado
		{
			aux->valor = novo;		//alterando o 'velho' pelo 'novo'			
			alterou = TRUE;
		}
		
		aux = aux->prox; 	//fazendo com que 'aux' aponte para o pr�ximo n� da lista
	}
	
	//retornando TRUE ou FALSE
	return alterou;
}
*/

int buscar (TLista L, int numero)
{
	//declara��o de vari�veis
	TLista aux = L; //fazendo 'aux' apontar, inicialmente, para o primeiro n� (ou seja, aquele apontado por 'L')
	
	while (aux != NULL) //enquanto 'aux' for diferente de NULL; ou seja, enquanto existir n� na lista.
	{	
		if (aux->valor == numero) //verificando se o elemento apontado por 'aux' � o n�mero sendo buscado
		{
			return TRUE;
		}
		aux = aux->prox; //fazendo com que 'aux' aponte para o pr�ximo n� da lista
	}
	return FALSE; //se chegou neste ponto, o 'numero' n�o existe em 'L'
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

int menu ()
{
	//declara��o de vair�veis
	int op;
	
	//limpando a tela
	system ("cls");
	
	//exibindo o menu de op��es ao usu�rio	
	printf ("Menu de opcoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a op��o desejada
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &op);
	
	//retornando a op��o
	return op;
}

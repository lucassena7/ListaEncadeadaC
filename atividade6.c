/* Desenvolver uma função que, dada uma lista encadeada L do tipo TLista e dois números inteiros 
   A e B, retorne o número de elementos de L que encontram-se no intervalo [A, B]. */

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//No* prox = No *prox --> prox é um ponteiro de No

//declaração de tipos
typedef struct No { //No é uma variável provisória de TNo
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista; //chame TNo* por Tlista

//protótipos das funções
int menu ();
int inserir (TLista* L, int numero);
void exibir (TLista L);
int quantNumerosIntervalo (TLista L, int numA, int numB);

void main ()
{
	//declaração de variáveis
	TLista lista = NULL;
	int opcao, num1, num2, resp;
	
	do
	{
		//o menu de opções será apresentado ao usuário até que ele opte por sair do sistema
		opcao = menu ();
		
		//testando a opção escolhida
		switch (opcao)
		{
			//Inserção
			case 1: printf ("Numero a ser inserido: ");
					scanf ("%d", &num1);
			
					//chamando a função
					if (inserir (&lista, num1) == TRUE)
					{
						printf ("\n\tInsercao realizada com sucesso!\n");
					}
					else
					{
						printf ("\n\tInsercao nao realizada!\n");
					}
					break;
			
			//Exibição
			case 2: //chamando a função
			        exibir (lista);
			        break;
			       
			//Busca
			case 3: printf ("Entre com o primeiro numero do intervalo: ");
			        scanf ("%d", &num1);
			        
			        printf ("Entre com o segundo numero do intervalo: ");
			        scanf ("%d", &num2);
			        
			        //Chamando a função
			        resp = quantNumerosIntervalo (lista, num1, num2);
			        printf ("O intervalo entre %d e %d possui %d elementos.\n", num1, num2, resp);
					break;       
			       
			//saída do programa 
			case 4: printf ("Fim do programa!\n");
			        break;
			        
			//opção inválida
			default:printf ("Opcao invalida! Tente novamente.\n");
			        break;
		}
		
		system ("pause");
	}
	while (opcao != 4);	  //4 - opção de saída
}

// Implementação das demais funções
int menu ()
{
	//declaração de vairáveis
	int op;
	
	//limpando a tela
	system ("cls");
	
	//exibindo o menu de opções ao usuário	
	printf ("Menu de opcoes:\n\n");
	printf ("(1) Inserir.\n");
	printf ("(2) Exibir\n");
	printf ("(3) Quantidade de numeros entre um intervalo.\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção desejada
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &op);
	
	//retornando a opção
	return op;
}

int inserir (TLista* L, int numero)
{
	//declaração de variáveis
	TLista aux;
	
	//posso 1: alocar memória
	aux = (TLista) malloc (sizeof(TNo)); // malloc: argumento -> quantos bytes voce quer ? aux vai guardar a quantidade de memória de TNo (retorna *void)
	
	//verificando se a memória foi alocada
	if (aux == NULL)
	{
		return FALSE;
	}
	
	else
	{
		//passo 2: armazenando 'numero' na posição alocada
		aux ->valor = numero;
		
		//passo 3: fazendo o novo nó apontar para a aquele que até então era o primeiro nó da lista
		aux->prox = *L;
		
		//passo 4: fazer com que a lista aponte para o novo elemento (uma vez que está sendo inserido no início da lista)
		*L = aux;
		
		return TRUE;
	}
}

void exibir (TLista L)
{
	//declaração de variáveis
	TLista aux = L; //fazendo 'aux' apontar, inicialmente, para o primeiro nó (ou seja, aquele apontado por 'L')
	
	if (L == NULL)
	{
		printf ("Lista Vazia!");
	}
	
	else
	{
		printf ("Lista: ");
		
		while (aux != NULL) //enquanto 'aux' for diferente de NULL; ou seja, enquanto existir nó na lista.
		{
			//printf("%d ", ((*aux).valor));
			printf("%d ", aux->valor); //exibindo o valor que está no nó apontado por 'aux'
			
			aux = aux->prox; //fazendo com que 'aux' aponte para o próximo nó da lista
		}
	}
}

int quantNumerosIntervalo (TLista L, int numA, int numB)
{
	//declaração de variáveis
	TLista aux = L; //fazendo 'aux' apontar, inicialmente, para o primeiro nó (ou seja, aquele apontado por 'L')
	int cont = 0;
	
	while (aux != NULL) //enquanto 'aux' for diferente de NULL; ou seja, enquanto existir nó na lista.
	{	
		if ((aux->valor >= numA) && (aux->valor <= numB)) //verificando se o elemento apontado por 'aux' está no intervalo.
		{
			cont++;
		}
		aux = aux->prox; //fazendo com que 'aux' aponte para o próximo nó da lista
	}
	return cont; //retornando a quantidade de números do intervalo
}

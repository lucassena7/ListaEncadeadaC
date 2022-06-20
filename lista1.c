/*
	FAETERJ-Rio
	FPR - Noite - 2021/2
	Professor Leonrdo Vianna
	Data: 06/12/2021
	
	Listas encadeadas (listas por ponteiros)
*/

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
//int inserir (Tno** L, int numero); //L é um ponteiro de ponteiro, o L guarda o endereço onde você encontra um endereço e nesse endereço voce encontra um inteiro
int inserir (TLista* L, int numero);
int remover (TLista* L, int numero);
int alterar (TLista L, int velho, int novo); //o que muda é o conteúdo da struct, e não o endereço de memoria que a lista aponta
int buscar (TLista L, int numero); //só vai percorrer a lista, não mudará seu endereço de memoria interno
void exibir (TLista L);
int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista lista = NULL;
	int opcao, num1, num2;
	
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
			
			//Remoção
			case 2: printf ("Numero a ser removido: ");
					scanf ("%d", &num1);
			
					//chamando a função
					if (remover (&lista, num1) != 0)
					{
						printf ("\n\tRemocao realizada com sucesso!\n");
					}
					else
					{
						printf ("\n\tRemocao nao realizada!\n");
					}
					break;
			
			//Alteração
			case 3: printf ("Numero a ser alterado: ");
					scanf ("%d", &num1);
					
					printf ("Novo valor: ");
					scanf ("%d", &num2);
			
					//chamando a função
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
			        
			        //chamando a função
			        if (buscar (lista, num1) == TRUE)
			        {
			        	printf ("\n\tElemento encontrado na lista!\n");
					}
					else
					{
						printf ("\n\tElemento nao encontrado na lista!\n");
					}
					break;
			
			//Exibição
			case 5: //chamando a função
			        exibir (lista);
			        break;
			       
			//saída do programa 
			case 6: printf ("Fim do programa!\n");
			        break;
			        
			//opção inválida
			default:printf ("Opcao invalida! Tente novamente.\n");
			        break;
		}
		
		system ("pause");
	}
	while (opcao != 6);	  //6 - opção de saída
}

//implementação das demais funções
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

int remover (TLista* L, int numero)
{
	//declaração de variáveis
	TLista aux1, aux2;
	int cont = 0;
	
	while ((*L != NULL) && ((*L)->valor == numero)) //verificando se o primeiro nó armazena 'numero'
	{
		aux1 = *L; //salvando em 'aux1' o endereço do nó que será removido
		
		*L = aux1->prox; //fazer com que *L aponte para o "até então segundo elemento da lista" 
	
		free (aux1); //liberar a memória apontada pelo 'aux1'
		
		cont++; //atualizando a quantidade de remoções realizadas
	}
	
	//verificando se ainda há elementos na lista
	if (*L != NULL)
	{
		//inicializando 'aux1' e 'aux2' de forma que apontem para os dois primeiros nós da lista
		aux2 = *L;
		aux1 = (*L)->prox;   //ou   aux1 = aux2->prox;
		
		//percorrendo a lista com 'aux1'
		while (aux1 != NULL)
		{
			//verificando se 'aux1' está apontando para o valor a ser removido
			if (aux1->valor == numero)
			{
				//fazer o nó anterior àquele que será removido apontar para o próximo do nó a ser removido
				aux2->prox = aux1->prox;
				
				//liberar a memória apontada pelo 'aux1'
				free (aux1);
		
				//atualizando a quantidade de remoções realizadas
				cont++;
				
				//fazendo 'aux1' apontar para o próximo elemento da lista
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
	//retornando a quantidade de remoções realizadas
	return cont;
}

//versão da função alterar retornando a quantidade de alterações feitas
int alterar (TLista L, int velho, int novo)
{
	//declaração de variáveis
	TLista aux = L;		//fazendo 'aux' apontar, inicialmente, para o primeiro nó (ou seja, aquele apontado por 'L')
	int cont = 0;		//armazenará o número de alterações realizadas
	
	while (aux != NULL)		//enquanto 'aux' for diferente de NULL; ou seja, enquanto existir nó na lista.
	{
		if (aux->valor == velho)	//verificando se o elemento apontado por 'aux' é o número a ser alterado
		{
			aux->valor = novo;		//alterando o 'velho' pelo 'novo'
			cont++;					//atualizando o número de alterações realizadas
		}
		
		aux = aux->prox; 	//fazendo com que 'aux' aponte para o próximo nó da lista
	}
	
	/*	Ou com FOR:

	for (aux=L;aux!=NULL;aux=aux->prox)
	{
		if (aux->valor == velho)	//verificando se o elemento apontado por 'aux' é o número a ser alterado
		{
			aux->valor = novo;		//alterando o 'velho' pelo 'novo'
			cont++;					//atualizando o número de alterações realizadas
		}
	}*/
	
	//retornando a quantidade de alterações realizadas
	return cont;
}
	
/*
//versão da função alterar retornando TRUE ou FALSE
int alterar (TLista L, int velho, int novo)
{
	//declaração de variáveis
	TLista aux = L;		//fazendo 'aux' apontar, inicialmente, para o primeiro nó (ou seja, aquele apontado por 'L')
	int alterou = FALSE;
	
	while (aux != NULL)		//enquanto 'aux' for diferente de NULL; ou seja, enquanto existir nó na lista.
	{
		if (aux->valor == velho)	//verificando se o elemento apontado por 'aux' é o número a ser alterado
		{
			aux->valor = novo;		//alterando o 'velho' pelo 'novo'			
			alterou = TRUE;
		}
		
		aux = aux->prox; 	//fazendo com que 'aux' aponte para o próximo nó da lista
	}
	
	//retornando TRUE ou FALSE
	return alterou;
}
*/

int buscar (TLista L, int numero)
{
	//declaração de variáveis
	TLista aux = L; //fazendo 'aux' apontar, inicialmente, para o primeiro nó (ou seja, aquele apontado por 'L')
	
	while (aux != NULL) //enquanto 'aux' for diferente de NULL; ou seja, enquanto existir nó na lista.
	{	
		if (aux->valor == numero) //verificando se o elemento apontado por 'aux' é o número sendo buscado
		{
			return TRUE;
		}
		aux = aux->prox; //fazendo com que 'aux' aponte para o próximo nó da lista
	}
	return FALSE; //se chegou neste ponto, o 'numero' não existe em 'L'
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

int menu ()
{
	//declaração de vairáveis
	int op;
	
	//limpando a tela
	system ("cls");
	
	//exibindo o menu de opções ao usuário	
	printf ("Menu de opcoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a opção desejada
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &op);
	
	//retornando a opção
	return op;
}

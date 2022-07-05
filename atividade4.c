/* Dado um arquivo texto e dois inteiros posA e posB, desenvolver uma fun��o que remova do arquivo o bloco de
caracteres delimitados pelas posi��es posA e posB.
	Notas:
			1. Suponha que o valor de posA � menor ou igual ao de posB;
			2. Considere que o primeiro caracter do arquivo encontra-se na posi��o 0;
			3. Se n�o existir a posi��o posA no arquivo, o seu conte�do ser� preservado;
			4. Se n�o existir a posi��o posB no arquivo, ser�o removidos todos os caracteres da posi��o posA ao final do arquivo. */

//importa��o de bibliotecas
#include <stdio.h>

//declara��o dos prot�tipos das fun��es
int removerBlocoCaracteres (char nomeArq[], int posA, int posB);
int quantidadeCaracteres (char nomeArq[]);

//main
void main ()
{
	//declara��o de vari�veis
	char nome[20];
	int pos1, pos2;
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	gets (nome);
	
	printf ("Entre com a posicao inicial a ser removida: ");
	scanf ("%d", &pos1);
	
	printf ("Entre com a posicao final a ser removida: ");
	scanf ("%d", &pos2);
	
	//chamando a fun��o
	switch (removerBlocoCaracteres (nome, pos1, pos2))
	{
		case -1: printf ("\nErro na abertura dos arquivos!\n");
		         break;
		         
		case  0: printf ("\nRemocao realizada com sucesso!\n");
		         break;
	}
}

//implementa��o das fun��es
int removerBlocoCaracteres (char nomeArq[], int posA, int posB)
{
	//declara��o de vari�veis
	FILE *arq, *tmp;
	char carac;
	int cont=0;
	int tamanho = quantidadeCaracteres (nomeArq);
	
	//abertura dos arquivos
	arq = fopen (nomeArq, "r");  //r - read   /   w - write   /  a - append
	tmp = fopen ("temp.txt", "w");
	
	//testando se houve erro na abertura de um dos arquivos (ou nos dois)
	if ((arq == NULL) || (tmp == NULL))
	{
		remove ("temp.txt");
		return -1;
	}
	else
	{
		//lendo os valores do arquivo origem, enquanto existirem
		//e jogando no temporario apenas os valores diferentes de 'numero'
		while (fscanf (arq, "%c", &carac) != EOF)   //end of file
		{
			//for (i=0, j=posB; i<=posA, j<tamanho; i++, j++)
			//{
				if ((carac < posA) || (carac >posB))
				{
					fprintf (tmp, "%c", carac);
				}
			//}
			
		}
				
		//fechar os arquivos
		fclose (arq);
		fclose (tmp);
		
		//removendo o arquivo original
		remove (nomeArq);
		
		//renomeando o arquivo tempor�rio para o nome do arquivo original
		rename ("temp.txt", nomeArq);
		
		return 0;
	}
}

int quantidadeCaracteres (char nomeArq[])
{
	//declara��o de vari�veis
	FILE *arq;
	int cont = 0;
	char caracter;
	
	//abrindo o arquivo
	arq = fopen (nomeArq, "r");
	
	//testando se houve sucesso na abertura ou n�o
	if (arq == NULL)
	{
		return -1;	//sinalizando que n�o foi poss�vel abrir o arquivo
	}
	else
	{
		//lendo os caracteres do arquivo
		while (fscanf (arq, "%c", &caracter) != EOF)
		{
			//jogando o caracter lido para mai�sculo
			caracter = toupper (caracter);
			
			cont++;
		}
		
		//fechando o arquivo
		fclose (arq);
		
		//retornando a quantidade de caracteres
		return cont;
	}	
}

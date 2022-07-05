/* Dado um arquivo texto e dois inteiros posA e posB, desenvolver uma função que remova do arquivo o bloco de
caracteres delimitados pelas posições posA e posB.
	Notas:
			1. Suponha que o valor de posA é menor ou igual ao de posB;
			2. Considere que o primeiro caracter do arquivo encontra-se na posição 0;
			3. Se não existir a posição posA no arquivo, o seu conteúdo será preservado;
			4. Se não existir a posição posB no arquivo, serão removidos todos os caracteres da posição posA ao final do arquivo. */

//importação de bibliotecas
#include <stdio.h>

//declaração dos protótipos das funções
int removerBlocoCaracteres (char nomeArq[], int posA, int posB);
int quantidadeCaracteres (char nomeArq[]);

//main
void main ()
{
	//declaração de variáveis
	char nome[20];
	int pos1, pos2;
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	gets (nome);
	
	printf ("Entre com a posicao inicial a ser removida: ");
	scanf ("%d", &pos1);
	
	printf ("Entre com a posicao final a ser removida: ");
	scanf ("%d", &pos2);
	
	//chamando a função
	switch (removerBlocoCaracteres (nome, pos1, pos2))
	{
		case -1: printf ("\nErro na abertura dos arquivos!\n");
		         break;
		         
		case  0: printf ("\nRemocao realizada com sucesso!\n");
		         break;
	}
}

//implementação das funções
int removerBlocoCaracteres (char nomeArq[], int posA, int posB)
{
	//declaração de variáveis
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
		
		//renomeando o arquivo temporário para o nome do arquivo original
		rename ("temp.txt", nomeArq);
		
		return 0;
	}
}

int quantidadeCaracteres (char nomeArq[])
{
	//declaração de variáveis
	FILE *arq;
	int cont = 0;
	char caracter;
	
	//abrindo o arquivo
	arq = fopen (nomeArq, "r");
	
	//testando se houve sucesso na abertura ou não
	if (arq == NULL)
	{
		return -1;	//sinalizando que não foi possível abrir o arquivo
	}
	else
	{
		//lendo os caracteres do arquivo
		while (fscanf (arq, "%c", &caracter) != EOF)
		{
			//jogando o caracter lido para maiúsculo
			caracter = toupper (caracter);
			
			cont++;
		}
		
		//fechando o arquivo
		fclose (arq);
		
		//retornando a quantidade de caracteres
		return cont;
	}	
}

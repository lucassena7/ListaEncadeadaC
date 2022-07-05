void main()
{	
//declarando string
	char string[10];
	
//lendo uma string
	printf("Entre com uma palavra: ");
	fflush(stdin);
	gets(string);
	
//chamando função que vai percorrer a string e aplicar a função recursiva de contagem de caracteres
	percorreString(string);
}

//função recursiva para contagem de cada caractere da string passada na main
int contaCaracteres(char str[], int i)
{
	//caso 
	if (str[i]==0)
	{
		return 1;
	}
	else
	{
		return contaCaracteres(str, i+1);
	}
}

int percorreString(char str[])
{
	int i, aux;
	
	//percorrendo a string
	for (i=0; i<strlen(str); i++)
	{
		aux = str[i];
		if(aux = str[i])
		{
			//exibindo cada caracter e sua quantidade
			printf("\n\t %c - aparece %d vezes", str[i], contaCaracteres(str, i));
		}
	}
}

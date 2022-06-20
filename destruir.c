/*
	FAETERJ-Rio
	FPR - Noite - 2021/2
	Professor Leonardo Vianna
	Data: 13/12/2021
	
	Listas encadeadas (listas por ponteiros)
	
			Continuação da aula de 06/12/2021
*/

void destruir_iterativo (TLista *l)
{
	//declaração de variáveis
	TLista aux;
	
	while (*l)
    //while (*l != NULL)
	{
        aux = *l;
        *l = (*l)->prox;
        free(aux);
    }
}


void destruir_recursivo (TLista *l)
{
    if(*l)
	{
        destruir_recursivo (&((*l)->prox));
        free (*l);
        *l = NULL;
    }
}

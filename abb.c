#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

/* Inicializa a ABB */
void tree_init(arvbin * t)
{
	*t = NULL;
}
// procurar um valor x no arranjo da in_fixa
int procurar(int arranjo[], int inicio, int fim, int dado)
{
	int i;
	for (i = inicio; i <= fim; i++)
	{
		if (arranjo[i] == dado)
			break;
	}
	return i;
}
/* Insere um novo elemento x na ABB t */
arvbin tree_ins(arvbin * t, tree_info x)
{
        (*t) = (arvbin) malloc(sizeof(struct no_arvbin));
        (*t)->dado = x;
        (*t)->esq = (*t)->dir = NULL;

        return (*t);

}
/* Realiza o percurso pré­-ordem da árvore binária t */
void pre_ordem(arvbin t)
{
    if (t != NULL) {
        printf("%d ", t->dado); // processa a raiz
        pre_ordem(t->esq); // visita a subárvore esquerda
        pre_ordem(t->dir); // visita a subárvore direita
    }
}

/**
@author:
        Antônio Flávio - N° 201626192 - Sistema de Informação
        Luiz Bissiato  - N° 201625449 - Sistema de Informação
        Wanderley Silva  N° 201626181 - Sistema de Informação

@materia: Estrutura de dados II
@professor: Prof. Me. Ciro Cirne Trindade
@data:07/10/2017
*/

#include "abb.h"
#include <stdio.h>

//Prototipo da função para realizar os testes da arvore pre fixa
arvbin testes(int[], int[], int, int, int*);

//Função para 'pegar' a raiz
arvbin criarArvore(int in_fixa[], int pos_fixa[], int n)
{
    int novoN = n - 1;
    return testes(in_fixa, pos_fixa, 0, n - 1, &novoN);
}
//função recursiva que ira testa se é possivel criar a arvore em pre ordem e ira processar o lado direito e esquerdo da arvore
arvbin testes(int in_fixa[], int pos_fixa[], int in_inicio, int in_final, int *Index)
{
    int static i = 0;
    arvbin no;
    if(i == 0){
        tree_init(&no);
        i++;
    }

    if(in_inicio > in_final)
        return NULL;

    no = tree_ins(&no, pos_fixa[*Index]);
    (*Index)--;

    int novoIndex = procurar(in_fixa, in_inicio, in_final, no->dado);


    no->dir = testes(in_fixa, pos_fixa, novoIndex + 1, in_final, Index);
    no->esq = testes(in_fixa, pos_fixa, in_inicio, novoIndex - 1, Index);

    return no;
}

int main()
{

	int n = 0; // Numero de termos
	int i = 0; // iteracao do laço

	scanf("%d", &n); //Get 'n' termos

	int in[n], pos[n]; // Criacao de um vetor de N elementos

	for(i = 0; i != n; i++) { //Laço do vetor infixa
        scanf("%d", &in[i]);
	}

	for(i = 0; i != n; i++) { //Laço do vetor pos fixa
        scanf("%d", &pos[i]);
	}

	arvbin ArvPre = criarArvore(in, pos, n); //criação da arvore pre fixa, passando o parametros in_fixa, pos_fixa e numero de termos

	pre_ordem(ArvPre);
	printf("\n\n\n");

	return 0;
}

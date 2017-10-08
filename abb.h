/*
 * abb.h
 *
 * Definição do TAD Árvore Binária de Busca (ABB) e protótipo
 * de suas operações.
 *
 * Ciro C. Trindade
 *
 * 22/ago/2017
 */

#ifndef _ABB_H
#define _ABB_H

#include <stdbool.h>

typedef int tree_info;
typedef struct no_arvbin * arvbin;
struct no_arvbin {
    arvbin esq;
    tree_info dado;
    arvbin dir;
};

/* Inicializa a ABB */
void tree_init(arvbin *);

/* Insere um novo elemento na ABB */
arvbin tree_ins(arvbin *, tree_info);

#endif

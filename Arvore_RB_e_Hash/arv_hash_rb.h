#ifndef _ARVORE_HASH_RB_H_
#define _ARVORE_HASH_RB_H_

#include "arv_rb.h"

typedef struct arv_hash{
    Arv_rb* T;
} Arv_hash;
int mod(int x, int y);
void inicializa(Arv_hash* h[],int n);
void insere_k(Arv_hash* h,int k);
void remover_hash_nodo(Arv_hash* h[],int n,int k);
void remover_hash(Arv_hash* h[],int n);
void print_hash(Arv_hash* h[],int n);
#endif

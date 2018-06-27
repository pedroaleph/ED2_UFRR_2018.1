#ifndef _ARVORE_HASH_RB_H_
#define _ARVORE_HASH_RB_H_

#include "arv_rb.h"

typedef struct arv_hash{
    Arv_rb* T;
} Arv_hash;
void inicializa(Arv_hash* h[],int n);
void insere_k(Arv_hash* h,int k);
void remover_hash(Arv_hash* h[],int n);
#endif

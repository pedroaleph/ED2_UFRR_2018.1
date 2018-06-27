#include <stdio.h>
#include <stdlib.h>
#include "arv_hash_rb.h"

int mod(int x, int y){
    return x%y;
}
void inicializa(Arv_hash* h[],int n){
    int i;
    for(i=0;i<n;i++){
        h[i] = NULL;
    }
}
void insere_k(Arv_hash* h,int k){
    if(h==NULL){
        h = (Arv_hash*)malloc(sizeof(Arv_hash));
        h->T = nova_arv_rb(h->T);
    }
    h->T->raiz = novo_nodo(h->T,h->T->raiz,h->T->NIL,k);
}
void remover_hash_nodo(Arv_hash* h[],int n,int k){
    int i;
    int hk = mod(k,n);
    for(i=0;i<n;i++){
        if(i==hk){
            h[i]->T->raiz = remover_nodo(h[i]->T,h[i]->T->raiz,h[i]->T->NIL,k);
            break;
        }
    }
}
void remover_hash(Arv_hash* h[],int n){
    int i;
    for(i=0;i<n;i++){
        if(h[i]!=NULL){
            remover_arv(h[i]->T);
            free(h[i]);
        }
    }
    free(h);
}

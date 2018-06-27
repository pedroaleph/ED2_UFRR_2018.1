#include <stdio.h>
#include <stdlib.h>
#include "arv_rb.h"

Arv_rb* nova_arv_rb(Arv_rb* T){
    T = (Arv_rb*)malloc(sizeof(Arv_rb));
    T->NIL = NULL;
    T->raiz = T->NIL;
    return T;
}
Nodo* novo_nodo(Arv_rb* T,Nodo* z,Nodo* p, int v){
    if(z==T->NIL){
        z = (Nodo*)malloc(sizeof(Nodo));
        z->info = v;
        if(p!= T->NIL)
            z->p = p;
        else z->p = T->NIL;
    }
    else{
        if(v<z->info)
            novo_nodo(T,z->esq,z,v);
        else
            novo_nodo(T,z->dir,z,v);
    }
    return z;
}
void remover_arv(Arv_rb* T){
    remover_nodos(T,T->raiz);
}
void remover_nodos(Arv_rb* T,Nodo* z){
    while(z!=T->NIL){
        if(z->dir==T->NIL && z->esq==T->NIL){
            free(z);
        }
        else{
            remover_nodos(T,z->esq);
            remover_nodos(T,z->dir);
        }
    }
}

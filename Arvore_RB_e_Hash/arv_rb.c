#include <stdio.h>
#include <stdlib.h>
#include "arv_rb.h"

int RED = 0;
int BLACK = 1;

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
        z->esq = T->NIL;
        z->dir = T->NIL;
        z->color = RED;

    }
    else{
        if(v<z->info)
            novo_nodo(T,z->esq,z,v);
        else
            novo_nodo(T,z->dir,z,v);
    }
    arv_rb_fix_up_insert(T,z);
    return z;
}
void arv_rb_fix_up_insert(Arv_rb* T, Nodo* z){
    while(z->p->color==RED){
        if(z->p==z->p->p->esq){
            Nodo* y = z->p->p->dir;
            if(y->color == RED){
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else {
                if(z == z->p->dir){
                    z = z->p;
                    left_rotate(T,z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                right_rotate(T,z->p->p);
            }
        }
        else{
            Nodo* y = z->p->p->esq;
            if(y->color == RED){
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else {
                if(z == z->p->esq){
                    z = z->p;
                    right_rotate(T,z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                left_rotate(T,z->p->p);
            }
        }
    }
    T->raiz->color = BLACK;
}
void left_rotate(Arv_rb* T,Nodo* z){
    Nodo* y = z->dir;
    z->dir = y->esq;
    if(y->esq!=T->NIL)
        y->esq->p = z;
    y->p = z->p;
    if(z->p==T->NIL)
        T->NIL = y;
    else if(z==z->p->esq)
        z->p->esq = y;
    else z->p->dir = y;
    y->esq = z;
    z->p = y;
}void right_rotate(Arv_rb* T,Nodo* z){
    Nodo* y = z->esq;
    z->esq = y->dir;
    if(y->dir!=T->NIL)
        y->dir->p = z;
    y->p = z->p;
    if(z->p==T->NIL)
        T->NIL = y;
    else if(z==z->p->dir)
        z->p->dir = y;
    else z->p->esq = y;
    y->dir = z;
    z->p = y;
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

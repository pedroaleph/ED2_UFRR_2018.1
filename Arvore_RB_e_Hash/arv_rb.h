#ifndef _ARVORE_RB_H_
#define _ARVORE_RB_H_

typedef struct nodo {
    int color;
    int info;
    struct nodo *p;
    struct nodo *esq;
    struct nodo *dir;
    int alt;
}Nodo;
typedef struct arv_rb {
    Nodo* raiz;
    Nodo* NIL;
} Arv_rb;

Arv_rb* nova_arv_rb(Arv_rb* T);
Nodo* novo_nodo(Arv_rb* T,Nodo* z,Nodo* p,int v);
void left_rotate(Arv_rb * T, Nodo* x);
void right_rotate(Arv_rb * T, Nodo* x);
void arv_rb_fix_up_insert(Arv_rb * T, Nodo* z);
void remover_arv(Arv_rb* T);
void remover_nodos(Arv_rb* T,Nodo* z);
#endif

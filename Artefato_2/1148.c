#include <stdio.h>
#include <limits.h>
int existe;
typedef struct aresta{
    int h;
    struct grafo* a;
    struct grafo* b;
} Aresta;
typedef struct grafo{
    int V;
    struct aresta* a[250000];
    int n;
    int visited;

} Grafo;
void inicializa(Grafo* g[]){
    int i,j;
    for(i = 0; i< 500; i++){
        g[i] = (Grafo*)malloc(sizeof(Grafo));
        g[i]->V = i+1;
        for(j = 0; j < 250000; j++){
             g[i]->a[j] = NULL;
        }
        g[i]->n = 0;
        g[i]->visited = 0;
    }
}
void reinicializa(Grafo* g[], int n){
    int i;
    for(i = 0; i< n; i++){
        g[i]->visited = 0;
    }
}
void inicializa_arestas(Aresta* a[]){
    int i;
    for(i = 0; i< 250000; i++){
        a[i] = (Aresta*)malloc(sizeof(Aresta));
        a[i]->a = NULL;
        a[i]->b = NULL;
    }
}
void acordo(Grafo* x, Grafo* y, int h, Aresta* a){
    a->h = h;
    x->a[x->n++] = a;
    a->a = x;
    a->b = y;
    y->a[y->n++] = a;
}
int caminho(Grafo* origem, Grafo* destino,int m,int z){
    int x,menor;
    if(origem->a[z]->b->V!=destino->V && origem->visited == 0){
        menor = origem->a[0]->h;
        for(x = 1; x < origem->n; x++){
            if(origem->a[x]->h<menor && origem->a[x]->b->visited == 0){
                 menor = caminho(origem->a[x]->b,destino,m,0);
            }
        }
            m += menor;
            origem->visited = 1;
            return menor;
    }
    else if(origem->a[z]->b->V==destino->V) return m;
    else return -1;
}
int main(){
    int N, E,i,j,X,Y,H,K,O,D,n,M;
    Grafo* G[500];
    inicializa(G);
    Aresta* A[250000];
    inicializa_arestas(A);
    while(scanf("%d %d",&N,&E)){
        if(N==0 && E==0) break;
        n = 0;
        while(E>n){
            scanf("%d %d %d",&X, &Y, &H);
            acordo(G[X-1],G[Y-1],H,A[n++]);
        }
        scanf("%d",&K);
        K++;
        while(0<K--){
            scanf("%d %d",&O,&D);
            M = 0;
            if(caminho(G[O-1],G[D-1],M,0)<0){
                printf("Nao e possivel entregar a carta\n");
            }
            else printf("%d\n",M);
            reinicializa(G,N);
        }
        printf("%d\n",M);
    }
    return 0;
}

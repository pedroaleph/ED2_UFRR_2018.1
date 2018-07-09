#include <stdio.h>
typedef struct Coordenadas{
    int x , y , v;
} coordenadas;
int loop;
void visitando(coordenadas c[],int a,int b,int n){
   int i,j;
    for(i=0;i<n;i++){
        if(c[i].x==a && c[i].y==b) break;
    }
   if(c[i].v==0){
        c[i].v = 1;
        for(j=0;j<n;j++){
            if(c[j].x==b && c[j].v==0){
                visitando(c,b,c[j].y,n);
            }
        }
    }else loop = 1;
}
void servico(int M){
    int A,B,i,j;
    coordenadas c[M];
        loop = 0;
        for(i=0;i<M;i++){
            scanf("%d %d",&A,&B);
            c[i].x = A-1;
            c[i].y = B-1;
            c[i].v = 0;
        }
        for(i=0;i<M-1;i++){
            for(j=i+1;j<M;j++){
                if(c[i].x==c[j].x && c[i].y==c[j].y)
                    c[j].x = -1;
            }
        }
        for(i=0;i<M;i++){
            if(c[i].x!=-1 && c[i].v==0) visitando(c,c[i].x,c[i].y,M);
            if(loop==1) break;
        }
        if(loop==1) printf("SIM\n");
        else printf("NAO\n");
}
int main(){
    int T,N,M;
    scanf("%d",&T);
    while(0<T--){
        scanf("%d %d",&N,&M);
        servico(M);
    }
    return 0;
}

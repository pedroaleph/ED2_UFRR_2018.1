#include <stdio.h>
typedef struct Matriz{
    int x;
    int v;
} matriz;
int w;
void perseguindo(matriz M[][5],int i, int j){
    if(i<5 && j<5 && w!=1){
        M[i][j].v = 1;
        if(i==4 && j==4) w = 1;
        else {
            if(j>0 && M[i][j-1].x!=1 && M[i][j].v == 0){
            perseguindo(M,i,j-1);
            }
            if (i<4 && M[i+1][j].x!=1 && M[i][j].v == 0){
            perseguindo(M,i+1,j);
            }
            if (j<4 && M[i][j+1].x!=1 && M[i][j].v == 0){;
            perseguindo(M,i,j+1);
            }
            if (i>0 && M[i-1][j].x!=1 && M[i][j].v == 0){
            perseguindo(M,i-1,j);
            }
        }
    }
}
int main(){
    int T,i,j;
    matriz M[5][5];
    scanf("%d",&T);
    while(0<T--){
        printf("\n");
        for(i=0;i<5;i++){
            for(j = 0;j<5;j++){
                scanf("%d",&M[i][j].x);
                M[i][j].v = 0;
            }
        }
        w = 0;
        perseguindo(M,0,0);
        if(w == 1) printf("COPS\n");
        else printf("ROBBERS\n");
    }
    return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5

typedef int Graph[SIZE][SIZE];
void initGraph(Graph G){
    int x, y;
    for(x=0; x<SIZE; x++){
        for(y=0; y<SIZE; y++){
            G[x][y] = 0;
        }
    }
}
void populateGraph(Graph G){
    G[0][0] = 1;
    G[0][1] = 1;
    G[0][2] = 1;
    G[0][3] = 1;
    G[0][4] = 1;
    G[1][1] = 1;
    G[1][2] = 1;
    G[1][3] = 1;
    G[1][4] = 1;
    G[2][2] = 1;
    G[2][1] = 1;
    G[2][3] = 1;
    G[2][4] = 1;
    G[3][1] = 1;
    G[3][2] = 1;
    G[3][3] = 1;
    G[3][4] = 1;
    G[4][1] = 1;
    G[4][2] = 1;
    G[4][3] = 1;
    G[4][4] = 1;
}
void Warshall(Graph A, Graph G){
    int x, y, z;
    memcpy(A, G, SIZE*SIZE*sizeof(int));

    for(z=0; z<SIZE; z++){
        for(x=0; x<SIZE; x++){
            for(y=0; y<SIZE; y++){
                if(A[x][y]==0){
                    A[x][y] = A[x][z] && A[z][y];
                }
            }
        }
    }
}
void displayGraph(Graph G){
    int x, y;
    for(x=0; x<SIZE; x++){
        for(y=0; y<SIZE; y++){
            printf("%d ", G[x][y]);
        }
        printf("\n");
    }
}
void main(){
    Graph G;
    initGraph(G);
    populateGraph(G);
    displayGraph(G);
    Graph A;
    initGraph(A);
    Warshall(A, G);
    printf("\n");
    displayGraph(A);
}
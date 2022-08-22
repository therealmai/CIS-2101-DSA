#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 999
#define SIZE 6

typedef int Graph[SIZE][SIZE]; //Adjacency Matrix
struct{
    int vertex[SIZE];
    int count;
}V;
void initGraph(Graph G){
    int x, y;
    for(x=0; x<SIZE; x++){
        for(y=0; y<SIZE; y++){
            G[x][y] = MAX;
        }
    }
}
void initV(){
    int x;
    V.count = 0;
    for(x=0; x<SIZE; x++){
        V.vertex[x] = -1;
    }
}
void populateGraph(Graph G){
    G[0][1] = G[1][0] = 1;
    G[0][2] = G[2][0] = 5;
    G[0][3] = G[3][0] = 4;
    G[0][4] = G[4][0] = 6;
    G[0][5] = G[5][0] = 5;
    G[1][2] = G[2][1] = 5;
    G[1][5] = G[5][1] = 6;
    G[3][2] = G[3][2] = 2;
    G[3][4] = G[4][3] = 1;
    G[4][5] = G[5][4] = 3;
}
void displayGraph(Graph G){
    int x, y;
    for(x=0; x<SIZE; x++){
        for(y=0; y<SIZE; y++){
            printf("%3d ", G[x][y]);
        }
        printf("\n");
    }
}
int kruskal(Graph G){
    int mst = 0, x, y, parx, pary, min;
    Graph A;
    memcpy(A, G, SIZE*SIZE*sizeof(int));
    parx = pary = 0;
    while(V.count<SIZE-1){ //repeat until edge is vertex-1
        min = MAX;
        for(x=0; x<SIZE; x++){ //find the minimum edge
            for(y=0; y<SIZE; y++){
                if(min > A[x][y]){
                    min = A[x][y];
                    parx = x;
                    pary = y;
                }
            }
        }

        if(V.vertex[pary]==-1){ //unvisited vertex
            if(V.vertex[parx]==-1){
                V.vertex[pary] = parx;
                mst += min; //add min to mst
                A[parx][pary] = A[pary][parx] = MAX; //set visited minimum edge to infinty so it wont be visited again
                V.count++; //add edge
            } else{
                if(V.vertex[parx]!=V.vertex[pary]){ //if not a cycle
                    V.vertex[pary] = (V.vertex[parx] != -1)? V.vertex[parx] : parx; //set the original parent of the visited vertex
                    mst += min; //add min to mst
                    A[parx][pary] = A[pary][parx] = MAX; //set visited minimum edge to infinty so it wont be visited again
                    V.count++; //add edge
                }
            }
        }
    }
    return mst;
}
void main(){
    Graph G;
    initGraph(G);
    initV();
    //displayGraph(G);
    populateGraph(G);
    //displayGraph(G);
    printf("%d ", kruskal(G));
}
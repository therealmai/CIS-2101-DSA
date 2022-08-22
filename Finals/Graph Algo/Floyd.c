#include<stdio.h>
#include<string.h>
#define SIZE 5
#define MAX 9999

typedef int Graph[SIZE][SIZE]; //Adjacency Matrix
typedef int Vertex[SIZE]; //Bit-Vector
void initGraph(Graph G){ //Set all edges to infinity
  int x, y;
  for(x=0; x<SIZE; x++){
    for(y=0; y<SIZE; y++){
      G[x][y] = MAX;
    }
  }
}
void populateGraph(Graph G){
  G[0][1] = 10;
  G[0][3] = 30;
  G[0][4] = 100;
  G[1][2] = 50;
  G[2][0] = 20;
  G[2][4] = 10;
  G[3][2] = 20;
  G[3][4] = 60;
}
void Floyd(Graph A, Graph G){
  int x, y, z;
  memcpy(A, G, SIZE*SIZE*sizeof(int));
  for(x=0; x<SIZE; x++){
    A[x][x] = 0;
  }
  for(z=0; z<SIZE; z++){
    for(x=0; x<SIZE; x++){
      for(y=0; y<SIZE; y++){
        if(A[x][z] + A[z][y] < A[x][y]){
          A[x][y] = A[x][z] + A[z][y];
        }
      }
    }
  }
}
int findCenter(Graph A){
  int max, x, y;
  int ecc[SIZE];
  for(y=0; y<SIZE; y++){
    max = A[0][y];
    for(x=1; x<SIZE; x++){
      max = (max>A[x][y])? max : A[x][y];
    }
    ecc[y] = max;
  }
  max = 0;
  for(x=1; x<SIZE; x++){
    max = (ecc[max]<ecc[x])? max : x;
  }
  return max;
}
void display(Graph A){
    int x, y;
    for(x=0; x<SIZE; x++){
        for(y=0; y<SIZE; y++){
            printf("%d ", A[x][y]);
        }
        printf("\n");
    }
}
void main(){
  Graph G;
  Graph A;
  initGraph(G);
  populateGraph(G);
  Floyd(A, G);
  display(A);
  printf("\n%d", findCenter(A));
}
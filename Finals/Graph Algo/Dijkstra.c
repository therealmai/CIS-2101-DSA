#include<stdio.h>
#include<stdlib.h>
#define size 5
#define infinity 999

typedef int Graph[size][size]; //Adjancency Matrix
typedef int Vertex[size]; //Bit Vector, can be computer word


void initGraph(Graph G){    //Set all index to infinity
    int x,y;
    for(x=0; x<size; x++){
        for(y=0; y<size; y++){
            G[x][y] = infinity;
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

Vertex *difference(Vertex V, Vertex S){
    Vertex* ret = (Vertex*)calloc(sizeof(Vertex),1);  //Allocate Space
    int x;
    for(x=0; x<size; x++){
        (*ret)[x] = V[x] & ~(S[x]);   //Formula for getting Difference
    }
    return ret;
}

int minimum (Vertex *D, Vertex *V){
    int x, y ,min;
    for(x=0; x<size; x++){
      if((*V)[x]==1){
        for(y=x+1; y<size; y++){
          if((*V)[y] == 1){
            min = ( (*D)[x] < (*D)[y] )? x : y;  //Bubble sort getting the minimum; traverse the array
          }  
        }
      }
    }
    return min;
}

Vertex* dijkstra(Graph G, Vertex V){
    Vertex *D = (Vertex*) calloc(sizeof(Vertex),1); //Contains the smallest paths
    Vertex S = {1,0,0,0,0}; // Set of visited vertices
    Vertex *A = NULL;
    
    int x, w,v;
    for(x=1;x<size; x++){
        (*D)[x] = G[0][x];
    }
    for(x=1; x<size-1; x++){
        A= difference(V, S);   //Difference
        w = minimum (D,A);   //Getting the lowest value vertex
        S[w]= 1;
        (*A)[w] = 0;
        for(v=1; v<size; v++){
          if((*A)[v]==1){
            (*D)[v] = ( (*D)[v] < ((*D)[w]+G[w][v]) ) ? (*D)[v] : ((*D)[w]+G[w][v]);   //Pick the smallest number and change it if necessary
          }  
        }
    }
    return D;
}
void display(Vertex *D){
	int x;
	for(x=0; x<size; x++){
		printf("%d ", (*D)[x]);
	}
}
void main(){
    Graph G;
    Vertex V = {1,1,1,1,1};
    initGraph(G);
    populateGraph(G);
    Vertex *D = dijkstra(G, V);
    display(D);
}

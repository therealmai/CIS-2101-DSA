#include<stdio.h>
#include<stdlib.h>
#define SIZE 7
#define UNVISITED -2
#define VISITED -1

typedef struct node{
    int elem;
    struct node *next;
}*Node;
typedef int vertex;
struct{
    int vertex[SIZE];
    int count;
}mark;
typedef Node Graph[SIZE]; //adjacency list
typedef struct{
    int vertex[SIZE]; //queue to be used for traversal
    int front, rear;
}Queue;
void initGraph(Graph L){
    int x;
    for(x=0; x<SIZE; x++){
        L[x] = NULL;
    }
}
void initMark(){
    int x;
    mark.count = 0;
    for(x=0; x<SIZE; x++){
        mark.vertex[x] = UNVISITED;
    }
}
void initQueue(Queue *Q){
    Q->front = 0;
    Q->rear = -1;
}
void insertVertex(int parent, int child, Graph L){
    Node *ptr;
    for(ptr=&L[parent]; *ptr!=NULL; ptr=&(*ptr)->next){}
    if(*ptr==NULL){
        *ptr = (Node)calloc(1, sizeof(struct node));
        (*ptr)->elem = child;
    }
}
void enqueue(Queue *Q, int elem){   //enqueue
    Q->rear = (Q->rear+1)%SIZE;
    Q->vertex[Q->rear] = elem;
}
vertex dequeue(Queue *Q){      //dequeue and front
    int x = Q->vertex[Q->front];
    Q->front = (Q->front+1)%SIZE;
    return x;
}
void populateGraph(Graph L){
  insertVertex(0, 1, L);
  insertVertex(0, 2, L);
  insertVertex(1, 2, L);
  insertVertex(1, 3, L);
  insertVertex(2, 0, L);
  insertVertex(3, 0, L);
  insertVertex(3, 2, L);
  insertVertex(4, 5, L);
  insertVertex(4, 6, L);
  insertVertex(5, 1, L);
  insertVertex(6, 3, L);
  insertVertex(6, 5, L);
}
void BFS(Graph L, vertex v){
    Queue Q;
    initQueue(&Q);
    Node ptr;
    vertex x, y;
    mark.vertex[v] = VISITED;
    mark.count++;
    enqueue(&Q, v);
    while(Q.front!=(Q.rear+1)%SIZE){
        x = dequeue(&Q);
        printf("%d ", x);
        for(ptr=L[x]; ptr!=NULL; ptr=ptr->next){
            y = ptr->elem;
            if(mark.vertex[y] == UNVISITED){
                mark.vertex[y] = VISITED;
                mark.count++;
                enqueue(&Q, y);
            }
        }
    }
}
void displayGraph(Graph L){
    int x;
    Node ptr;
    for(x=0; x<SIZE; x++){
        printf("%d -> ", x);
        for(ptr=L[x]; ptr!=NULL; ptr = ptr->next){
            printf("%d -> ", ptr->elem);
        }
        printf("NULL\n");
    }
}
 void main(){
     Graph L;
     initGraph(L);
     initMark();
     populateGraph(L);
     displayGraph(L);
     BFS(L, 4);
     int x;
     if(mark.count<SIZE){
         for(x=0; mark.vertex[x]!=UNVISITED; x++){}
         BFS(L, x);
     }
 }
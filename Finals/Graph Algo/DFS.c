#include<stdio.h>
#include<stdlib.h>
#define SIZE 7
#define UNVISITED -2
#define VISITED -1
typedef struct node{
  int elem;
  struct node* next;
}*node;
typedef node Graph[SIZE];
typedef int vertex;
struct{
  vertex vertices[SIZE];
  int count;
}mark, diffnum;
void initMark(){                   /*initialize mark array*/
  int x;
  mark.count = -1;
  for(x=0; x<SIZE; x++){
    mark.vertices[x] = UNVISITED;
  }
}
void initDiffnum(){
  int x;
  diffnum.count = 1;
  for(x=0; x<SIZE; x++){
    diffnum.vertices[x] = UNVISITED;
  }
}
void initGraph(Graph L){
  int x;
  for(x=0; x<SIZE; x++){
    L[x] = NULL;
  }
}
void insertVertex(vertex ancestor, vertex descendant, Graph L){
  node *ptr;
  for(ptr=&L[ancestor]; *ptr!=NULL && (*ptr)->elem!=descendant; ptr=&(*ptr)->next){}
  if(*ptr==NULL){
    *ptr = (node)calloc(1, sizeof(struct node));
    (*ptr)->elem = descendant;
  }
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
void displayGraph(Graph L){
  int x;
  node ptr;
  for(x=0; x<SIZE; x++){
    printf("%d -> ", x);
    for(ptr=L[x]; ptr!=NULL; ptr=ptr->next){
      printf("%d -> ", ptr->elem);
    }
    printf("NULL\n");
  }
}
void dfs(vertex v, Graph L){
  vertex w;
  node ptr;
  mark.vertices[v] = VISITED;
  mark.count++;
  printf("%d ", v);
  for(ptr=L[v]; ptr!=NULL; ptr=ptr->next){
    w = ptr->elem;
    if(mark.vertices[w] == UNVISITED){
      dfs(w, L);
    }
  }
}
void dfn(vertex v, Graph L){
  vertex w;
  node ptr;
  diffnum.vertices[v] = diffnum.count++;
  for(ptr=L[v]; ptr!=NULL; ptr=ptr->next){
    w = ptr->elem;
    if(diffnum.vertices[w] == UNVISITED){
      dfn(w, L);
    }
  }
}
void displayDFN(){
  int x;
  printf("\nDiffNum:\n");
  for(x=0; x<SIZE; x++){
    printf("%d %d\n", x, diffnum.vertices[x]);
  }
}
void main(){
  Graph L;
  initDiffnum();
  initMark();
  initGraph(L);
  populateGraph(L);
  displayGraph(L);
  dfs(4, L);
  if(mark.count<SIZE-1){
    dfs(++mark.count, L);
  }
  dfn(4, L);
  displayDFN();
}
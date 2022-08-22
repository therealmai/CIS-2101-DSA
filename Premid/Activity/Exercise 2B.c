#include<stdio.h>
#include<stdlib.h>
//#define NULL 0
#define SIZE 6
typedef struct{
  int data;
  int link;
}Nodetype;

typedef struct VHnode {
  Nodetype heap[SIZE];
  int availList;      
}*VHeap;           /* Shared by all cursorList */

typedef struct {
  int elemPtr;    /* Points to the first element of the list */
  VHeap VH;       /* Points to the shared Virtual Heap */
}cursorList; 

void initVirtualHeap(VHeap *V);
void displayVirtualHeap(VHeap V);
void initCursorList(cursorList *L);
void displayList(cursorList L);
void insertLast(VHeap *V, cursorList *L, int elem);
void populateList(VHeap *V,cursorList *L,  int arr[]);
cursorList getEven(cursorList *L);
int main() {
  VHeap V;
  cursorList L,catcher;
  int arr[SIZE] = {4,10,3,6,7,1};
  printf("TASK 1\n");
  initVirtualHeap(&V);
  displayVirtualHeap(V);
  printf("TASK 2\n");
  initCursorList(&L);
  displayList(L);
  printf("TASK 3\n");
  populateList(&V, &L,arr);
  displayList(L);
  printf("TASK 4\n");
  catcher = getEven(&L);
  printf("Removed Even List: ");
  displayList(L);
  printf("New Even List: ");
  displayList(catcher);
  return 0;
}

void initVirtualHeap(VHeap *V){
  int x;
  *V = (VHeap)calloc(1,sizeof(struct VHnode));
  (*V)->availList = 0;
  for(x=0; x<SIZE; x++){
    (*V)->heap[x].link = x+1;  
  }
  (*V)->heap[x-1].link = -1;
}

void displayVirtualHeap(VHeap V){
  int x;
  for(x=V->availList; x!= -1; x = V->heap[x].link){
      printf("Index: %d, Data: %d, Link: %d \n",x,V->heap[x].data, V->heap[x].link);
    }
  printf("\n");
}

void initCursorList(cursorList *L){
  L->elemPtr = -1;
  L->VH = NULL;
}

void insertLast(VHeap *V, cursorList *L, int elem){
  int *trav,x;
  for(trav = &L->elemPtr; *trav != -1; trav = &L->VH->heap[*trav].link){}
  x = (*V)->availList;
  if(x != -1){
    (*V)->availList = (*V)->heap[x].link;
    (*V)->heap[x].data = elem;
    (*V)->heap[x].link = *trav;
    *trav = x;
  }
}

void displayList(cursorList L){
  int x;
  if(L.elemPtr!=-1){
    for(x = L.elemPtr; x!=-1; x = L.VH->heap[x].link){
      printf("%d ", L.VH->heap[x].data);
    }
  } else {
    printf("List is empty");
  }
  printf("\n");
}
void populateList(VHeap *V,cursorList *L,  int arr[]){
  int x;
  if(L->elemPtr == -1){
    L->VH = *V;
  }
  for(x=0; x<SIZE; x++){
    insertLast(V,L,arr[x]);  
  }
}

cursorList getEven(cursorList *L){
  cursorList Even = {-1,L->VH} ;
  int *trav, *ptr, temp;
  
  ptr = &Even.elemPtr;
  for(trav = &L->elemPtr; *trav != -1;){
    if(L->VH->heap[*trav].data % 2 == 0){
      temp = *trav;
      *trav = L->VH->heap[temp].link;
      *ptr = temp;
      ptr = &L->VH->heap[*ptr].link;
      }else{
        trav = &L->VH->heap[*trav].link;  
      }
    }
    *ptr = -1;
    return Even;
}

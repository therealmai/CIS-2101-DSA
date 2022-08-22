#include<stdio.h>
#define SIZE 10
typedef struct{
  int Elem[SIZE];
  int ndx;
}Heap;
void initHeap(Heap *A){
  A->ndx = -1;
}
void insertPOT(Heap *A){
  int arr[] = {7, 1, 4, 5, 6, 2};
  int x;
  for(x=0; x<sizeof(arr)/sizeof(int); x++){
    A->Elem[++A->ndx] = arr[x];
  }
}
void minSubHeapify(Heap *A, int par){
  int SC=-1, LC, RC, temp;
  if(par<A->ndx){
    LC = par*2+1;
    RC = par*2+2;
    if(RC<=A->ndx && LC<=A->ndx){
      SC = (A->Elem[LC]< A->Elem[RC])? LC : RC;
    }else if(LC<=A->ndx){
      SC = LC;
    }
    if(SC!=-1 && A->Elem[par]>A->Elem[SC]){
      temp = A->Elem[par];
      A->Elem[par] = A->Elem[SC];
      A->Elem[SC] = temp;
      minSubHeapify(A, par*2+1);
      minSubHeapify(A, par*2+2);
    }
  }
}
int deleteMin(Heap *A){
  int par = 0, min;
  min = A->Elem[par];
  A->Elem[par] = A->Elem[A->ndx--];
  for(;par<=(A->ndx-1)/2;par++){
    minSubHeapify(A, par);
  }
  return min;
}
void minHeapify(Heap *A){
  int par;
  for(par=(A->ndx-1)/2; par>=0; par--){
    minSubHeapify(A, par);
  }
}
void minHeapSort(Heap *A){
  int min;
  while(A->ndx>-1){
    min = deleteMin(A);
    A->Elem[A->ndx+1] = min;
  }
}
void main(){
  Heap A;
  initHeap(&A);
  insertPOT(&A);
  minHeapify(&A);
  minHeapSort(&A);
}

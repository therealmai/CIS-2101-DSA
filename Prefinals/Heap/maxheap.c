#include<stdio.h>
#define SIZE 10
typedef struct{
  int Elem[SIZE];
  int ndx;
}Heap;
void initHeap(Heap *H){
  H->ndx = -1;
}
void insertPOT(Heap *H){
  int arr[] = {1, 8, 3, 6, 5, 2};
  int x;
  for(x=0; x<sizeof(arr)/sizeof(int); x++){
    H->Elem[++H->ndx] = arr[x];
  }
}
void maxSubHeapify(Heap *H, int par){
  int BC = -1, LC, RC, temp;
  if(par<H->ndx){
    LC = par*2+1;
    RC = par*2+2;
    if(RC<=H->ndx && LC<=H->ndx){
      BC = (H->Elem[LC] > H->Elem[RC])? LC : RC;
    } else if (LC<=H->ndx){
      BC = LC;
    }
    if(BC!=-1 && H->Elem[par]<H->Elem[BC]){
      temp = H->Elem[par];
      H->Elem[par] = H->Elem[BC];
      H->Elem[BC] = temp;
      maxSubHeapify(H, par*2+1);
      maxSubHeapify(H, par*2+2);
    }
  }
}
void maxHeapify(Heap *H){
  int par;
  for(par=(H->ndx-1)/2; par>=0; par--){
    maxSubHeapify(H, par);
  }
}
int deleteMax(Heap *H){
  int max, par = 0;
  max = H->Elem[par];
  H->Elem[par] = H->Elem[H->ndx--];
  for(;par<=(H->ndx-1)/2; par++){
    maxSubHeapify(H, par);
  }
  return max;
}
void maxHeapSort(Heap *H){
  int max, index = H->ndx;
  while(H->ndx>-1){
    max = deleteMax(H);
    H->Elem[H->ndx+1] = max;
  }
}
void main(){
  Heap A;
  initHeap(&A);
  insertPOT(&A);
  maxHeapify(&A);
  maxHeapSort(&A);
}
#include<stdio.h>
#define Max 10
typedef struct{
    char data;
    int next;
}Nodetype;

typedef struct{
    Nodetype Nodes[Max];
    int Avail;
}VHeap;



void initVirtualHeap(VHeap *VH);
void initialize(int *S);
int allocSpace(VHeap *VH);
void deallocSpace(VHeap *VH, int cell);
char top(VHeap VH, int S);
void pop(VHeap *VH, int *S);
void push(VHeap *VH, int *S, char ch);
int isEmpty(int S);
void insertLast(VHeap *VH, int *S, char elem);
void display(VHeap *VH, int *S);

void main(){
    VHeap VH;
    initVirtualHeap(&VH);
    int A;
    initialize(&A);
    push(&VH, &A, 'A');
    push(&VH, &A, 'B');
    push(&VH,&A,'C');
    display(&VH, &A);
    pop(&VH, &A);
    insertLast(&VH, &A, 'D');
    display(&VH, &A);
    
}

void initVirtualHeap(VHeap *VH){
 int x; 
 VH->Avail = 0;
 for(x =0; x< Max ; x++){
  VH->Nodes[x].next = x+1; 
  }
 VH->Nodes[Max-1].next = -1;
}

void initialize(int *S){
  *S = -1;  
}

int allocSpace(VHeap *VH){
 int x;
 x = VH->Avail;
 if(x != -1){
  VH->Avail = VH->Nodes[x].next;
  VH->Nodes[x].next = -1;
  }
  return x;
}

void deallocSpace(VHeap *VH, int cell){
   if (cell >= 0 && cell < Max){
  VH->Nodes[cell].next = VH->Avail;
  VH->Avail = cell;
   }
}

char top(VHeap VH, int S){
 return VH.Nodes[S].data;  
}

void pop(VHeap *VH, int *S){
  if(*S != -1){
  int temp;
  temp = *S;
  *S = VH->Nodes[temp].next;
  deallocSpace(VH, temp);
  }  
}

void push(VHeap *VH, int *S, char ch){
  int temp; //int
  temp = allocSpace(VH);
  if(temp != -1){
  VH->Nodes[temp].data = ch;
  VH->Nodes[temp].next = *S;
  *S = temp;
  }
}

int isEmpty(int S){
  return (S == -1) ? 1: 0;
}

void insertLast(VHeap *VH, int *S, char elem){
 int temp;
 char ch;
 initialize(&temp);
 while(isEmpty(*S) == 0){
  ch = top(*VH, *S);
  pop(VH, S);
  push(VH,&temp, ch);
  }
 push(VH, S, elem);
 while(isEmpty(temp) == 0){
   ch = top(*VH, temp);
   pop(VH, &temp);
   push(VH,S, ch);
   }
}

void display(VHeap *VH, int *S){
int temp;
char ch;
initialize(&temp);
while(isEmpty(*S) == 0){
  ch = top(*VH, *S);
  printf("%c", ch);
  pop(VH, S);
  push(VH, &temp, ch);
}

while(isEmpty(temp) == 0){
  ch = top(*VH, temp);
  pop(VH, &temp);
  push(VH, S, ch);
  }
 printf("\n");
}

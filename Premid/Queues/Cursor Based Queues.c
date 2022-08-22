#define max 4
#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
  char elem;
  int next;
}node;

typedef struct{
  node nodes[max];  
  int Avail;
}VHeap;

typedef struct{
  int front;
  int rear;
  VHeap *vptr;
}Queue;

void initializeCursor(VHeap *VH);
void initQueue(Queue *Q,VHeap *VH);
int isFull(Queue Q);
int isEmpty(Queue Q);
void enqueue(Queue *Q, char ch);
void dequeue (Queue *Q);
char front(Queue Q);
void display(Queue* Q,VHeap *VH);

void main(){
VHeap VH;
Queue Q;
initializeCursor(&VH);
initQueue(&Q, &VH);
enqueue(&Q, 'A');
enqueue(&Q, 'B');
enqueue(&Q, 'C');
enqueue(&Q, 'D');
dequeue(&Q);
display(&Q, &VH);
  
}

void initializeCursor(VHeap *VH){
int x;
VH->Avail = 0;
for(x=0; x<max; x++){
  VH->nodes[x].next = x+1;
}
  VH->nodes[x].next = -1;
}
void initQueue(Queue *Q,VHeap *VH){
 Q->front = -1;
 Q->rear = -1;
 Q->vptr = VH;
}

int isFull(Queue Q){
  return (Q.vptr->Avail == -1) ? 1 : 0;
}

int isEmpty(Queue Q){
  return (Q.front == -1) ? 1 : 0;
}

void enqueue(Queue *Q, char ch){
  int temp;
  temp = Q->vptr->Avail;
  if(temp != -1){
    Q->vptr->Avail = Q->vptr->nodes[Q->vptr->Avail].next;
    Q->vptr->nodes[temp].elem = ch;
    Q->vptr->nodes[temp].next = -1;
    
    if(Q->front == -1){
      Q->front = Q->rear = temp;  
    }else{
      Q->rear = Q->vptr->nodes[Q->rear].next = temp;  
    }
  }
}

void dequeue (Queue *Q){
  int temp;
  temp = Q->vptr->nodes[Q->front].next;
  if(Q->front != -1){
  Q->vptr->nodes[Q->front].next = Q->vptr->Avail;
  Q->vptr->Avail = Q->front;
  Q->front = temp;
  if(Q->front == -1){
    Q->rear = -1;
    }
  }
}

char front(Queue Q){
  if(isEmpty(Q) == 0){
    return Q.vptr->nodes[Q.front].elem;  
  }  
}
void display(Queue* Q, VHeap *VH){
  Queue temp;
  char ch;
  
  initQueue(&temp, VH);
  while(isEmpty(*Q) == 0){
   ch = front(*Q);
   printf("%c", ch);
   dequeue(Q);
   enqueue(&temp,ch);
  }
  
  while(isEmpty(temp) == 0){
   ch = front(temp);
   dequeue(&temp);
   enqueue(Q,ch);
  }
}

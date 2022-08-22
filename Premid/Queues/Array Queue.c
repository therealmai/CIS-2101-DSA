#define max 4
#include<stdio.h>

typedef struct{
  char elem[max];
  int front;
  int rear;
}Queue;

void initQueue(Queue *Q);
int isFull(Queue Q);
int isEmpty(Queue Q);
void enqueue(Queue *Q, char ch);
void dequeue(Queue *Q);
char front(Queue Q);
void displayQueue(Queue *Q);

void main(){
  Queue Q;
  initQueue(&Q);
  enqueue(&Q, 'A');
  enqueue(&Q, 'B');
  enqueue(&Q, 'C');
  displayQueue(&Q);
  dequeue(&Q);
  dequeue(&Q);
  dequeue(&Q);
  enqueue(&Q, 'D');
  printf("\n");
  displayQueue(&Q);  
}

void initQueue(Queue *Q){
  Q->front = 1;
  Q->rear = 0;
}

int isFull(Queue Q){
   return (Q.front == (Q.rear+2) % max) ? 1 : 0;  
}

int isEmpty(Queue Q){
  return (Q.front == (Q.rear+1) % max) ? 1 : 0;  
}

void enqueue(Queue *Q, char ch){
  if(isFull(*Q) == 0){
  Q->rear = (Q->rear+1) % max;
  Q->elem[Q->rear] = ch;
  }
}

void dequeue(Queue *Q){
  if(isEmpty(*Q) == 0){
    Q->front = (Q->front+1) % max;
    }  
}

char front(Queue Q){
  return Q.elem[Q.front];  
}

void displayQueue(Queue *Q){
  Queue temp;
  char ch;
  
  initQueue(&temp);
  
  while(isEmpty(*Q) == 0){
  ch = front(*Q);
  printf("%c", ch);
  dequeue(Q);
  enqueue(&temp, ch);
  }
  
  while(isEmpty(temp) == 0){
  ch = front(temp);
  dequeue(&temp);
  enqueue(Q, ch);
  }
}

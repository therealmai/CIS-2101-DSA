#define max 4
#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
    char elem;
    struct cell* next;
}*node;

typedef struct{
    node front;
    node rear;
}Queue;

void initQueue(Queue *Q);
int isEmpty(Queue Q);
void enqueue(Queue *Q, char elem);
void dequeue(Queue *Q);
char front(Queue Q);
void display(Queue* Q);


void main(){
  Queue Q;
  initQueue(&Q);
  enqueue(&Q, 'A');
  enqueue(&Q, 'B');
  enqueue(&Q, 'C');
  enqueue(&Q, 'D');
  display(&Q);
  dequeue(&Q);
  dequeue(&Q);
  display(&Q);
}


void initQueue(Queue *Q){
  Q->front = NULL;
  Q->rear = NULL;
}

int isEmpty(Queue Q){
  return (Q.front == NULL) ? 1 : 0;  
}

void enqueue(Queue *Q, char elem){
  node temp;
  temp = (node)malloc(sizeof(struct cell));
  if(temp != NULL){
    temp->elem = elem;
    temp->next = NULL;
    if(isEmpty(*Q) == 1){
      Q->front = Q->rear = temp; 
      }else{
      Q->rear = Q->rear->next = temp;  
      }
    }
}

void dequeue(Queue *Q){
node temp;

if(isEmpty(*Q) == 0){
  temp = Q->front;
  Q->front = temp->next;
  free(temp);
  
  if(isEmpty(*Q) == 1){
    Q->rear = NULL;
    }
  }
  
}

char front(Queue Q){
  if(isEmpty(Q) == 0){
    return Q.front->elem;
    }
}

void display(Queue* Q){
Queue temp;
char ch;
initQueue(&temp);

while(isEmpty(*Q) == 0){
  ch = front(*Q);
  printf("%c", ch);
  dequeue(Q);
  enqueue(&temp,ch);
  }
printf("\n");
while(isEmpty(temp) == 0){
  ch = front(temp);
  dequeue(&temp);
  enqueue(Q, ch);
  }

}



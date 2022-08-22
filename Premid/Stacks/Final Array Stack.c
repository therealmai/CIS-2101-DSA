#include<stdio.h>
#define max 10

typedef struct{
    char elem[max];
    int top;
}Stack;

void initialize(Stack *S);
void push(Stack *S, char elem);
void pop(Stack *S);
int isEmpty(Stack S);
char top(Stack S);
void insertBottom(Stack* S, char elem);
void display(Stack *S);

void main(){
  Stack S;
  initialize(&S);
  push(&S, 'A');
  push(&S, 'B');
  push(&S, 'C');
  display(&S);
  printf("\n");
  pop(&S);
  insertBottom(&S, 'D');
  display(&S);
}

void initialize(Stack *S){
 S->top = -1;  
}

void push(Stack *S, char elem){
  S->top++;
  S->elem[S->top] = elem;
}

void pop(Stack *S){
    S->top--;  
}

int isEmpty(Stack S){
  return (S.top > -1) ? 0: 1;
}

char top(Stack S){
    return S.elem[S.top];
}
void insertBottom(Stack* S, char elem){
Stack temp;
char ch;
initialize(&temp);
while(isEmpty(*S) == 0){
  ch = top(*S);
  pop(S);
  push(&temp, ch);
  }
push(S, elem);

while(isEmpty(temp) == 0){
   ch = top(temp);
   pop(&temp);
   push(S, ch);
  }  
}


void display(Stack *S){
  Stack temp;
  char ch;
initialize(&temp);
while(isEmpty(*S) == 0){
  ch = top(*S);
  printf("%c", ch);
  pop(S);
  push(&temp, ch);
  }
while(isEmpty(temp) == 0){
   ch = top(temp);
   pop(&temp);
   push(S, ch);
  }    
}

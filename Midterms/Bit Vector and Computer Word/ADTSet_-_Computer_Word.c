#include <stdio.h>
#include <stdlib.h>

typedef unsigned int SET;

void initSET(SET *A);
void insert(SET *A, int n);
void deleteMem(SET *A, int n);
void populateA(SET *A);
void populateB(SET *B);
void display(SET V);

//set operations
int isMember(SET A, int n);
SET unionSet(SET A, SET B);
SET intersection(SET A, SET B);
SET difference(SET A, SET B);
int isSubset(SET A, SET B);

int main() {
	SET A,B;
	initSET(&A);
	initSET(&B);
	populateA(&A);
	populateB(&B);	
		
	display(A);
	display(B);

	printf("\n");	
	
	SET U = unionSet(A,B);
	SET I = intersection(A,B);
	SET D = difference(A,B);
	
	display(U);
	display(I);
	display(D);
	
	printf("\n");
	printf("%d ",isMember(A,9));  // 1
	printf("%d ",isSubset(A,B));  // 0
	deleteMem(&A,9);
	printf("%d ",isMember(A,9));  // 0
	printf("%d ",isSubset(A,B));  // 1
	
	return 0;
}

void populateA(SET *A){
	int num[] = {5, 7, 9},x;
	for(x=0;x<3;x++){
		insert(A,num[x]);
	}
}

void populateB(SET *B){
	int num[] = {3, 5, 7, 11, 13, 15},x;
	for(x=0;x<6;x++){
		insert(B,num[x]);
	} 
}

void initSET(SET *A){
	*A = 0;
}

void insert(SET *A, int n){
	if(n>=0 && n<sizeof(SET)*8)
	*A |= 1 << n;
}

void deleteMem(SET *A, int n){
	unsigned int mask = 1;
	if(n>=0 && n<sizeof(SET)*8)
	*A &= ~(mask << n);
}

void display(SET A){
	int x, size;
	unsigned int mask = 1;
	size = sizeof(SET)*8;
	for(x=0; x<size; x++){
		if((A & mask)>0)
		printf("%d ",x);	
		mask <<= 1;
	}
	printf("\n");
}

int isMember(SET A, int n){
	unsigned int mask = 1;
	return ((A & mask << n) > 0) ? 1 : 0; 
}

SET unionSet(SET A, SET B){
	return A | B;
	
}

SET intersection(SET A, SET B){
	return A & B;
}

SET difference(SET A, SET B){ //A – B
	return A & ~B;
}

int isSubset(SET A, SET B){
	return ((A & B) == A) ? 1 : 0;
}

